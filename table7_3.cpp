#include <cstdio>
#include <cmath>
#include "Daikei.hpp"
#include "Daikei2.hpp"
using namespace std;
#define FLOAT double


template <typename T>
struct Furenzoku {
  T operator ()(T x) {
    if (x < 1.0 / 3.0) {
      return 1.0;
    } else if (1.0 / 3.0 <= x && x < 1.0) {
      T tmp = x - 1.0 / 3.0;
      return 1.0 - 9.0 * tmp * tmp / 4.0;
    }
    return 0.0;
  }
};


int main()
{
  //p44 台形則による不連続点をもつ関数の計算
  const FLOAT I = 7.0 / 9.0;
  int N = 1;
  FLOAT x = Daikei<FLOAT, Furenzoku<FLOAT>>()(0.0, 1.0, N, Furenzoku<FLOAT>());
  printf("%2d %.7f (%.7f)\n", N, x, x - I);

  FLOAT x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei<FLOAT, Furenzoku<FLOAT>>()(0.0, 1.0, N, Furenzoku<FLOAT>());
    printf("%2d %.7f (%.7f)\n", N, x, x - I);
    x_old = x;
  }
  printf("\n");


  //リチャードソン補外(k=1)による不連続点をもつ関数の計算
  N = 2;
  x = Daikei2<FLOAT, 1, Furenzoku<FLOAT>>::call(0.0, 1.0, N, Furenzoku<FLOAT>());
  printf("%2d %.7f (%.7f)\n", N, x, x - I);

  x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei2<FLOAT, 1, Furenzoku<FLOAT>>::call(0.0, 1.0, N, Furenzoku<FLOAT>());
    printf("%2d %.7f (%.7f)\n", N, x, x - I);
    x_old = x;
  }
  printf("\n");


  //リチャードソン補外(k=2)による不連続点をもつ関数の計算
  N = 4;
  x = Daikei2<FLOAT, 2, Furenzoku<FLOAT>>::call(0.0, 1.0, N, Furenzoku<FLOAT>());
  printf("%2d %.7f (%.7f)\n", N, x, x - I);

  x_old = x;
  N *= 2;
  for (; N <= 32; N *= 2) {
    x = Daikei2<FLOAT, 2, Furenzoku<FLOAT>>::call(0.0, 1.0, N, Furenzoku<FLOAT>());
    printf("%2d %.7f (%.7f)\n", N, x, x - I);
    x_old = x;
  }

  return 0;
}