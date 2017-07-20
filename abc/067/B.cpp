#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> l;
    l.assign(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> l[i];
    }

    sort(l.begin(), l.end());
    int ans = 0;
    for(int i = N-1; i >= N-K; i--) {
        ans += l[i];
    }

    cout << ans << endl;
}