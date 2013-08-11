#include <string>

using namespace std;

class CircleOrder {
    int n;

public:
    string firstOrder(string circle) {
        n = circle.size();
        string ans = "";

        while(true) {
            char minc = 'z' + 1;
            int idx = -1;

            for(int i = 0; i < n; i++) {
                if(isUpper(circle[i]) && ok(circle, i)) {
                    if(minc > circle[i]) {
                        minc = circle[i];
                        idx = i;
                    }
                }
            }

            if(idx == -1) break;

            circle[idx] = '#';
            ans += minc - 'A' + 'a';

            for(int i = 0; i < n; i++) {
                if(circle[i] == minc - 'A' + 'a') {
                    circle[i] = '.';
                }
            }
        }

        return (ans.size() == n / 2 ? ans : "NONE");
    }

    bool ok(string &s, int idx) {
        char judge = s[idx] - 'A' + 'a';

        // left
        for(int i = idx - 1; ; i--) {
            if(i < 0) i += n;

            if(judge == s[i]) return true;
            else if(s[i] == '#' || isLower(s[i])) break;
        }

        // right
        for(int i = idx + 1; ; i++) {
            i %= n;

            if(judge == s[i]) return true;
            else if(s[i] == '#' || isLower(s[i])) break;
        }

        return false;
    }

    bool isUpper(char c) {
        return 'A' <= c && c <= 'Z';
    }

    bool isLower(char c) {
        return 'a' <= c && c <= 'z';
    }
};
