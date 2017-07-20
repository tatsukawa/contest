#include <bits/stdc++.h>

using namespace std;

int main() {
    int A, B;
    cin >> A >> B;
    string ans = (((A+B) % 3 == 0 or A % 3 == 0 or B % 3 == 0) ? "Possible" : "Impossible");
    cout << ans << endl;
}