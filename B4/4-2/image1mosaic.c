#include <stdio.h>
#include "image1.h"


/* 画像全体を「涼しげ」にする関数 */
void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X]); 


int main(void)
{
   bmp_header_t hd;
   pixel_t img [MAX_Y][MAX_X];

   bmp_read("in.bmp", &hd, img);    /* in.bmp から読み込む */
   bmp_mosaic(&hd, img);              /* 処理の呼び出し */
   bmp_write("out.bmp", &hd, img);  /* out.bmp への書き出し */

   return 0;
}


/* 画像処理の関数の本体 */
void bmp_mosaic(bmp_header_t *hd, pixel_t img[MAX_Y][MAX_X])
{
    int i, j;
    int width = hd->biWidth;

    // 이미지의 왼쪽 절반에만 모자이크 처리 적용
    for (i = 0; i < hd->biHeight; i += 16) {
        for (j = 0; j < width / 2; j += 16) {
            int sum_r = 0, sum_g = 0, sum_b = 0;
            int count = 0;
            
            // 블록 내의 픽셀들의 평균값 계산
            for (int k = i; k < i + 16; k++) {
                for (int l = j; l < j + 16; l++) {
                    sum_r += img[k][l].r;
                    sum_g += img[k][l].g;
                    sum_b += img[k][l].b;
                    count++;
                }
            }
            // 블록 내의 픽셀을 평균값으로 설정
            for (int k = i; k < i + 16; k++) {
                for (int l = j; l < j + 16; l++) {
                    img[k][l].r = sum_r / count;
                    img[k][l].g = sum_g / count;
                    img[k][l].b = sum_b / count;
                }
            }
        }
    }
}





