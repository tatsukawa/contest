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
int N, X, Y = INF;
vector<P> v;

vector<int> T, A;
vector<ll> g[100011];
bool solve(int x) {
    for(int i = 0; i < x; i++) {
        g[i].clear();
    }
    for(int i = 0; i < N; i++) {
        g[min(x, T[i]) - 1].emplace_back(A[i]);
    }

    ll sum = 0;
    priority_queue<ll> q;
    for(int i = x-1; i >= 0; i--) {
        for(ll d: g[i]) {
            q.push(d);
        }
        if(q.size()) {
            sum += q.top();
            q.pop();
        }
    }

    return X <= sum;
}


int main() {
    ios::sync_with_stdio(false);
    int t, a;
    cin >> N >> X;
    for(int i = 0; i < N; i++) {
        cin >> t;
        T.emplace_back(t);
    }
    for(int i = 0; i < N; i++) {
        cin >> a;
        A.emplace_back(a);
    }

    int l = 0, r = 100001;
    while(l+1 < r) {
        int c = (l + r) / 2;
        if(solve(c)) {
            r = c;
        } else {
            l = c;
        }
    }

    if(r >= 100001) {
        r = -1;
    }
    cout << r << endl;
}


