#include <iostream>
using namespace std;

int main()
{
    double x;
    cin >> x;

    double l = 0, r = x;

    while (r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= x) r = mid;
        else l = mid;
    }

    printf("%lf\n", l);
    return 0;
}