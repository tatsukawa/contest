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
    string s = "";
    for(int i = 0; i < 12; i++) {
        char c;
        cin >> c;
        if(i == 4) {
            s += " ";
        }
        s += c;
    }
    cout << s << endl;
}
