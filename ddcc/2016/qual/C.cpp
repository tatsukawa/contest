#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);

    ll N, K;
    cin >> N >> K;
    
    vector<ll> A(N);
    map<ll, ll> cnt;
    ll ans = 0;
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] = __gcd(A[i], K);
        cnt[A[i]]++;
    }

    for(auto i : cnt) {
        for(auto j : cnt) {
            if((i.first * j.first) % K == 0) {
                ans += i.second * j.second;
            }
        }
        if(i.first * i.first % K == 0) 
            ans -= i.second;
    }

    cout << ans / 2 << endl;
}

