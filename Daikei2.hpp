#ifndef DAIKEI2_HPP_
#define DAIKEI2_HPP_

#include "Daikei.hpp"

// 台形則での計算にリチャードソンの補外(p42)を適用して積分値を計算する
template<typename T, int k, typename Func>
struct Daikei2
{
  static T call(T a, T b, int N, Func func)
  {
    int m = 1;
    for (int i = 0; i < k; i++) m *= 4;
    T ret = Daikei2<T, k - 1, Func>::call(a, b, N, func) - Daikei2<T, k - 1, Func>::call(a, b, N / 2, func) / m;
    ret /= (1 - static_cast<T>(1) / m);
    return ret;
  }
};

template<typename T, typename Func>
struct Daikei2<T, 1, Func>
{
  static T call(T a, T b, int N, Func func)
  {
    T ret = Daikei<T, Func>()(a, b, N, func) - Daikei<T, Func>()(a, b, N / 2, func) / 4;
    ret /= (1 - static_cast<T>(1) / 4);
    return ret;
  }
};

#endif
