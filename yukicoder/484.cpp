/*
    dp[dir][l][r] := dir = 0 なら[l, r]が未収穫でかつ、[l, r]の左のセルを、dir = 1なら右のセルの木の実の収穫を行った時の最短時間
*/

#include <bits/stdc++.h>

using namespace std;

const int64_t INF = 1e16;

int64_t dp[2][2048][2048];
int N;
vector<int64_t> A;

// [l, r]
int64_t solve(bool d, int l, int r) {
    if(dp[d][l][r] >= 0) {
        return dp[d][l][r];
    }

    int64_t ret = INF;
    int64_t dist = r - l + 1;

    if(d) {
        if(l-1 >= 0) ret = min(ret, solve(false, l-1, r) + dist);
        if(r+1 < N) ret = min(ret, solve(true, l, r+1) + 1);
        ret = max(ret, A[r]);
    } else {
        if(l-1 >= 0) ret = min(ret, solve(false, l-1, r) + 1);
        if(r+1 < N) ret = min(ret, solve(true, l, r+1) + dist);
        ret = max(ret, A[l]);
    }

    return dp[d][l][r] = ret;
}

int main() {
    cin >> N;
    int64_t a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        A.emplace_back(a);
    }

    memset(dp, -1, sizeof(dp));

    dp[0][1][N-1] = A[0];
    dp[1][0][N-2] = A[N-1];

    int64_t ans = INF;

    for(int i = 0; i < N; i++) {
        ans = min(ans, solve(false, i, i));
        ans = min(ans, solve(true, i, i));
    }

    cout << ans << endl;
}
