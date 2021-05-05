#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include "Daikei.hpp"
#include "Daikei2.hpp"
using namespace std;
#define FLOAT double


int main()
{
  //p43 台形則による円周率の計算
  int N = 2;
  FLOAT x = Daikei<FLOAT, FLOAT(FLOAT)>()(-1.0, 1.0, N, [](FLOAT y) { return 2 / (1 + y * y); });
  printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);

  FLOAT x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei<FLOAT, FLOAT(FLOAT)>()(-1.0, 1.0, N, [](FLOAT y) { return 2 / (1 + y * y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);
    x_old = x;
  }
  printf("\n");


  //p43 リチャードソン補外(k=1)による円周率の計算
  N = 4;
  x = Daikei2<FLOAT, 1, FLOAT(FLOAT)>::call(-1.0, 1.0, N, [](FLOAT x) { return 2 / (1 + x * x);});
  printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);

  x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei2<FLOAT, 1, FLOAT(FLOAT)>::call(-1.0, 1.0, N, [](FLOAT x) { return 2 / (1 + x * x);});
    printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);
    x_old = x;
  }

  return 0;
}
