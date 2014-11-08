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
    int a, m;
    cin >> a >> m;

    for(int i = 0; i < 100000; i++) {
        a = (a + a) % m;
    }

    cout << (a ? "No" : "Yes") << endl;
}

