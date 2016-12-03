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

int main() {
    ios::sync_with_stdio(false);

    int N, a;
    cin >> N;
    int k;
    vector<int> ans(N);
    for(int i = 0; i < N; i++) {
        cin >> a;
        switch(i) {
            case 0:
                k = 100000;
                break;
            case 1:
                k = 50000;
                break;
            case 2:
                k = 30000;
                break;
            case 3:
                k = 20000;
                break;
            case 4:
                k = 10000;
                break;
            default:
                k = 0;
                break;
        }

        ans[a-1] = k;
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << endl;
    }
}


