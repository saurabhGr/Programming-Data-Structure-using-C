#include<stdio.h>
#include<math.h>
#include<ctype.h>
float encrypt[3][1], decrypt[3][1], a[3][3], b[3][3], mes[3][1], c[3][3];
void encryption()
{
	int i, j, k;
// implementing c1=k11p1+k21p2+k31p3
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];

	printf("\nEncrypted string is: ");
	//converting back to alphabetical
	for(i = 0; i < 3; i++)
		printf("%c", (char)((int)(encrypt[i][0])%26 + 65));

}
void decryption()
{
	int i, j, k;
	if(!inverse())
	return 0;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 3; k++)
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];

	printf("\nDecrypted string is: ");
	for(i = 0; i < 3; i++)
		printf("%c", (char)(fmod(decrypt[i][0], 26) + 65));
	printf("\n");
}
void getKeyMessage() {
	int i, j;
	char msg[3];
	printf("Enter 3x3 matrix for key (It should be inversible):\n");
	// stores key
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
            {
			scanf("%f", &a[i][j]);
			c[i][j] = a[i][j];
		   }
		   //check whether key having inverse or not
		   if(!inverse())
            return 0;
	printf("\nEnter a letter string: ");
	scanf("%s", msg);
	//converting stored msg into UPPER case
	for(i = 0; i < 3; i++)
        msg[i]=toupper(msg[i]);
        // converting stored msg into 0-26
	for(i = 0; i < 3; i++)
		mes[i][0] = msg[i]-65;
}
int inverse()
{  long determinant;
    int i, j, k;
	float p, q;
//creating identity matrix
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
            {
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		      }
// calculating cofactor matrix
	for(k = 0; k < 3; k++) {
		for(i = 0; i < 3; i++) {
			p = c[i][k];
			q = c[k][k];

			for(j = 0; j < 3; j++) {
				if(i != k) {
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}

	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			b[i][j] = b[i][j] / c[i][i];
    determinant = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]
                  * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
    if ( determinant == 0)
    {printf("\nMatrix is NOT invertible");
     return 0;}
    else
        printf("\nThe given matrix has an inverse!!!");
    return 1;
}
void main()
{ //go and bring msg from stdin
	getKeyMessage();
	// after getting msg from stdin call encryption
	encryption();
	decryption();
}
