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
const ll MOD = 1000000007;

string s;
int K;
int indexing;
vector<int> G[3000];
ll dp[3030][3030];

void construct(int l, int r, int p) {
    if(l >= r) {
        return;
    }
    int cur = 0;
    int prev = l;
    for(int i = l; i <= r; i++) {
        if(s[i] == '(') {
            cur++;
        } else {
            cur--;
        }

//        printf("%d:%d:%c\n", p, cur, s[i]);

        if(cur == 0) {
            ++indexing;
            int d = indexing; 
            G[p].emplace_back(d); 
            construct(prev+1, i-1, d); 
            prev = i+1;
        }
    }
}

void check(int i, string s) {
    cout << s << i << endl;
    for(int j = 0; j < G[i].size(); j++) {
        check(G[i][j], s+"  ");
    }
}

const int R[] = {1, 0, 1, 2};
const int B[] = {1, 2, 1, 0};

// i:root, r:count_red
ll solve(int i, int r, int b) {
    if(G[i].size() == 0) {
        return (abs(r-b) <= K);
    }

    if(dp[i][r] >= 0)
        return dp[i][r];

    ll res = 1LL;

    for(int j = 0; j < G[i].size(); j++) {
        ll sum = 0;
        for(int k = 0; k < 4; k++) {
            sum += solve(G[i][j], r+R[k], b+B[k]);
            sum %= MOD;
        }
//        printf("root:%d, %d, r:%d, b:%d\n", i, sum, r, b);
        res *= sum;
        res %= MOD;
    }

    return dp[i][r] = res;
}

int main() {
    ios::sync_with_stdio(false);

    cin >> s;
    cin >> K;

    construct(0, s.size(), 0);
        check(0, "");
    memset(dp, -1, sizeof dp);
    cout << solve(0, 0, 0) << endl;
}


