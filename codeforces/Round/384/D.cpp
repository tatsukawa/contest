#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

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


const ll INF = 1e15;

const int MAXN = 200200;

vector<int> G[MAXN];
vector<ll> a;
vector<ll> sum;
vector<ll> mx;

ll dfs1(int v, int p) {
    sum[v] = a[v];
    for(auto u: G[v]) {
        if(p == u) continue;
        sum[v] += dfs1(u, v);
    }
    return sum[v];
}

ll dfs2(int v, int p) {
    mx[v] = sum[v];
    for(auto u: G[v]) {
        if(p == u) continue;
        mx[v] = max(mx[v], max(sum[v], dfs2(u, v)));
    }
    return mx[v];
}

ll dfs3(int v, int p) {
    vector<ll> w;
    ll ret = -INF;
    for(auto u: G[v]) {
        if(p == u) continue;
        w.emplace_back(mx[u]);
        ret = max(ret, dfs3(u, v));
    }
    sort(w.begin(), w.end(), greater<ll>());
    if(w.size() >= 2) {
        ret = max(ret, w[0]+w[1]);
    }
//    cout << v << ":";
//    cout << w << endl;
//    cout << ret << endl;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    a.resize(n);
    sum.resize(n);
    mx.resize(n);
    rep(i,0,n) {
        cin >> a[i];
    }
    int s, t;
    rep(i,0,n-1) {
        cin >> s >> t;
        s--; t--;
        G[s].emplace_back(t);
        G[t].emplace_back(s);
    }
    dfs1(0, -1);
    dfs2(0, -1);
//    cout << mx << endl;
//    cout << sum << endl;
    ll ans = dfs3(0, -1);
    if(ans == -INF) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }
}

