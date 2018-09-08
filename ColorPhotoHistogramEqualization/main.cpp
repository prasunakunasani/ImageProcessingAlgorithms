/*
Name: Prasuna Kunasani
Program:
  This is a sample C program illustrating:
  - reading a raw colour image from a file into the buffer; and
  - normalizing the histogram of the color channels
  - saving the image back into a output buffer
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define ROWS 300
#define COLS 400
#define K 256 //number of grey levels
int histR[K], histG[K], histB[K];  //the histogram
int cumHistR[K], cumHistG[K], cumHistB[K];

unsigned char in_buf[ROWS][COLS*3];/* Buffer for the input image */
unsigned char out_buf[ROWS][COLS*3];/* Buffer for the output image */

unsigned char RGB[3][ROWS][COLS];

int main(int argc, char **argv) {
    FILE *fin, *fout;
    int i, j, n, N;

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
    n = fread(in_buf, sizeof(char), ROWS * COLS *3, fin);
    if (n != ROWS * COLS * 3 * sizeof(char)) {
        fprintf(stderr, "ERROR: Read input image file %s error)\n", argv[1]);
        exit(1);
    }


    /* ===============================================
       Do your processing here
       =============================================== */

    //Initialize the histogram
    for (int a = 0; a < K; a++) {
        histR[a] = 0;
        histG[a] = 0;
        histB[a] = 0;
    }

    //load the color image into a color image buffer
    int color = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            RGB[0][i][j] = (unsigned int) in_buf[i][3*j];
            RGB[1][i][j] = (unsigned int) in_buf[i][3*j+1];
            RGB[2][i][j] = (unsigned int) in_buf[i][3*j+2];
        }
    }

    //Compute the histogram for .
    for (int x = 0; x < ROWS; x++) {
        for (int y = 0; y < COLS; y++) {
            histR[RGB[0][x][y]]++;
            histG[RGB[1][x][y]]++;
            histB[RGB[2][x][y]]++;
        }
    }
    cumHistR[0] = histR[0];
    cumHistG[0] = histG[0];
    cumHistB[0] = histB[0];

    //Compute the cumulative histogram
    for (int b = 1; b < K; b++) {
        cumHistR[b] = histR[b] + cumHistR[b - 1];
        cumHistG[b] = histG[b] + cumHistG[b - 1];
        cumHistB[b] = histB[b] + cumHistB[b - 1];

    }
    cout << endl;

    //Normalize cumHist[] with the scaling foctor S where S = (K-1)/(ROWSxCOLS)
    //a' = H(a) * S

    float S = (K - 1) / (float) (ROWS * COLS);

    //posible fix - should be rows/3 up there

    for (int c = 0; c < K; c++) {
        cumHistR[c] = cumHistR[c] * S;
        cumHistG[c] = cumHistG[c] * S;
        cumHistB[c] = cumHistB[c] * S;
    }

    for (int d = 0; d < ROWS; d++) {
        for (int e = 0; e < COLS; e++) {
            out_buf[d][3*e] = (unsigned char) cumHistR[RGB[0][d][e]];
            out_buf[d][3*e+1] = (unsigned char) cumHistG[RGB[1][d][e]];
            out_buf[d][3*e+2] = (unsigned char) cumHistB[RGB[2][d][e]];
        }
    }

    /* Save the output image. */
    printf("... Save the output image\n");
    n = fwrite(out_buf, sizeof(char), ROWS * COLS * 3, fout);
    if (n != ROWS * COLS * 3 * sizeof(char)) {
        fprintf(stderr, "ERROR: Write output image file %s error)\n", argv[1]);
        exit(1);
    }

    fclose(fin);
    fclose(fout);
}
