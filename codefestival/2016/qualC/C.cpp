#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;
const ll MOD = 1e9+7LL;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> T(N);
    vector<ll> A(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    ll cnt = 1LL;
    if(A[0] != T[N-1]) {
        cnt = 0;
    }
    
    if(N == 2) {
        // 1 5
        if(T[0] != T[1]) {
            // 5 2
            if(T[1] > A[1]) {
                cnt = 0LL;
            }
        }

        if(A[0] != A[1]) {
            if(A[0] > T[0]) {
                cnt = 0LL;
            }
        }
    }


    for(int i = 1; i < N - 1; i++) {
        if(T[i-1] != T[i]) {
            if(T[i] > A[i]) {
                cnt = 0LL;
            }
        } else {
            // 余白あり
            if(A[i] == A[i+1]) {
                cnt *= min(T[i], A[i]) - 1LL + 1LL;
                cnt %= MOD;
            }
        }

        if(A[i] != A[i+1]) {
            if(T[i] < A[i]) {
                cnt = 0LL;
            }
        }
    }

    cout << cnt % MOD << endl;
}

