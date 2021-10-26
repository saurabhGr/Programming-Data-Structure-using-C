#ifndef _DES_H_
#define _DES_H_
#define ENCRYPTION_MODE 1
#define DECRYPTION_MODE 0
typedef struct
{
      unsigned char temp[8];
      unsigned char y[4];
      unsigned char z[4];
} key_set;
void generate_key(unsigned char* key);
void generate_sub_keys(unsigned char* main_key, key_set* key_sets);
void process_message(unsigned char* message_piece, unsigned char* processed_piece, key_set* key_sets, int mode);
#endif // _DES_H_
#include <stdio.h>
#include <stdlib.h>
int key_shift_sizes[] = {-1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1};

int key_permutation[] = {
                         57, 49, 41, 33, 25, 17, 9,
                         1, 58, 50, 42, 34, 26, 18,
                         10, 2, 59, 51, 43, 35, 27,
                         19, 11, 3, 60, 52, 44, 36,
                         63, 55, 47, 39, 31, 23, 15,
                         7, 62, 54, 46, 38, 30, 22,
                         14, 6, 61, 53, 45, 37, 29,
                         21, 13, 5, 28, 20, 12, 4 };

int message_permutation[] = {
                             58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17,  9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 };

int sub_key_permutation[] = {
                             14, 17, 11, 24, 1, 5,
                             3, 28, 15, 6, 21, 10,
                             23, 19, 12,  4, 26, 8,
                             16, 7, 27, 20, 13, 2,
                             41, 52, 31, 37, 47, 55,
                             30, 40, 51, 45, 33, 48,
                             44, 49, 39, 56, 34, 53,
                             46, 42, 50, 36, 29, 32 };

int message[] =  {
                  32, 1, 2, 3, 4, 5,
                  4, 5, 6, 7, 8, 9,
                  8, 9, 10, 11, 12, 13,
                  12, 13, 14, 15, 16, 17,
                  16, 17, 18, 19, 20, 21,
                  20, 21, 22, 23, 24, 25,
                  24, 25, 26, 27, 28, 29,
                  28, 29, 30, 31, 32, 1 };

int array_a1[] = {
                  14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                  0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                  4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                  15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 };

int array_a2[] = {
                  15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                  3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                  0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                  13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 };

int array_a3[] = {
                  10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                  13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                  13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                  1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 };

int array_a4[] = {
                  7, 13, 14,  3,  0,  6,  9, 10,  1,  2,  8,  5, 11, 12,  4, 15,
                  13,  8, 11,  5,  6, 15,  0,  3,  4,  7,  2, 12,  1, 10, 14,  9,
                  10,  6,  9,  0, 12, 11,  7, 13, 15,  1,  3, 14,  5,  2,  8,  4,
                  3, 15,  0,  6, 10,  1, 13,  8,  9,  4,  5, 11, 12,  7,  2, 14 };

int array_a5[] = {
                  2, 12,  4,  1,  7, 10, 11,  6,  8,  5,  3, 15, 13,  0, 14,  9,
                  14, 11,  2, 12,  4,  7, 13,  1,  5,  0, 15, 10,  3,  9,  8,  6,
                  4,  2,  1, 11, 10, 13,  7,  8, 15,  9, 12,  5,  6,  3,  0, 14,
                  11,  8, 12,  7,  1, 14,  2, 13,  6, 15,  0,  9, 10,  4,  5,  3 };

int array_a6[] = {
                  12,  1, 10, 15,  9,  2,  6,  8,  0, 13,  3,  4, 14,  7,  5, 11,
                  10, 15,  4,  2,  7, 12,  9,  5,  6,  1, 13, 14,  0, 11,  3,  8,
                  9, 14, 15,  5,  2,  8, 12,  3,  7,  0,  4, 10,  1, 13, 11,  6,
                  4,  3,  2, 12,  9,  5, 15, 10, 11, 14,  1,  7,  6,  0,  8, 13 };

int array_a7[] = {
                  4, 11,  2, 14, 15,  0,  8, 13,  3, 12,  9,  7,  5, 10,  6,  1,
                  13,  0, 11,  7,  4,  9,  1, 10, 14,  3,  5, 12,  2, 15,  8,  6,
                  1,  4, 11, 13, 12,  3,  7, 14, 10, 15,  6,  8,  0,  5,  9,  2,
                  6, 11, 13,  8,  1,  4, 10,  7,  9,  5,  0, 15, 14,  2,  3, 12 };

int array_a8[] = {
                  13,  2,  8,  4,  6, 15, 11,  1, 10,  9,  3, 14,  5,  0, 12,  7,
                  1, 15, 13,  8, 10,  3,  7,  4, 12,  5,  6, 11,  0, 14,  9,  2,
                  7, 11,  4,  1,  9, 12, 14,  2,  0,  6, 10, 13, 15,  3,  5,  8,
                  2,  1, 14,  7,  4, 10,  8, 13, 15, 12,  9,  0,  3,  5,  6, 11 };

int intermediate_permutation[] = {
                                  16,  7, 20, 21,
                                  29, 12, 28, 17,
                                  1, 15, 23, 26,
                                  5, 18, 31, 10,
                                  2,  8, 24, 14,
                                  32, 27,  3,  9,
                                  19, 13, 30,  6,
                                  22, 11,  4, 25 };

int end_permutation[] = {
                         40,  8, 48, 16, 56, 24, 64, 32,
                         39,  7, 47, 15, 55, 23, 63, 31,
                         38,  6, 46, 14, 54, 22, 62, 30,
                         37,  5, 45, 13, 53, 21, 61, 29,
                         36,  4, 44, 12, 52, 20, 60, 28,
                         35,  3, 43, 11, 51, 19, 59, 27,
                         34,  2, 42, 10, 50, 18, 58, 26,
                         33,  1, 41,  9, 49, 17, 57, 25 };

void make_keys(unsigned char* key)
{
      int count;
      for(count = 0; count < 8; count++)
      {
            key[count] = rand()%255;
      }
}

void binary_digits(char input)
{
      int count;
      for(count = 0; count < 8; count++)
      {
            char shift_byte = 0x01 << (7 - count);
            if(shift_byte & input)
            {
                  printf("1");
            }
            else
            {
                  printf("0");
            }
      }
}

void display_keys(key_set key_set)
{
      int count;
      printf("Y: \n");
      for(count = 0; count < 8; count++)
      {
            printf("%02X : ", key_set.temp[count]);
            binary_digits(key_set.temp[count]);
            printf("\n");
      }
      printf("\nX: \n");
      for(count = 0; count < 4; count++)
      {
            printf("%02X : ", key_set.y[count]);
            binary_digits(key_set.y[count]);
            printf("\n");
      }
      printf("\nZ: \n");
      for(count = 0; count < 4; count++)
      {
            printf("%02X : ", key_set.z[count]);
            binary_digits(key_set.z[count]);
             printf("\n");
      }
      printf("\n");
}

void key_maker(unsigned char* main_key, key_set* key_sets)
{
      int m, n,i;
      int shift_size;
      unsigned char shift_byte, first_bit, second_bit, third_bit, fourth_bit;
      for(m = 0; m < 8; m++)
      {
            key_sets[0].temp[m] = 0;
      }
      for(m = 0; m < 56; m++)
      {
            shift_size = key_permutation[m];
            shift_byte = 0x80 >> ((shift_size - 1)%8);
            shift_byte &= main_key[(shift_size - 1)/8];
            shift_byte <<= ((shift_size - 1)%8);
            key_sets[0].temp[m/8] |= (shift_byte >> m%8);
      }
      for(m = 0; m < 3; m++)
      {
            key_sets[0].y[m] = key_sets[0].temp[m];
      }
      key_sets[0].y[3] = key_sets[0].temp[3] & 0xF0;
      for(m = 0; m < 3; m++)
      {
            key_sets[0].z[m] = (key_sets[0].temp[m + 3] & 0x0F) << 4;
            key_sets[0].z[m] |= (key_sets[0].temp[m + 4] & 0xF0) >> 4;
      }
      key_sets[0].z[3] = (key_sets[0].temp[6] & 0x0F) << 4;
      for(m = 1; m < 17; m++)
      {
            for(n = 0; n < 4; n++)
            {
                  key_sets[m].y[n] = key_sets[m - 1].y[n];
                  key_sets[m].z[n] = key_sets[m - 1].z[n];
            }
            shift_size = key_shift_sizes[i];
            if(shift_size == 1)
            {
                  shift_byte = 0x80;
            }
            else
            {
                  shift_byte = 0xC0;
            }
            first_bit = shift_byte & key_sets[m].y[0];
            second_bit = shift_byte & key_sets[m].y[1];
            third_bit = shift_byte & key_sets[m].y[2];
            fourth_bit = shift_byte & key_sets[m].y[3];
            key_sets[m].y[0] <<= shift_size;
            key_sets[m].y[0] |= (second_bit >> (8 - shift_size));
            key_sets[m].y[1] <<= shift_size;
            key_sets[m].y[1] |= (third_bit >> (8 - shift_size));
            key_sets[m].y[2] <<= shift_size;
            key_sets[m].y[2] |= (fourth_bit >> (8 - shift_size));
            key_sets[m].y[3] <<= shift_size;
            key_sets[m].y[3] |= (first_bit >> (4 - shift_size));
            first_bit = shift_byte & key_sets[m].z[0];
            second_bit = shift_byte & key_sets[m].z[1];
            third_bit = shift_byte & key_sets[m].z[2];
            fourth_bit = shift_byte & key_sets[m].z[3];
            key_sets[m].z[0] <<= shift_size;
            key_sets[m].z[0] |= (second_bit >> (8 - shift_size));
            key_sets[m].z[1] <<= shift_size;
            key_sets[m].z[1] |= (third_bit >> (8 - shift_size));
            key_sets[m].z[2] <<= shift_size;
            key_sets[m].z[2] |= (fourth_bit >> (8 - shift_size));
            key_sets[m].z[3] <<= shift_size;
            key_sets[m].z[3] |= (first_bit >> (4 - shift_size));
            for(n = 0; n < 48; n++)
            {
                  shift_size = sub_key_permutation[n];
                  if(shift_size <= 28)
                  {
                        shift_byte = 0x80 >> ((shift_size - 1)%8);
                        shift_byte &= key_sets[m].y[(shift_size - 1)/8];
                        shift_byte <<= ((shift_size - 1)%8);
                  }
                  else
                  {
                        shift_byte = 0x80 >> ((shift_size - 29)%8);
                        shift_byte &= key_sets[m].z[(shift_size - 29)/8];
                        shift_byte <<= ((shift_size - 29)%8);
                  }
                  key_sets[m].temp[n/8] |= (shift_byte >> n%8);
            }
      }
}

void evaluate_message(unsigned char* message_piece, unsigned char* processed_piece, key_set* key_sets, int mode)
{
      unsigned char initial_permutation[8], final_permutation[8];
      unsigned char row, column, shift_byte;
      unsigned char ln[4], rn[4], er[6], ser[4], l[4], r[4];
      int count, temp, key_position, shift_size;
      memset(initial_permutation, 0, 8);
      memset(processed_piece, 0, 8);
      for(count = 0; count < 64; count++)
      {
            shift_size = message_permutation[count];
            shift_byte = 0x80 >> ((shift_size - 1)%8);
            shift_byte &= message_piece[(shift_size - 1)/8];
            shift_byte <<= ((shift_size - 1)%8);
            initial_permutation[count/8] |= (shift_byte >> count%8);
      }
      for(count = 0; count < 4; count++)
      {
            l[count] = initial_permutation[count];
            r[count] = initial_permutation[count + 4];
      }
      for(temp = 1; temp <= 16; temp++)
      {
            memcpy(ln, r, 4);
            memset(er, 0, 6);
            for(count = 0; count < 48; count++)
            {
                  shift_size = message[count];
                  shift_byte = 0x80 >> ((shift_size - 1)%8);
                  shift_byte &= r[(shift_size - 1)/8];
                  shift_byte <<= ((shift_size - 1)%8);
                  er[count/8] |= (shift_byte >> count%8);
            }
            if(mode == DECRYPTION_MODE)
            {
                  key_position = 17 - temp;
            }
            else
            {
                  key_position = temp;
            }
            for(count = 0; count < 6; count++)
            {
                  er[count] ^= key_sets[key_position].temp[count];
            }
            for(count = 0; count < 4; count++)
            {
                  ser[count] = 0;
            }
            row = 0;
            row |= ((er[0] & 0x80) >> 6);
            row |= ((er[0] & 0x04) >> 2);
            column = 0;
            column |= ((er[0] & 0x78) >> 3);
            ser[0] |= ((unsigned char)array_a1[row*16 + column] << 4);
            row = 0;
            row |= (er[0] & 0x02);
            row |= ((er[1] & 0x10) >> 4);
            column = 0;
            column |= ((er[0] & 0x01) << 3);
            column |= ((er[1] & 0xE0) >> 5);
            ser[0] |= (unsigned char)array_a2[row*16 + column];
            row = 0;
            row |= ((er[1] & 0x08) >> 2);
            row |= ((er[2] & 0x40) >> 6);
            column = 0;
            column |= ((er[1] & 0x07) << 1);
            column |= ((er[2] & 0x80) >> 7);
            ser[1] |= ((unsigned char)array_a3[row*16 + column] << 4);
            row = 0;
            row |= ((er[2] & 0x20) >> 4);
            row |= (er[2] & 0x01);
            column = 0;
            column |= ((er[2] & 0x1E) >> 1);
            ser[1] |= (unsigned char)array_a4[row*16 + column];
            row = 0;
            row |= ((er[3] & 0x80) >> 6);
            row |= ((er[3] & 0x04) >> 2);
            column = 0;
            column |= ((er[3] & 0x78) >> 3);
            ser[2] |= ((unsigned char)array_a5[row*16 + column] << 4);
            row = 0;
            row |= (er[3] & 0x02);
            row |= ((er[4] & 0x10) >> 4);
            column = 0;
            column |= ((er[3] & 0x01) << 3);
            column |= ((er[4] & 0xE0) >> 5);
            ser[2] |= (unsigned char)array_a6[row*16 + column];
            row = 0;
            row |= ((er[4] & 0x08) >> 2);
            row |= ((er[5] & 0x40) >> 6);
            column = 0;
            column |= ((er[4] & 0x07) << 1);
            column |= ((er[5] & 0x80) >> 7);
            ser[3] |= ((unsigned char)array_a7[row*16 + column] << 4);
            row = 0;
            row |= ((er[5] & 0x20) >> 4);
            row |= (er[5] & 0x01);
            column = 0;
            column |= ((er[5] & 0x1E) >> 1);
            ser[3] |= (unsigned char)array_a8[row*16 + column];
            for(count = 0; count < 4; count++)
            {
                  rn[count] = 0;
            }
            for(count = 0; count < 32; count++)
            {
                  shift_size = intermediate_permutation[count];
                  shift_byte = 0x80 >> ((shift_size - 1)%8);
                  shift_byte &= ser[(shift_size - 1)/8];
                  shift_byte <<= ((shift_size - 1)%8);
                  rn[count/8] |= (shift_byte >> count%8);
            }
            for(count = 0; count < 4; count++)
            {
                  rn[count] ^= l[count];
            }
            for(count = 0; count < 4; count++)
            {
                  l[count] = ln[count];
                  r[count] = rn[count];
            }
      }
      for(count = 0; count < 4; count++)
      {
            final_permutation[count] = r[count];
            final_permutation[4 + count] = l[count];
      }
      for(count = 0; count < 64; count++)
      {
            shift_size = end_permutation[count];
            shift_byte = 0x80 >> ((shift_size - 1)%8);
            shift_byte &= final_permutation[(shift_size - 1)/8];
            shift_byte <<= ((shift_size - 1)%8);
            processed_piece[count/8] |= (shift_byte >> count%8);
      }
}
