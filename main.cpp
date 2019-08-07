#include <cstdio>
#include <cstdlib>
#include <cmath>

#include "tgaimage.h"

TGAColor white = {255, 255, 255, 255};
TGAColor green = {  0, 255,   0, 255};

struct dot {
  int x = 0;
  int y = 0;
};

void line(dot d1, dot d2, TGAImage &image);

int main() {
  int height = 0;
  int width = 0;

  printf("Enter height of image:\n");
  scanf("%d", &height);

  printf("\nEnter width of image:\n");
  scanf("%d", &width);

  TGAImage image(height, width, TGAImage::RGB);

  dot d1;
  dot d2;

  int trying = 0;

  do {
    if (trying == 2) {
      printf("Wrong coordinates!\n\n");
      return -1;
    } else trying++;

    printf("\nEnter first dot coordinates:\n\tx1 = ");
    scanf("%d", &d1.x);
    printf("\ty1 = ");
    scanf("%d", &d1.y);
  } while (d1.x > width || d1.y > height || trying == 3);

  trying = 0;

  do {
    if (trying == 2) {
      printf("Wrong coordinates!\n\n");
      return -1;
    } else trying ++;

    printf("\nEnter second dot coordinates:\n\tx2 = ");
    scanf("%d", &d2.x);
    printf("\ty2 = ");
    scanf("%d", &d2.y);
  } while (d2.x > width || d2.y > height || trying == 3);
  
  line(d1, d2, image);

  image.flip_vertically();

  image.write_tga_file("output.tga");
}

void line(dot d1, dot d2, TGAImage &image) {
  int deltax = abs(d2.x - d1.x);
  int diry = abs(d2.y - d1.y);

  float direr = dirx / diry; 
  float error = 0;


}

