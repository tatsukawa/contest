#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

using namespace std;
using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);

    int M;
    const ll x = 2017;
    cin >> M;

    ll ans = 1;

    for(int i = 0; i < 2*x; i++) {
        ans *= x;
        ans %= M;
    }

    cout << (ans + x) % M << endl;
}

