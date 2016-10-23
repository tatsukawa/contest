#include <bits/stdc++.h>

using namespace std;
using ll = int64_t;
using P = std::pair<int, int>;

const int INF = 1e8;

int main() {
    ios::sync_with_stdio(false);
    string t;
    cin >> t;

    for(int i = 0; i < t.size(); i++) {
        for(int j = i + 1; j < t.size(); j++) {
            if(t[i] == 'C' and t[j] == 'F') {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}

