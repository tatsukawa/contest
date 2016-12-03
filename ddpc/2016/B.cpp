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
        os << " " << v[i];
    os << " ]";
    return os;
}


const int INF = 1e8;

int dp[101001];
int N, X, Y = INF;
vector<P> v;

int solve(int x, int s, int S) {
    if(Y <= s) {
        return INF;
    }
    if(S >= X) {
        Y = s;
        return s;
    }

    if(x == N) {
        return INF;
    }

    int res = INF;
    res = min(res, solve(x+1, s, S));
    if(s+1 <= v[x].first) {
        res = min(res, solve(x+1, s+1, S+v[x].second));
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> N >> X;
    vector<int> T(N), A(N);
    for(int i = 0; i < N; i++) {
        cin >> T[i];
    }
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        v.emplace_back(make_pair(T[i], A[i]));
    }

    sort(ALL(v));
    //for(auto x:v) {
    //   cout << x.first << ' ' << x.second << endl;
    //}

    memset(dp, -1, sizeof dp);
    int ans = solve(0, 0, 0);
    if(ans == INF) {
        cout << -1 << endl;
    } else {
        cout << ans  << endl;
    }
}


