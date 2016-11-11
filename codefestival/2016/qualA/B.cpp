#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>

using namespace std;

typedef long long ll;
const int INF = 1e8;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    vector<bool> used(N, false);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
        a[i]--;
    }
    int ans = 0;

    for(int i = 0; i < N; i++) {
        if(used[i]) continue;
        if(i == a[a[i]]) {
            ans++;
            used[i] = true;
            used[a[i]] = true;
        }
    }

    cout << ans << endl;
}
