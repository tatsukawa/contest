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

const int INF = 1e8;

struct disjoint_set {
    int size;
    vector<int> par;
    vector<int> rank;

    disjoint_set(int n) : size(n) {
        for(int i = 0; i < n; i++) {
            par.emplace_back(i);
            rank.emplace_back(0);
        }
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y) return;

        if(rank[x] < rank[y]) par[x] = y;
        else {
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
        }
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
    
    int root(int x) {
        return (par[x] == x ? x : par[x] = root(par[x]));
    }
};


int main() {
    ios::sync_with_stdio(false);
    
    int N, K, L, s, t;
    cin >> N >> K >> L;
    auto a = disjoint_set(N);
    auto b = disjoint_set(N);
    rep(i, 0, K) {
        cin >> s >> t;
        s--, t--;
        a.unite(s, t);
    }

    rep(i, 0, L) {
        cin >> s >> t;
        s--, t--;
        b.unite(s, t);
    }

    map<pair<int, int>, int> memo;

    rep(i, 0, N) {
        memo[make_pair(a.root(i), b.root(i))]++;
    }

    cout << memo[make_pair(a.root(0), b.root(0))];

    rep(i, 1, N) {
        cout << ' ' << memo[make_pair(a.root(i), b.root(i))];
    }

    cout << endl;
}

