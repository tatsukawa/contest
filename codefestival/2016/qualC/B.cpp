#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    int K, T;
    cin >> K >> T;
    vector<int> a(T);
    for(int i = 0; i < T; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end(), greater<int>());
    int sum = 0;
    for(int i = 1; i < T; i++) {
        sum += a[i];
    }

    int d = a[0] - sum - 1;

    if(d >= 0) {
        cout << d << endl;
    } else {
        cout << 0 << endl;
    }
}

