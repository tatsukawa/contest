#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);

	random_device rd;

	mt19937 mt(rd());

	uniform_int_distribution<int> dice(10000000,1000000000);

    for(int i = 0; i < 100; i++) {
        cout << dice(mt) << endl;
    }
}

