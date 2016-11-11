#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int INF = 1 << 30;

class CorrectingParenthesization {
    int dp[52][52];
public:
    int getMinErrors(string s) {
        memset(dp, -1, sizeof dp);
        return dfs(s, 0, s.size() - 1);
    }

    int dfs(string& str, int s, int e) {
        if(dp[s][e] >= 0) return dp[s][e];
        if(s + 1 == e) return judge(str[s], str[e]);

        int ret = dfs(str, s + 1, e - 1) + judge(str[s], str[e]);

        for(int k = s + 1; k < e; k += 2) ret = min(ret, dfs(str, s, k) + dfs(str, k + 1, e));

        return dp[s][e] = ret;
    }

    int judge(char a, char b) {
        if(isCompare(a, b)) return 0;
        if(isNotCompare(a, b)) return 1;
        return 2;
    }

    bool isCompare(char s, char e) {
        return (s == '(' && e == ')') || (s == '{' && e == '}') || (s == '[' && e == ']');
    }

    bool isNotCompare(char s, char e) {
        return (s == '(' || s == '{' || s == '[' || e == ')' || e == ']' || e == '}');
    }
};
