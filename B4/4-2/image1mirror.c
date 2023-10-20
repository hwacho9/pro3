#include <stdio.h>
#include "image1.h"


/* 画像全体を「涼しげ」にする関数 */
void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]); 


int main(void)
{
   bmp_header_t hd;
   pixel_t img [MAX_Y][MAX_X];

   bmp_read("in.bmp", &hd, img);    /* in.bmp から読み込む */
   bmp_mirror(&hd, img);              /* 処理の呼び出し */
   bmp_write("out.bmp", &hd, img);  /* out.bmp への書き出し */

   return 0;
}


/* 画像処理の関数の本体 */
void bmp_mirror(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
  int i, j;
    pixel_t temp;

    for (i = 0; i < hd->biHeight / 2; i++) {
        for (j = 0; j < hd->biWidth; j++) {
            // 현재 픽셀과 대칭되는 픽셀을 스왑
            temp = img[i][j];
            img[i][j] = img[hd->biHeight - 1 - i][j];
            img[hd->biHeight - 1 - i][j] = temp;
        }
    }
  /************** ここまで *************************************************/

}