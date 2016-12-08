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

int main() {
    ios::sync_with_stdio(false);

    vector<int> a;
    vector<int> v;
    int N, T;
    cin >> N >> T;
    a.resize(N);
    rep(i, N) {
        cin >> a[i];
    }
    int m = a[0];
    int ans = 0;
    int x = 0;
    for(int i = 1; i < N; i++) {
        if(a[i] < m) {
            m = a[i];
        } else if(a[i]-m > x) {
            ans = 1;
            x = a[i]-m;
        } else if(a[i]-m == x) {
            ans++;
        }
    }

    cout << ans << endl;
}

