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
    int n;
    long long l, r;
    cin >> n;
    for(int i = 0; i < n; i++) {
        long long bit = 1;
        long long ans = 0;
        cin >> l >> r;
        while(l <= r) {
            ans = max(ans, l);
            l |= bit;
            bit <<= 1;
        }
        cout << ans << endl;
    }
}

