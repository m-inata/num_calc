#ifndef DAIKEI_HPP_
#define DAIKEI_HPP_

// 台形則(p41)で計算する関数オブジェクト
template <typename T, typename Func>
struct Daikei {
    // 積分区間[a, b]をN等分した台形の和を計算する
    T operator ()(T a, T b, int N, Func func) {
        T ret = static_cast<T>(0);
        T h = (b - a) / N;
        ret += func(a) / 2 + func(b) / 2;
        for (int n = 1; n < N; n++) {
            ret += func(a + static_cast<T>(n) * h);
        }
        ret *= h;
        return ret;
    }
};

#endif
