#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
using namespace std;
#define FLOAT double


template <typename T>
inline T f(T x) {
  return static_cast<T>(1) / (1 + x);
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
  //--p22--------------------------
  // 真の値
  const FLOAT ln2 = log(2.0);
  
  int N = 1;
  // xは台形則による計算値
  FLOAT x = daikei<FLOAT>(N, f<FLOAT>);
  printf("%2d %.6f ( %.6f )\n", N, x, x - ln2);
  FLOAT x_old = x;
  N *= 2;
  
  for (; N <= 32; N *= 2) {
    x = daikei<FLOAT>(N, f<FLOAT>);
    printf("%2d %.6f ( %.6f ) %.6f\n", N, x, x - ln2, x_old - x);
    x_old = x;
  }
  printf("\n");
  
  return 0;
}
