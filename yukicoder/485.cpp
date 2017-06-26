#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

using namespace std;
using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    if(b % a == 0) {
        cout << b / a << endl;
    } else {
        cout << "NO" << endl;
    }
}