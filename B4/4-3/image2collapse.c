#include <stdio.h>
#include "image2.h"


/* 画像全体を「涼しげ」にする関数 */
void bmp_collapse(bmp_data_t *bmp); 


int main(void)
{
   bmp_data_t bmp;

   bmp_read("in.bmp", &bmp);    /* in.bmp から読み込む */
   bmp_collapse(&bmp);              /* 処理の呼び出し */
   bmp_write("out.bmp", &bmp);  /* out.bmp への書き出し */

   return 0;
}


/* 画像処理の関数の本体 */
void bmp_collapse(bmp_data_t *bmp)
{
  int i, j;
    int new_height = bmp->header.biHeight / 2; 
    
    bmp->header.biHeight = new_height;

    for (i = 0; i < bmp->header.biHeight; i++) {
        for (j = 0; j < bmp->header.biWidth; j++) {
            // 각 두 픽셀의 색상값을 평균하여 설정
            bmp->img[i][j].r = (bmp->img[i * 2][j].r + bmp->img[i * 2 + 1][j].r) / 2;
            bmp->img[i][j].g = (bmp->img[i * 2][j].g + bmp->img[i * 2 + 1][j].g) / 2;
            bmp->img[i][j].b = (bmp->img[i * 2][j].b + bmp->img[i * 2 + 1][j].b) / 2;
        }
    }
  /************** ここまで *************************************************/

}