#define _USE_MATH_DEFINES
#include <cstdio>
#include <cmath>
#include "Daikei3.hpp"
using namespace std;
#define FLOAT double


// π * cosh(x) / ( cosh(π * sinh(x) / 2) )^3
template <typename T>
struct CalcPi2 {
    T operator ()(T x) {
        T a = M_PI * std::cosh(x);
        T b = std::sinh(x) * M_PI / 2.0;
        T c = std::cosh(b) * std::cosh(b) * std::cosh(b);
        return a / c;
    }
};


int main()
{
    // p50 二重指数変換でtable7_4の関数を積分する計算。
    for (FLOAT h = 2.0; h > 0.12499; h /= 2.0) {
        FLOAT x = Daikei3<FLOAT, CalcPi2<FLOAT>>()(h, std::pow(10.0, -17), CalcPi2<FLOAT>());
        printf("%.3f %.15f\n", h, x);
    }

    return 0;
}