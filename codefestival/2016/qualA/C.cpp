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
    string s;
    ll K;
    cin >> s >> K;

    for(int i = 0; i < s.size() - 1; i++) {
        ll diff = (int)('z' - s[i] + 1);
        if(s[i] == 'a') continue;
        if(K < diff) {
            continue;
        }
        K -= diff;
        s[i] = 'a';
    }

    int n = s.size();
    K %= 26;
    for(int i = 0; i < K; i++) {
        s[n-1]++;
        if(s[n-1] == (char)('z'+1)) {
            s[n-1] = 'a';
        }
    }

    cout << s << endl;
}
