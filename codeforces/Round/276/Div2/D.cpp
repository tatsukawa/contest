#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <numeric>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    int n, ans = 0;
    scanf("%d", &n);
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();

    for(int i = 0; i < n; i++) {
        int tmp = a[i] * 2;
        while(tmp <= a[n-1]) {
            int p = lower_bound(a.begin(), a.end(), tmp) - a.begin();
            if(p > 0) ans = max(ans, a[p-1] % a[i]);
            tmp += a[i];
        }
        ans = max(ans, a[n-1] % a[i]);
    }

    cout << ans << endl;
}

