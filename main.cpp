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

#ifndef DEBUG
#define PRINTF() printf()

#else 
#define PRINTF() ;

#endif


void line(dot d1, dot d2, TGAImage &image, TGAColor color);

int main() {
  int height = 100;
  int width = 100;

  // printf("Enter height of image:\n");
  // scanf("%d", &height);

  // printf("\nEnter width of image:\n");
  // scanf("%d", &width);

  TGAImage image(height, width, TGAImage::RGB);

  dot d1;
  dot d2;

  // int trying = 0;

  /* do {
    if (trying == 2) {
      printf("Wrong coordinates!\n\n");
      return -1;
    } else trying++;

    printf("\nEnter first dot coordinates:\nx1 = ");
    scanf("%d", &d1.x);
    printf("y1 = ");
    scanf("%d", &d1.y);
  } while (d1.x > width || d1.y > height || trying == 3);

  trying = 0;

  do {
    if (trying == 2) {
      printf("Wrong coordinates!\n\n");
      return -1;
    } else trying ++;

    printf("\nEnter second dot coordinates:\nx2 = ");
    scanf("%d", &d2.x);
    printf("y2 = ");
    scanf("%d", &d2.y);
  } while (d2.x > width || d2.y > height || trying == 3);
  */
  //line({  0, 0  }, {0,   100}, image, green);
  line({  0, 100}, {100, 100}, image, green);
  line({100, 100}, {100, 0  }, image, green);
  line({100, 0  }, {0,   0  }, image, green);

  image.flip_vertically();

  image.write_tga_file("output.tga");
}

void line(dot d1, dot d2, TGAImage &image, TGAColor color) {
  int deltax = abs(d2.x - d1.x);
  int deltay = abs(d2.y - d1.y);
 
  int x  = d1.x;
  int y  = d1.y;
  int x1 = d2.x;

  int dirx = (d2.x - d1.x)? 1 : -1;
  int diry = (d2.y - d1.y)? 1 : -1;

  if (deltay > deltax) {
    std::swap(deltax, deltay);
    std::swap(x     , y     );
    std::swap(dirx  , diry  );
    
    x1 = d2.y;
  }

  int deltaerr = deltay; 
  int error = 0;

  for (; x <= x1; x++) {
    if (x1 == d2.x) image.set(x, y, color);
    else            image.set(y, x, color);

    error += deltaerr;

    if (2*error >= deltax) {
      y += diry;
      error -= deltax;
    }
  }
}

