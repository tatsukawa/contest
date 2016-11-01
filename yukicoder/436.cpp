#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    int w = 0;
    cin >> s;
    int N = s.size();
    for(auto c : s) {
        w += (c == 'w');
    }

    cout << min(w, N - w - 1) << endl;
}
