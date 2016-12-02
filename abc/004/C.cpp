#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    vector<int> v;
    for(int i = 1; i <= 6; i++)
        v.emplace_back(i);

    int N;
    cin >> N;
    N %= 30;
    for(int i = 0; i < N; i++) {
        swap(v[i%5], v[(i)%5+1]);
    }

    for(int i = 0; i < 6; i++) cout << v[i];

    cout << endl;
}

