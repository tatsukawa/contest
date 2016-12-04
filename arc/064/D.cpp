#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl

#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort((x).begin(), (x).end())
#define REVERSE(x) reverse( (x).begin(),(x).end())
#define UNIQUE(x) (x).erase(unique(ALL((x))), (x).end())
#define PW(x) (1LL<<(x))

using namespace std;
using ll = int64_t;
using P = pair<int, int>;

template<class T,class U>
ostream& operator<<(ostream &os, const pair<T, U> &p) {
    os << get_variable_name(p) << " = (" << p.first <<", " << p.second << ")";
    return os;
}

template<class T>
ostream& operator <<(ostream& os, const vector<T> &v){
    cout << get_variable_name(v) << " = [";
    for(auto i : v) 
        os << " " << i; 
    os << " ]";
    return os;
}


const int INF = 1e8;

const ll MOD = 1e9+7LL;

ll num[10000];

// 5 5
// 101
//  5 * (5 * 5) * (5 * 5)

template<typename T>
T xpow(T x, T n, T M) {
    T ret = 1;
    T val = x;
    for(; n != 0; n >>= 1) {
        if(n & 1) {
            ret *= val;
            ret %= M;
        }
        val *= val;
        val %= M;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    ll N, K;

    cin >> N >> K;

    vector<ll> divs;

    for(ll i = 1; i*i <= N; i++) {
        if(N % i == 0) {
            divs.emplace_back(i);
            if(i*i < N) divs.emplace_back(N/i); 
        }
    }

    sort(ALL(divs));

    ll ans = 0;

    // d:cyclic
    for(int i = 0; i < divs.size(); i++) {
        ll d = divs[i];
        ll val = xpow<ll>(K, (d+1)/2, MOD);
        for(int j = 0; j < i; j++) {
            if(divs[i] % divs[j] == 0) {
                val = (val - num[j] + MOD) % MOD;
            }
        }
        num[i] = val;
        if(d & 1) { // odd
            ans += num[i] * d;
        } else { // even
            ans += num[i] * d / 2;
        }
        ans %= MOD;
    }

    cout << ans << endl;

}
