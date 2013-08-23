#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
string max(const string &_a, const string &_b) {
    string a = (_a.size() == 0 ? _a : _a[0] == '0' ? _a.substr(1) : _a);
    string b = (_b.size() == 0 ? _b : _b[0] == '0' ? _b.substr(1) : _b);

    if(a.size() == 0 && b.size() == 0) return "0";

    if(a.size() > b.size()) return a;
    if(a.size() < b.size()) return b;

    for(int i = 0; i < a.size(); i++) {
        if(a[i] > b[i]) return a;
        if(a[i] < b[i]) return b;
    }

    return a;
}
class MatchNumbersEasy {
    // dp[i] := i個一致する数を使った時の最大数。
    public:
        string maxNumber(vector<int> matches, int n) {
            vector<string> dp(n + 1, "");

            for(int i = 0; i <= n; i++) {
                for(int j = 0; j < matches.size(); j++) {
                    if(i + matches[j] > n) continue;

                    dp[i + matches[j]] = max(dp[i + matches[j]], dp[i] + string(1, j + '0'));
                }
            }
            return dp[n];
        }
};

// BEGIN CUT HERE
namespace moj_harness {
    int run_test_case(int);
    void run_test(int casenum = -1, bool quiet = false) {
        if (casenum != -1) {
            if (run_test_case(casenum) == -1 && !quiet) {
                cerr << "Illegal input! Test case " << casenum << " does not exist." << endl;
            }
            return;
        }

        int correct = 0, total = 0;
        for (int i=0;; ++i) {
            int x = run_test_case(i);
            if (x == -1) {
                if (i >= 100) break;
                continue;
            }
            correct += x;
            ++total;
        }

        if (total == 0) {
            cerr << "No test cases run." << endl;
        } else if (correct < total) {
            cerr << "Some cases FAILED (passed " << correct << " of " << total << ")." << endl;
        } else {
            cerr << "All " << total << " tests passed!" << endl;
        }
    }

    int verify_case(int casenum, const string &expected, const string &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (expected == received) {
            verdict = "PASSED";
        } else {
            verdict = "FAILED";
        }

        cerr << verdict;
        if (!info.empty()) {
            cerr << " (";
            for (int i=0; i<(int)info.size(); ++i) {
                if (i > 0) cerr << ", ";
                cerr << info[i];
            }
            cerr << ")";
        }
        cerr << endl;

        if (verdict == "FAILED") {
            cerr << "    Expected: \"" << expected << "\"" << endl; 
            cerr << "    Received: \"" << received << "\"" << endl; 
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum__) {
        switch (casenum__) {
            case 0: {
                        int matches[]             = {6,7,8};
                        int n                     = 21;
                        string expected__         = "210";

                        clock_t start__           = clock();
                        string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int matches[]             = {5,23,24};
                        int n                     = 30;
                        string expected__         = "20";

                        clock_t start__           = clock();
                        string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int matches[]             = {1,5,3,2};
                        int n                     = 1;
                        string expected__         = "0";

                        clock_t start__           = clock();
                        string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int matches[]             = {1,1,1,1,1,1,1,1,1,1};
                        int n                     = 50;
                        string expected__         = "99999999999999999999999999999999999999999999999999";

                        clock_t start__           = clock();
                        string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int matches[]             = ;
                            int n                     = ;
                            string expected__         = ;

                            clock_t start__           = clock();
                            string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int matches[]             = ;
                            int n                     = ;
                            string expected__         = ;

                            clock_t start__           = clock();
                            string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int matches[]             = ;
                            int n                     = ;
                            string expected__         = ;

                            clock_t start__           = clock();
                            string received__         = MatchNumbersEasy().maxNumber(vector <int>(matches, matches + (sizeof matches / sizeof matches[0])), n);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
            default:
                    return -1;
        }
    }
}


int main(int argc, char *argv[]) {
    if (argc == 1) {
        moj_harness::run_test();
    } else {
        for (int i=1; i<argc; ++i)
            moj_harness::run_test(atoi(argv[i]));
    }
}
// END CUT HERE
