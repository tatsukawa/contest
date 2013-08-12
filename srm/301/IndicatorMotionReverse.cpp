#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

class IndicatorMotionReverse {
    map<char, char> L, R, S, F;
public:
    string getMinProgram(vector<string> actions) {
        return format(parser(actions));
    }

    string format(string a) {
        string ret = "";
        for(int i = 0; i < a.size();) {
            char c = a[i];
            int n = 1;
            for(i++; c == a[i]; i++, n++) {}

            ret += unique(c, n);
        }

        if(ret.size() > 100) ret = ret.substr(0, 97) + "...";

        return ret;
    }

    string unique(char c, int n) {
        ostringstream oss;

        int x = n % 99;
        n -= x;

        if(x != 0) oss << c << setfill('0') << setw(2) << x;
        for(int i = 0; i < n/99; i++) oss << c << "99";

        return oss.str();
    }

    string parser(vector<string>& a) {
        generate();

        string ans = "";
        char before = '.';
        for(int i = 0; i < a.size(); i++) {
            for(int j = 0; j < a[i].size(); j++) {
                if(before == '.') {
                    before = a[i][j];
                    continue;
                }

                ans += judge(before, a[i][j]);
                before = a[i][j];
            }
        }

        return ans;
    }

    char judge(char before, char after) {
        if(L[before] == after) return 'L';
        if(R[before] == after) return 'R';
        if(S[before] == after) return 'S';
        return 'F';
    }

    void generate(void) {
        L['|'] = 'N';
        L['N'] = '-';
        L['-'] = '/';
        L['/'] = '|';
        R['N'] = '|';
        R['|'] = '/';
        R['/'] = '-';
        R['-'] = 'N';
        S['|'] = '|';
        S['N'] = 'N';
        S['-'] = '-';
        S['/'] = '/';
        F['N'] = '/';
        F['|'] = '-';
        F['-'] = '|';
        F['/'] = 'N';
    }
};
