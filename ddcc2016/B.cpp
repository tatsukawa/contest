#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);

    double R, N, M;
    cin >> R >> N >> M;

    double dx = (2.0*R) / N;
    double d = R-dx;
    double x, y;
    double ans = 0;
    for(int i = 0; i < N+M-1; i++) {
        if(i <= N) {
            x = sqrt(R*R - d*d);
        } else {
            x = 0;
        }

        if(i >= M) {
            y = sqrt(R*R - (d+M*dx)*(d+M*dx));
        } else {
            y = 0;
        }

        d -= dx;
        ans += max(2*y, 2*x);
    }

    printf("%.8f\n", ans);
}

