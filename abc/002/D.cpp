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

bool G[16][16];

int main() {
    ios::sync_with_stdio(false);
    int x, y;
    int N, M;
    cin >> N >> M;
    rep(i,0,M) {
        cin >> x >> y;
        x--, y--;
        G[x][y] = G[y][x] = true;
    }
    int ans = 0;
    rep(i,0,(1<<N)) {
        bool ok = true;
        rep(j,0,N) {
            rep(k,0,N) {
                if(j == k) continue;
                if(((i>>j)&1) and ((i>>k)&1)) {
                     if(!G[j][k] or !G[k][j]) {
                         ok = false;
                     }
                }
            }
        }
        if(ok) {
            ans = max(ans, __builtin_popcount(i));
        }
    }
    cout << ans << endl;
}

