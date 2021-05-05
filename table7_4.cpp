#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include "Daikei.hpp"
#include "Daikei2.hpp"
using namespace std;
#define FLOAT double


int main()
{
  //p45 台形則による円周率の計算
  int N = 1;
  FLOAT x = Daikei<FLOAT, FLOAT(FLOAT)>()(0.0, 1.0, N, [](FLOAT y) { return 4 * sqrt(1 - y * y); });
  printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);

  FLOAT x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei<FLOAT, FLOAT(FLOAT)>()(0.0, 1.0, N, [](FLOAT y) { return 4 * sqrt(1 - y * y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);
    x_old = x;
  }
  printf("\n");


  //p45 リチャードソン補外(k=1)による円周率の計算
  N = 2;
  x = Daikei2<FLOAT, 1, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return 4 * sqrt(1 - y * y); });
  printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);

  x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei2<FLOAT, 1, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return 4 * sqrt(1 - y * y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);
    x_old = x;
  }
  printf("\n");

  //p45 リチャードソン補外(k=2)による円周率の計算
  N = 4;
  x = Daikei2<FLOAT, 2, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return 4 * sqrt(1 - y * y); });
  printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);

  x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei2<FLOAT, 2, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return 4 * sqrt(1 - y * y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - M_PI);
    x_old = x;
  }

  return 0;
}
