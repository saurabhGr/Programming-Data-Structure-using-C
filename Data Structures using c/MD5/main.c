#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
// union is a struct ....we simply write whole union struct by....MDunion
typedef union buw {
    unsigned w;
    unsigned char b[4];
} MDunion;
// defining hexadecimal to digest consists of 4 hexadecimal values
typedef unsigned Digest[4];
//F(x,y,z)
unsigned fun0( unsigned pqrs[] )
   {
    return ( pqrs[1] & pqrs[2]) | (~pqrs[1] & pqrs[3]);
    }
//G(x,y,z)
unsigned fun1( unsigned pqrs[] )
   {
    return ( pqrs[3] & pqrs[1]) | (~pqrs[3] & pqrs[2]);
    }
//H(x,y,z)
unsigned fun2( unsigned pqrs[] )
  {
    return  pqrs[1] ^ pqrs[2] ^ pqrs[3];
   }
//I(x,y,z)
unsigned fun3( unsigned pqrs[] )
  {
    return pqrs[2] ^ (pqrs[1] |~ pqrs[3]);
    }

typedef unsigned (*DigestFunction)(unsigned a[]);

unsigned *CalculateKs( unsigned *k)
{
    double s, pwr;
    int i;
    pwr = pow( 2, 32);
    for (i=0; i<64; i++)
        {
        s = fabs(sin(1+i));
        k[i] = (unsigned)( s * pwr );
           }
    return k;
}

unsigned rotor( unsigned v, short amt )
{
    unsigned  msk1 = (1<<amt) -1;
    return ((v>>(32-amt)) & msk1) | ((v<<amt) & ~msk1);
}

unsigned *AlgoMD5( const char *msg, int mlen)
{
    static Digest h0 = { 0x67452301, 0xEFCDAB89, 0x98BADCFE, 0x10325476 };
    static DigestFunction ff[] = { &fun0, &fun1, &fun2, &fun3 };
    static short M[] = { 1, 5, 3, 7 };
    static short O[] = { 0, 1, 5, 0 };
    static short rotation0[] = { 7,12,17,22};
    static short rotation1[] = { 5, 9,14,20};
    static short rotation2[] = { 4,11,16,23};
    static short rotation3[] = { 6,10,15,21};
    static short *rotations[] = {rotation0, rotation1, rotation2, rotation3 };
    static unsigned kspace[64];
    static unsigned *k;
    static Digest h;
    Digest pqrs;
    DigestFunction fctn;
    short m, o, g;
    unsigned f;
    short *rotation;
    union {
        unsigned w[16];
        char     b[64];
                }mm;
    int os = 0;
    int grp, grps, q, p;
    unsigned char *msg2;
    if (k==NULL) k= CalculateKs(kspace);
    for (q=0; q<4; q++) h[q] = h0[q];
    {
        grps  = 1 + (mlen+8)/64;
        msg2 = (unsigned char *)malloc( 64*grps);
        memcpy( msg2, msg, mlen);
        msg2[mlen] = (unsigned char)0x80;
        q = mlen + 1;
        while (q < 64*grps){ msg2[q] = 0; q++ ; }
        {
            MDunion u;
            u.w = 8*mlen;
            q -= 8;
            memcpy(msg2+q, &u.w, 4 );
        }
    }
    for (grp=0; grp<grps; grp++)
    {
        memcpy( mm.b, msg2+os, 64);
        for(q=0;q<4;q++) pqrs[q] = h[q];
        for (p = 0; p<4; p++) {
            fctn = ff[p];
            rotation = rotations[p];
            m = M[p]; o= O[p];
            for (q=0; q<16; q++) {
                g = (m*q + o) % 16;
                f = pqrs[1] + rotor( pqrs[0]+ fctn(pqrs) + k[q+16*p] + mm.w[g], rotation[q%4]);
                pqrs[0] = pqrs[3];
                pqrs[3] = pqrs[2];
                pqrs[2] = pqrs[1];
                pqrs[1] = f;
            }
        }
        for (p=0; p<4; p++)
            h[p] += pqrs[p];
        os += 64;
    }
    if( msg2 )
        free(msg2);
    return h;
}
int main()
{
    int i,j;
    char msg[10000];
    printf("Enter your message : ");
    gets(msg);
    unsigned *d=AlgoMD5(msg, strlen(msg));
    MDunion u;
    printf("MD5 Hash : ");
    for(i=0;i<4;i++)
        {
        u.w = d[i];
        for (j=0;j<4;j++)
            printf("%02x",u.b[j]);
          }
    printf("\n");
    return 0;
}
