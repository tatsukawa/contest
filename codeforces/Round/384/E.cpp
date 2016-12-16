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


const int inf = 1e8;

int n;
vector<int> a;
vector<int> in[8];
int dp[1025][1025];

int can(int len) {
    vector<int> cur(8);
    rep(i,0,n+1) {
        rep(j,0,1<<9) {
            dp[i][j] = -inf;
        }
    }
    dp[0][0] = 0;
    rep(i,0,n) {
        rep(j,0,1<<8) {
            if(dp[i][j] == -inf) {
                continue;
            }
            rep(k,0,8) {
                if(j & (1 << k)) {
                    continue;
                }
                int it = cur[k] + len - 1;
                if(it >= in[k].size()) {
                    continue;
                }
                dp[in[k][it]+1][j|(1<<k)] = max(dp[in[k][it]+1][j|(1<<k)], dp[i][j]);
                it++;
                if(it >= in[k].size()) {
                    continue;
                }
                dp[in[k][it]+1][j|(1<<k)] = max(dp[in[k][it]+1][j|(1<<k)],dp[i][j]+1);
            }
        }
        cur[a[i]]++;
    }
    int ret = -inf;
    rep(i,0,n+1) {
        ret = max(ret, dp[i][(1<<8)-1]);
    }
    if(ret == -inf) {
        return -1;
    }

    return ret*(len+1)+(8-ret)*len;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a.resize(n); 
    rep(i,0,n) {
        cin >> a[i];
        a[i]--;
        in[a[i]].emplace_back(i);
    }
    int l = 0, r = n / 8;
    while(r-l > 1) {
        int m = (l+r) / 2;
        if(can(m) == -1) {
            r = m;
        } else {
            l = m;
        }
    }

    int ans = max(can(l), can(r));
    if(ans == -1) {
        ans = 0;
        rep(i,0,8) {
            if(in[i].size() != 0) {
                ans++;
            }
        }
    }

    cout << ans << endl;
}

