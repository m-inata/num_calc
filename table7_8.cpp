#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include "Daikei3.hpp"
using namespace std;
#define FLOAT double


int main()
{
    // p48 標準正規分布の関数を(-∞, ∞)で積分する計算。
    for (FLOAT h = 8.0; h > 0.499; h /= 2.0) {
        FLOAT x = Daikei3<FLOAT, FLOAT(FLOAT)>()(h, std::pow(10.0, -17), [](FLOAT x) { return std::exp(-x * x / 2.0); });
        x /= std::sqrt(2.0 * M_PI);
        printf("%.1f %.15f\n", h, x);
    }

    return 0;
}
