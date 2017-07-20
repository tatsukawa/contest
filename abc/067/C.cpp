#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long> a(N+1, 0);
    long long b;
    for(int i = 1; i <= N; i++) {
        cin >> b;
        a[i] = b + a[i-1];
    }

    long long ans = LLONG_MAX;

    for(int i = 1; i < N; i++) {
        long long x = a[i];
        long long y = a[N] - a[i];
        ans = min(ans, abs(x-y));
    }

    cout << ans << endl;
} 