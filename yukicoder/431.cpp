#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;



int main() {
    ios::sync_with_stdio(false);

    int D1, D2, D3, S;
    cin >> D1 >> D2 >> D3 >> S;

    int s = D1 + D2 + D3;

    if(S == 1) {
        cout << "SURVIVED" << endl;
    } else {
        if(s >= 2) {
            cout << "DEAD" << endl;
        } else {
            cout << "SURVIVED" << endl;
        }
    }
}

