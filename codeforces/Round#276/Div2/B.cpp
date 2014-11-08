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
    int N;
    cin >> N;
    vector<long long> x(N), y(N);
    for(int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    long long l = max(x[N-1] - x[0], y[N-1] - y[0]);

    cout << l * l << endl;
}

