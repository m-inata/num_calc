#include <cstdio>
#include <cmath>
#include "Daikei.hpp"
#include "Daikei2.hpp"
using namespace std;
#define FLOAT double

int main()
{
    //--p42--------------------------
    const double E = std::exp(1.0);
    const double I = E - 1;

    //台形則によるexp(1.0)-1の計算
    int N = 1;
    FLOAT x = Daikei<FLOAT, FLOAT(FLOAT)>()(0.0, 1.0, N, [](FLOAT y) { return std::exp(y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - I);

    FLOAT x_old = x;
    N *= 2;
    for (; N <= 16; N *= 2)
    {
        x = Daikei<FLOAT, FLOAT(FLOAT)>()(0.0, 1.0, N, [](FLOAT y) { return std::exp(y); });
        printf("%2d %.7f (%.7f)\n", N, x, x - I);
        x_old = x;
    }
    printf("\n");

    //リチャードソン補外(k=1)によるexp(1.0)-1の計算
    N = 2;
    x = Daikei2<FLOAT, 1, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return std::exp(y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - I);

    x_old = x;
    N *= 2;
    for (; N <= 16; N *= 2)
    {
        x = Daikei2<FLOAT, 1, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return std::exp(y); });
        printf("%2d %.7f (%.7f)\n", N, x, x - I);
        x_old = x;
    }
    printf("\n");

    //リチャードソン補外(k=2)によるexp(1.0)-1の計算
    N = 4;
    x = Daikei2<FLOAT, 2, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return std::exp(y); });
    printf("%2d %.7f (%.7f)\n", N, x, x - I);

    x_old = x;
    N *= 2;
    for (; N <= 16; N *= 2)
    {
        x = Daikei2<FLOAT, 2, FLOAT(FLOAT)>::call(0.0, 1.0, N, [](FLOAT y) { return std::exp(y); });
        printf("%2d %.7f (%.7f)\n", N, x, x - I);
        x_old = x;
    }

    return 0;
}