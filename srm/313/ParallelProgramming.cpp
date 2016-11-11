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

const int INF = 1e8;

using namespace std;

class ParallelProgramming {
        vector<int> t;
        vector<string> vp;
        int dp[51]; // dp[i] := i個目の処理をするときの最大時間
        int n;
    public:
        int minTime(vector<int> time, vector <string> prec) {
            bool v[51][51];
            t = time;
            vp = prec;
            memset(v, 0, sizeof v);
            n = prec.size();
            int res = 0;

            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) if(vp[i][j] == 'Y') v[i][j] = true;
            for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = 0; k < n; k++) 
                if(v[i][j] && v[j][k]) v[i][k] = true;

            for(int i = 0; i < n; i++) if(v[i][i]) return -1;

            for(int i = 0; i < n; i++) {
                memset(dp, 0, sizeof dp);
                res = max(res, dfs(i));
            }
            return res;
        }

        int dfs(int p) {
            if(dp[p] != 0) return dp[p];
            int res = 0;
            for(int i = 0; i < n; i++) if(vp[p][i] == 'Y') 
                res = max(res, dfs(i));
            return dp[p] = res + t[p];
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

    int verify_case(int casenum, const int &expected, const int &received, clock_t elapsed) { 
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
            cerr << "    Expected: " << expected << endl; 
            cerr << "    Received: " << received << endl; 
        }

        return verdict == "PASSED";
    }

    int run_test_case(int casenum__) {
        switch (casenum__) {
            case 0: {
                        int time[]                = {150,200,250};
                        string prec[]             = {"NNN",
                            "NNN",
                            "NNN"};
                        int expected__            = 250;

                        clock_t start__           = clock();
                        int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int time[]                = {150,200,250};
                        string prec[]             = {"NNN",
                            "YNN",
                            "NNN"};
                        int expected__            = 350;

                        clock_t start__           = clock();
                        int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int time[]                = {150,200,250};
                        string prec[]             = {"NYN",
                            "NNY",
                            "NNN"};
                        int expected__            = 600;

                        clock_t start__           = clock();
                        int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int time[]                = {150,200,250};
                        string prec[]             = {"NYN",
                            "NNY",
                            "YNN"};
                        int expected__            = -1;

                        clock_t start__           = clock();
                        int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 4: {
                        int time[]                = {345,335,325,350,321,620};
                        string prec[]             = {"NNNNNN",
                            "NNYYYY",
                            "YNNNNN",
                            "NNYNYN",
                            "NNNNNN",
                            "NNNNNN"};
                        int expected__            = 1355;

                        clock_t start__           = clock();
                        int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 5: {
                            int time[]                = ;
                            string prec[]             = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int time[]                = ;
                            string prec[]             = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 7: {
                            int time[]                = ;
                            string prec[]             = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = ParallelProgramming().minTime(vector <int>(time, time + (sizeof time / sizeof time[0])), vector <string>(prec, prec + (sizeof prec / sizeof prec[0])));
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
