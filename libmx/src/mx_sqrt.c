#include "libmx.h"

int mx_sqrt(int x1) {
   unsigned int m, y, b, x, x2;
   if (x1 < 1)
      return 0;
   else
      x = (unsigned int) x1;
   x2 = x;
   m = 0x4000;
   y = 0;
   while (m != 0){
      b = y | m;
      y = y >> 1;
      if (x >= b) {
         x = x - b;
         y = y | m;
      }
      m = m >> 2;
   }
   if  (x2 == y * y)
      return y;
   else
      return 0;
}

// int mx_sqrt(int x) {
// 	if (x == INT_MAX) return 46340;

// 	for (int i = 0; i * i <= x; i++)
// 		if (i * i == x)
// 			return i;
// 	return 0;
// }
