#include <stdio.h>
#include "image1.h"


/* 画像全体を「涼しげ」にする関数 */
void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]); 


int main(void)
{
   bmp_header_t hd;
   pixel_t img [MAX_Y][MAX_X];

   bmp_read("in.bmp", &hd, img);    /* in.bmp から読み込む */
   bmp_collapse(&hd, img);              /* 処理の呼び出し */
   bmp_write("out.bmp", &hd, img);  /* out.bmp への書き出し */

   return 0;
}


/* 画像処理の関数の本体 */
void bmp_collapse(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
  int i, j;
    int new_height = hd->biHeight / 2; 
    
    hd->biHeight = new_height;

    for (i = 0; i < new_height; i++) {
        for (j = 0; j < hd->biWidth; j++) {
            // 각 두 픽셀의 색상값을 평균하여 설정
            img[i][j].r = (img[i * 2][j].r + img[i * 2 + 1][j].r) / 2;
            img[i][j].g = (img[i * 2][j].g + img[i * 2 + 1][j].g) / 2;
            img[i][j].b = (img[i * 2][j].b + img[i * 2 + 1][j].b) / 2;
        }
    }
  /************** ここまで *************************************************/

}