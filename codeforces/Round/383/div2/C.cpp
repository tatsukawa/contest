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
using ll = int64_t; using P = pair<int, int>; 
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

int main() {
    ios::sync_with_stdio(false);
    int n, ans = 1;
    vector<int> crush;
    vector<bool> used;

    cin >> n;

    crush.resize(n);
    used.resize(n);

    rep(i, n) {
        cin >> crush[i];
        crush[i]--;
    }

    fill(used.begin(), used.end(), false);

    rep(i, n) {
        if(used[i]) {
            continue;
        }

        int cnt = 1;
        int j;
        used[i] = true;
        for(j = crush[i]; !used[j]; j = crush[j]) {
            used[j] = true;
            cnt++;
        }
        if(j != i) {
            cout << -1 << endl;
            return 0;
        }
        if(cnt % 2 == 0) {
            cnt /= 2;
        }
        ans = ans*cnt/__gcd(ans, cnt); 
    }

    cout << ans << endl;
}

