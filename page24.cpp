#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
using namespace std;
#define FLOAT double


template <typename T>
inline T f2(T x) {
  return 4 * sqrt(1 - x * x);
}


template <typename T, typename Func>
T daikei(int N, Func func)
{
  T ret = static_cast<T>(0);
  ret += func(0) / 2 + func(1) / 2;
  for (int n = 1; n < N; n++) {
    ret += func(static_cast<T>(n) / N);
  }
  ret /= N;
  return ret;
}


int main()
{
  //--p24----------------------------
  int N = 1;
  // xは台形則による計算値
  FLOAT x = daikei<FLOAT>(N, f2<FLOAT>);
  printf("%2d %.6f ( %.6f )\n", N, x, x - M_PI);
  FLOAT x_old = x;
  N *= 2;
  
  for (; N <= 32; N *= 2) {
    x = daikei<FLOAT>(N, f2<FLOAT>);
    printf("%2d %.6f ( %.6f ) %.6f\n", N, x, x - M_PI, x_old - x);
    x_old = x;
  }
  
  return 0;
}
