#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

using namespace std;
using ll = int64_t;

int main() {
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int index = 0;
    while(index+2 < s.size()) {
        char c = s[index];
        bool f = (c == s[index+1] and c == s[index+2]);
        if(f) {
            if(c == 'X') {
                cout << "West" << endl;
            } else {
                cout << "East" << endl;
            }
            return 0;
        }
        index++;
    }

    cout << "NA" << endl;
}