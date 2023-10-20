#include <stdio.h>
#include "image1.h"


/* 画像全体を「涼しげ」にする関数 */
void bmp_frame(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]); 


int main(void)
{
   bmp_header_t hd;
   pixel_t img [MAX_Y][MAX_X];

   bmp_read("in.bmp", &hd, img);    /* in.bmp から読み込む */
   bmp_frame(&hd, img);              /* 処理の呼び出し */
   bmp_write("out.bmp", &hd, img);  /* out.bmp への書き出し */

   return 0;
}


/* 画像処理の関数の本体 */
void bmp_frame(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j; 

    pixel_t red;
        red.r = HIGH;
        red.g = LOW;
        red.b = LOW;

    
    printf("%d\n", hd->biWidth);
    printf("%d", hd->biHeight);

//left axis
    for (i = 0; i < hd->biWidth; i++) {
        for ( j = 0; j < hd->biHeight - 315 ; j++) {
            img[i][j] = red;
        }
    }
    
    //top cross
    for (i = hd->biHeight - 5; i < hd->biHeight; i++) {
        for (j = 0; j < hd->biWidth; j++) {
            img[i][j] = red;
        }
    }
    //bottom cross
    for (i = 0; i < hd->biHeight - 315; i++) {
        for (j = 0; j < hd->biWidth; j++) {
            img[i][j] = red;
        }
    }

    //right axis
    for (i = 0; i < hd->biHeight; i++) {
        for (j = hd->biWidth - 5; j < hd->biWidth; j++) {
            img[i][j] = red;
        }
    }

}


  /************** ここまで *************************************************/

