#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i,n) for(int (i) = 0; (i) < (n); (i)++)

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

ll dp[1024][1024];

int main() {
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    rep(i, K) dp[0][i] = 1;

    for(int i = 1; i < N; i++) {
        rep(j, K) {
            rep(k, K) {
                if(j == k) continue;
                dp[i][j] += dp[i-1][k];
            }
        }
    }

    ll ans = 0;

    rep(i, K) ans += dp[N-1][i];

    cout << ans << endl;
}

