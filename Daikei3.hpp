#ifndef DAIKEI3_HPP_
#define DAIKEI3_HPP_


// 刻み幅hの台形則で計算する。
// Tがfloatならepsironは10^-7から10^-8くらい、
// Tがdoubleならepsironは10^-17から10^-18くらいにする。
template <typename T, typename Func>
struct Daikei3 {
  T operator ()(T h, T epsiron, Func func) {
    T ret = func(0);
    for (int n = 1; ; n++) {
        T a = func(n * h);
        T b = func(-n * h);
        bool finish_a = std::abs(a) < epsiron * std::abs(ret);
        bool finish_b = std::abs(b) < epsiron * std::abs(ret);
        if (!finish_a) {
            ret += a;
        }
        if (!finish_b) {
            ret += b;
        }
        if (finish_a && finish_b)
            break;
    }
    ret *= h;
    return ret;
  }
};

#endif
