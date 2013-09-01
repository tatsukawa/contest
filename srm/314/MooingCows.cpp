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

class MooingCows {
    public:
        int dissatisfaction(vector <string> farmland) {
            int res = 1e8;
            int n = farmland.size();
            int m = farmland[0].size();
            
            for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) {
                if(farmland[i][j] == '.') continue;
                int sum = 0;
                for(int y = 0; y < n; y++) for(int x = 0; x < m; x++) {
                    if(farmland[y][x] == '.') continue;
                    sum += (y - i) * (y - i) + (x - j) * (x - j);
                }
                res = min(res, sum);
            }

            return res;
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
                        string farmland[]         = {"C..",
                            ".C.",
                            ".C."};
                        int expected__            = 3;

                        clock_t start__           = clock();
                        int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        string farmland[]         = {"CCCC",
                            "CCCC",
                            "CCCC"};
                        int expected__            = 26;

                        clock_t start__           = clock();
                        int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        string farmland[]         = {"C"};
                        int expected__            = 0;

                        clock_t start__           = clock();
                        int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        string farmland[]         = {"CCC....",
                            "C......",
                            "....C.C",
                            ".C.CC..",
                            "C......"};
                        int expected__            = 81;

                        clock_t start__           = clock();
                        int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            string farmland[]         = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            string farmland[]         = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            string farmland[]         = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = MooingCows().dissatisfaction(vector <string>(farmland, farmland + (sizeof farmland / sizeof farmland[0])));
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
