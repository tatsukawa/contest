#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e3;

char A[512][512];
char tmp1[512], tmp2[512];
int N;
int ans = 27;

bool check() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

int dfs(int cnt) {
    if(cnt > ans) {
        return INF;
    }

    if(check()) {
        ans = cnt;
        return ans;
    } 

    int ret = INF;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            for(int k = 0; k < N; k++) {
                tmp1[k] = A[i][k];
                tmp2[k] = A[k][j];
                A[k][j] = A[i][k];
            }            
            ret = min(ret, dfs(cnt+1));
            for(int k = 0; k < N; k++) {
                A[i][k] = tmp1[k];
                A[k][j] = tmp2[k];
            }
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N;
    if(N > 3) {
        return 0;
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    bool f = true;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(A[i][j] == '#') f = false;
        }
    } 

    if(f) {
        cout << -1 << endl;
        return 0;
    }
    

    cout << dfs(0) << endl;
}