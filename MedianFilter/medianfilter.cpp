/*
Name: Prasuna Kunasani
Program: 
  This is a sample C program illustrating:
  - reading a raw image from a file into the buffer; and
  - applying the median filter to the image and then saving that image
Assumptions made:
- That the original image is always 440*455
- That the final image is also the same dimensions for length and width
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std; 

#define ROWS 440
#define COLS 455

unsigned int img[ROWS][COLS]; //the grey scale image

unsigned char in_buf[ROWS][COLS];/* Buffer for the input image */
unsigned char out_buf[ROWS][COLS];/* Buffer for the output image */

int median(int[],int);

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
         int sequence[9]={0,0,0,0,0,0,0,0,0};   
        int counter = 0;
        for (int k =-M2; k<=M2; k++)
      {
          for(int l=-M2; l<=M2; l++)
          {
              if((0<=i+k)&&(i+k<ROWS)&&(0<=j+l&&j+l<COLS)) 
            { 
                sequence[counter] = img[i+k][j+l]; 
                counter++;           
            } 
      
              sort(sequence,sequence+9); 
    
               for (int i = 0; i < (9 / 2); i++)
                   {
                  int temporary = sequence[i];          
                  sequence[i] = sequence[(9 - 1) - i];
                  sequence[(9 - 1) - i] = temporary;
                  }
    
              out_buf[i][j] = (unsigned char) median(sequence,counter); 
          }
      
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

// Function for calculating median
int median(int a[], int n)
{
  // First we sort the array
  sort(a, a+n);
 
  // check for even case
  if (n % 2 != 0)
    return a[n/2];
     
  return (a[(n-1)/2] + a[n/2])/2;
}


