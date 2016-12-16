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
int n, a, b;
string s;
bool used[100101];

int solve(int x) {
    if(used[x]) return INF;
    if(s[x] == s[b]) {
        return 0;
    }
    used[x] = true;
    int res = INF;
    if(x+1 < n) res = min(res, solve(x+1) + (s[x] != s[x+1] ? 1 : 0));
    if(x-1 >=0) res = min(res, solve(x-1) + (s[x] != s[x-1] ? 1 : 0));

    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> a >> b;
    a--; b--;
    cin >> s;
    cout << solve(a) << endl;
}

