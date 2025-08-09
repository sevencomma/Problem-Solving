#include <bits/stdc++.h>
using namespace std;

double x, y, c;

double func(double w) {
    return 1.0 / sqrt(x * x - w * w) + 1.0 / sqrt(y * y - w * w) - 1.0 / c;
}

double ladder_width() {
    const double eps = 1e-9;
    double low = 0;
    double high = min(x, y) - eps;
    double mid;

    for (int i = 0; i < 100; i++) {
        mid = (low + high) / 2.0;
        double ret = func(mid);
        if (ret > 0) {
            high = mid;
        }
        else {
            low = mid;
        }
    }
    return mid;
}

int main() {
    cin >> x >> y >> c;
    double w = ladder_width();
    printf("%.3f\n", w);
    return 0;
}
