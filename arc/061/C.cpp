#include <iostream>

using namespace std;

int main() {
    string s;
    long long sum = 0;
    cin >> s;
    int n = s.size();

    for(int i = 0; i < (1 << (n - 1)); i++) {
        long long tmp = (s[0] - '0');
        long long tmp2 = 0;
        for(int j = 1; j < n; j++) {
            if((i >> (j-1)) & 1) {
                tmp2 += tmp;
                tmp = (s[j] - '0');
            } else {
                tmp *= 10;
                tmp += (s[j] - '0');
            }
        }
        tmp2 += tmp;
        sum += tmp2;
    }

    cout << sum << endl;
}
