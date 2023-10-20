#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "image2.h"

/*******************************************************
   24ビット-ビットマップデータ (BMPファイル) のファイル入出力
   (制限)
     - 画像の横幅は４の倍数であること
     - リトルエンディアンにのみ対応
********************************************************/

void bmp_read (
  char filename[], 
  bmp_data_t *bmp

)
{
  FILE *fp;
  int i, j;
	
  /* ファイルオープン */
  if ((fp = fopen(filename, "rb"))==NULL) {
    fprintf(stderr, "read_bmp: failed to open \"%s\"\n", filename);
    exit(1);
  }
  fprintf(stderr, "input file = \"%s\"\n", filename);

  /* ヘッダ情報の読み込み */
  fread(&bmp->header.bfType, sizeof(bmp->header.bfType), 1, fp);
  fread(&bmp->header.bfSize, sizeof(bmp->header.bfSize), 1, fp);
  fread(&bmp->header.bfReserved1, sizeof(bmp->header.bfReserved1), 1, fp);
  fread(&bmp->header.bfReserved2, sizeof(bmp->header.bfReserved2), 1, fp);
  fread(&bmp->header.bfOffBits, sizeof(bmp->header.bfOffBits), 1, fp);
  fread(&bmp->header.biSize, sizeof(bmp->header.biSize), 1, fp);
  fread(&bmp->header.biWidth, sizeof(bmp->header.biWidth), 1, fp);
  fread(&bmp->header.biHeight, sizeof(bmp->header.biHeight), 1, fp);
  fread(&bmp->header.biPlanes, sizeof(bmp->header.biPlanes), 1, fp);
  fread(&bmp->header.biBitCount, sizeof(bmp->header.biBitCount), 1, fp);
  fread(&bmp->header.biCompression, sizeof(bmp->header.biCompression), 1, fp);
  fread(&bmp->header.biSizeImage, sizeof(bmp->header.biSizeImage), 1, fp);
  fread(&bmp->header.biXPelsPerMeter, sizeof(bmp->header.biXPelsPerMeter), 1, fp);
  fread(&bmp->header.biYPelsPerMeter, sizeof(bmp->header.biYPelsPerMeter), 1, fp);
  fread(&bmp->header.biClrUsed, sizeof(bmp->header.biClrUsed), 1, fp);
  fread(&bmp->header.biClrImportant, sizeof(bmp->header.biClrImportant), 1, fp);

  assert(bmp->header.biHeight<=MAX_Y);
  assert(bmp->header.biWidth<=MAX_X);
        
  /* ビットマップデータの読み込み */
  for (i=0; i < bmp->header.biHeight; i++) {
    for (j=0; j < bmp->header.biWidth; j++) {
      fread(&bmp->img[i][j].b, 1, 1, fp);
      fread(&bmp->img[i][j].g, 1, 1, fp);
      fread(&bmp->img[i][j].r, 1, 1, fp);
    }
  }	

  /* ファイルクローズ */
  fclose(fp);
}


void bmp_write(
  char filename[], 
  bmp_data_t *bmp
)
{
  FILE *fp;
  int i, j;
	
  assert(bmp->header.biHeight<=MAX_Y);
  assert(bmp->header.biWidth<=MAX_X);

  /* ファイルオープン */
  if ((fp = fopen(filename, "wb"))==NULL) {
    fprintf(stderr, "write_bmp: failed to open \"%s\"\n", filename);
    exit(1);
  }
  fprintf(stderr, "output file = %s\n", filename);

  /* ヘッダ情報の書き出し */
  fwrite(&bmp->header.bfType, sizeof(bmp->header.bfType), 1, fp);
  fwrite(&bmp->header.bfSize, sizeof(bmp->header.bfSize), 1, fp);
  fwrite(&bmp->header.bfReserved1, sizeof(bmp->header.bfReserved1), 1, fp);
  fwrite(&bmp->header.bfReserved2, sizeof(bmp->header.bfReserved2), 1, fp);
  fwrite(&bmp->header.bfOffBits, sizeof(bmp->header.bfOffBits), 1, fp);
  fwrite(&bmp->header.biSize, sizeof(bmp->header.biSize), 1, fp);
  fwrite(&bmp->header.biWidth, sizeof(bmp->header.biWidth), 1, fp);
  fwrite(&bmp->header.biHeight, sizeof(bmp->header.biHeight), 1, fp);
  fwrite(&bmp->header.biPlanes, sizeof(bmp->header.biPlanes), 1, fp);
  fwrite(&bmp->header.biBitCount, sizeof(bmp->header.biBitCount), 1, fp);
  fwrite(&bmp->header.biCompression, sizeof(bmp->header.biCompression), 1, fp);
  fwrite(&bmp->header.biSizeImage, sizeof(bmp->header.biSizeImage), 1, fp);
  fwrite(&bmp->header.biXPelsPerMeter, sizeof(bmp->header.biXPelsPerMeter), 1, fp);
  fwrite(&bmp->header.biYPelsPerMeter, sizeof(bmp->header.biYPelsPerMeter), 1, fp);
  fwrite(&bmp->header.biClrUsed, sizeof(bmp->header.biClrUsed), 1, fp);
  fwrite(&bmp->header.biClrImportant, sizeof(bmp->header.biClrImportant), 1, fp);

  /* ビットマップデータの書き出し */
  for (i=0; i < bmp->header.biHeight; i++) {
    for (j=0; j < bmp->header.biWidth; j++) {
      fwrite(&bmp->img[i][j].b, 1, 1, fp);
      fwrite(&bmp->img[i][j].g, 1, 1, fp);
      fwrite(&bmp->img[i][j].r, 1, 1, fp);
    }
  }  

  /* ファイルクローズ */
  fclose(fp);
}