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


const ll INF = 1e14;
ll A, B, C;
string T;
ll dp[16][5000][4];
int mask;
int S;
// 数値を２進数文字列に変換
std::string to_binString(unsigned int val)
{
    if( !val )
        return std::string("0");
    std::string str;
    while( val != 0 ) {
        if( (val & 1) == 0 )  // val は偶数か？
            str.insert(str.begin(), '0');  //  偶数の場合
        else
            str.insert(str.begin(), '1');  //  奇数の場合
        val >>= 1;
    }
    return str;
}

bool compare(int a, int b) {
    for(int i = 0; i < T.size(); i++) {
        if(((a >> i) & 1) != ((b >> i) & 1)) {
            return false;
        }
    }

    return true;
}

ll solve(int x, int s, bool flag) {
    if(x > T.size()) {
        return INF;
    }

    if(x == T.size()) {
        if(compare(s, S)) {
            return 0;
        }

        if(compare((~s) & mask, S)) {
            return C;
        }

        return INF;
    }

    if(dp[x][s][flag] >= 0) {
        return dp[x][s][flag]; 
    }

    ll res = INF;
    res = min(res, solve(x+1, ((s|(1<<(x))) & mask), false)+B);
    res = min(res, solve(x+1, ((s<<1) & mask), false)+A);
    if(!flag) res = min(res, solve(x, ((~s) & mask), true)+C);

    return dp[x][s][flag] = res;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> A >> B >> C;
    cin >> T;
    for(int i = 0; i < T.size(); i++) {
        if(T[i] == '1') {
            S |= (1 << i);
        }
    }

    for(int i = 0; i < T.size(); i++) {
        mask |= (1 << i);
    }

    memset(dp, -1, sizeof dp);

    ll ans = solve(0, 0, true);
    if(ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << solve(0, 0, true) << endl;
    }

}

