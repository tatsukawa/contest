#include <bits/stdc++.h>

#define REP(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define ALL(v) ((v).begin(), (v).end())

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    ll T, A;
    ll nx = 1LL, ny = 1LL;
    int k = 0;
    for(int i = 0; i < N; i++) {
        cin >> T >> A;
        ll m = max(((nx / T) + (nx % T ? 1LL : 0)), (ny / A) + (ny % A ? 1LL : 0));
        nx = T*m;
        ny = A*m;
    }    

    cout << nx + ny << endl;
       
}

