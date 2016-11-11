#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <numeric>

using namespace std;

class PrimePalindromic {
public:
    int count(int A, int B) {
        int ans = 0;

        for(int i = A, n; i <= B && (n = i); i++) {
            vector<string> vs;
            for(int d = 2; d <= n && n != 1; d++) {
                if(!(n % d)) {
                    vs.push_back(toStr(d));
                    n /= d;
                    d = 1;
                }
            }

            sort(vs.begin(), vs.end());

            do {
                string s = accumulate(vs.begin(), vs.end(), string(""));
                if(isPalindromic(s)) {
                    ans++;
                    break;
                }
            } while(next_permutation(vs.begin(), vs.end()));
        }

        return ans;
    }

    string toStr(int n) {
        stringstream ss;
        ss << n;
        return ss.str();
    }

    bool isPalindromic(string s) {
        int n = s.size();
        for(int i = 0; i < n / 2; i++) if(s[i] != s[n - i - 1]) return false;
        return true;
    }
};
