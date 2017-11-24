/*
Name: Prasuna Kunasani
Program: 
  This is a sample C program illustrating:
  - reading a raw image from a file into the buffer; and
  - applying linear filters to the image as outlined in the assignment
Assumptions made:
- That the original image is always 500*500
- That the final image is also the same dimensions for length and width
Can you see visual difference between the two results?
The differences are very subtle but the second filter emphasizes pixels near the center. 
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std; 

#define ROWS 500
#define COLS 500

unsigned int img[ROWS][COLS]; //the grey scale image

unsigned char in_buf[ROWS][COLS];/* Buffer for the input image */
unsigned char out_buf[ROWS][COLS];/* Buffer for the output image */

int main(int argc,char **argv)
{
  FILE *fin, *fout;
  int  i, j, n, N;

  /* Check the number of arguments in the command line. */
  if (argc != 3) {
    fprintf(stderr, "Usage: %s in.img out.img\n", argv[0]);
    exit(1);
  }

  /* Open the input image file */
  if ((fin = fopen(argv[1], "rb")) == NULL) {
    fprintf(stderr, "ERROR: Cann't open input image file %s\n", argv[1]);
    exit(1);
  }

  /* Open the output image file */
  if ((fout = fopen(argv[2], "wb")) == NULL) {
    fprintf(stderr, "ERROR: Cann't open output image file %s\n", argv[2]);
    exit(1);
  }

  /* Load the input image */
  printf("... Load input image\n");
  n=fread(in_buf, sizeof(char), ROWS*COLS, fin);
  if (n < ROWS*COLS*sizeof(char)){
    fprintf(stderr, "ERROR: Read input image file %s error)\n", argv[1]);
    exit(1);
  }
  
  
  /* ===============================================
     Do your processing here
     =============================================== */

   int M=3; 
  int M2 = (M-1)/2; 
 
  //Note: The mask changes according to the filter mentioned in the question. 
  float mask[3][3] = {{0.1111,0.1111,0.1111},
          {0.1111,0.1111,0.1111},
          {0.1111,0.1111,0.1111}};

  /*
 float mask[3][3] = {{0.075,0.125,0.075},
          {0.125,0.2,0.125},
          {0.075,0.125,0.075}};

  */

  for (int a=0; a<ROWS; a++)
    {
      for(int b=0; b<COLS; b++)
       {
          img[a][b] = (unsigned int) in_buf[a][b];
      }
   }
  
  for (int i=0; i<ROWS; i++)
    {
      for (int j=0; j<COLS; j++)
      {
       float t_sum = 0.0; 
       for (int k =-M2; k<=M2; k++)
       {
        for(int l=-M2; l<=M2; l++)
        {
          if((0<=i+k)&&(i+k<ROWS)&&(0<=j+l&&j+l<COLS)) 
          t_sum += img[i+k][j+l] * mask[k+M2][l+M2];
          else
          t_sum += img[i][j] *mask[k+M2][l+M2];
        }
        out_buf[i][j] = (unsigned char) ((int)t_sum); 
       }
      }
    }
  
  /* Save the output image. */
  printf("... Save the output image\n");
  n=fwrite(out_buf, sizeof(char), ROWS*COLS, fout);
  if (n < ROWS*COLS*sizeof(char)) {
    fprintf(stderr, "ERROR: Write output image file %s error)\n", argv[1]);
    exit(1);
  }

  fclose(fin);
  fclose(fout);
}
