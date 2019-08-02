#include <cstdio>
#include <cstdlib>

#include "tgaimage.h"

TGAColor white = {255, 255, 255, 255};
TGAColor green = {  0, 255,   0, 255};

struct dot {
  int x = 0;
  int y = 0;
};

void line(dot d1, dot d1, TGAImage image);

int main() {
  TGAImage image(1000, 1000, TGAImage::RGB);

  dot d1;
  dot d2;

  printf("Enter first dot coordinates:\n\tx1 = ");
  scanf("%d", &d1.x);
  printf("\ty1 = ");
  scanf("%d", &d1.y);

  printf("\nEnter second dot coordinates:\n\tx2 = ");
  scanf("%d", &d2.x);
  printf("\ty2 = ");
  scanf("%d", &d2.y);

  for(float t = 0; t <= 1; t += 0.001) {
    int tmp_x = d1.x + t*(d2.x - d1.x);
    int tmp_y = d1.y + t*(d2.y - d1.y);

    image.set(tmp_x, tmp_y, white);
  }

  image.flip_vertically();

  image.write_tga_file("output.tga");
}

void line(dot d1, dot d1, TGAImage image) {
  for(float t = 0; t <= 1; t += 0.001) {
    int tmp_x = d1.x + t*(d2.x - d1.x);
    int tmp_y = d1.y + t*(d2.y - d1.y);

    image.set(tmp_x, tmp_y, white);
  }
}
