#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);

    double E, D;

    while(cin >> D >> E) {
        if(D == 0 and E == 0) break;

        double ans = INF;
        for(double x = 0; x < D; x++) {
            double y = D - x;
            ans = min(ans, fabs(sqrt(x*x + y*y) - E));
        }
        printf("%.10lf\n", ans);
    }
}

