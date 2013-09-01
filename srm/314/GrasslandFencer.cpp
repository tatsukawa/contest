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

class GrasslandFencer {
    public:
        int n;
        vector<int> fences;
        map<int, double> memo;

        double calcArea(int a, int b, int c) {
            if(a + b <= c) return 0;
            double p = 1.0 * (a + b + c) / 2;
            return sqrt(p * (p - a) * (p - b) * (p - c));
        }

        double dfs(int S) {
            if(memo[S]) return memo[S];
            double res = 0;
            for(int i = 0; i < n; i++) if(!(1 & (S >> i)))
                for(int j = i + 1; j < n; j++) if(!(1 & (S >> j)))
                    for(int k = j + 1; k < n; k++) if(!(1 & (S >> k))) {
                        res = max(res, dfs(S | (1 << i) | (1 << j) | (1 << k)) + calcArea(fences[i], fences[j], fences[k]));
                    }
            return memo[S] = res;
        }

        double maximalFencedArea(vector <int> f) {
            n = f.size();
            fences = f;
            return dfs(0);
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

    static const double MAX_DOUBLE_ERROR = 1e-9; static bool topcoder_fequ(double expected, double result) { if (isnan(expected)) { return isnan(result); } else if (isinf(expected)) { if (expected > 0) { return result > 0 && isinf(result); } else { return result < 0 && isinf(result); } } else if (isnan(result) || isinf(result)) { return false; } else if (fabs(result - expected) < MAX_DOUBLE_ERROR) { return true; } else { double mmin = min(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); double mmax = max(expected * (1.0 - MAX_DOUBLE_ERROR), expected * (1.0 + MAX_DOUBLE_ERROR)); return result > mmin && result < mmax; } }
    double moj_relative_error(double expected, double result) { if (isnan(expected) || isinf(expected) || isnan(result) || isinf(result) || expected == 0) return 0; return fabs(result-expected) / fabs(expected); }

    int verify_case(int casenum, const double &expected, const double &received, clock_t elapsed) { 
        cerr << "Example " << casenum << "... "; 

        string verdict;
        vector<string> info;
        char buf[100];

        if (elapsed > CLOCKS_PER_SEC / 200) {
            sprintf(buf, "time %.2fs", elapsed * (1.0/CLOCKS_PER_SEC));
            info.push_back(buf);
        }

        if (topcoder_fequ(expected, received)) {
            verdict = "PASSED";
            double rerr = moj_relative_error(expected, received); 
            if (rerr > 0) {
                sprintf(buf, "relative error %.3e", rerr);
                info.push_back(buf);
            }
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
                        int fences[]              = {3,4,5,6,7,8,9};
                        double expected__         = 36.754383146489694;

                        clock_t start__           = clock();
                        double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int fences[]              = {1,2,4,8};
                        double expected__         = 0.0;

                        clock_t start__           = clock();
                        double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int fences[]              = {7,4,4,4};
                        double expected__         = 6.928203230275509;

                        clock_t start__           = clock();
                        double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int fences[]              = {21,72,15,55,16,44,54,63,69,35,75,69,76,70,50,81};
                        double expected__         = 7512.322360676162;

                        clock_t start__           = clock();
                        double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int fences[]              = ;
                            double expected__         = ;

                            clock_t start__           = clock();
                            double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int fences[]              = ;
                            double expected__         = ;

                            clock_t start__           = clock();
                            double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int fences[]              = ;
                            double expected__         = ;

                            clock_t start__           = clock();
                            double received__         = GrasslandFencer().maximalFencedArea(vector <int>(fences, fences + (sizeof fences / sizeof fences[0])));
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
