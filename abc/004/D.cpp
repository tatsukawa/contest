#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int R, G, B, S;

int dp[2020][2020];

int f(int x, int S) {

    if(dp[x][S] >= 0) return dp[x][S];

    if(S == 0) {
        return 0;
    }

    if(x == 2000) return INF;
    if(2000-x < S) return INF;

    int res = INF;

    if(R > 0) {
        R--;
        res = min(res, f(x+1, S-1) + abs(900-x));
        R++;
        res = min(res, f(x+1, S));
    } else if(G > 0) {
        G--;
        res = min(res, f(x+1, S-1) + abs(1000-x));
        G++;
        res = min(res, f(x+1, S));
    } else {
        B--;
        res = min(res, f(x+1, S-1) + abs(1100-x));
        B++;
        res = min(res, f(x+1, S));
    }

    return dp[x][S] = res;
}

int main() {
    ios::sync_with_stdio(false);

    memset(dp, -1, sizeof dp);
    cin >> R >> G >> B;
    cout << f(0, R+G+B) << endl;

}

