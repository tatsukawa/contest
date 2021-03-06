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

class CyclesInPermutations {
    public:
        int maxCycle(vector <int> board) {
            int res = 0;
            for(int i = 0; i < board.size(); i++) {
                int p = i, count = 0;
                do {
                    p = board[p] - 1;
                    count++;
                } while(p != i);

                res = max(res, count);
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
                        int board[]               = {3,2,4,1,6,5};
                        int expected__            = 3;

                        clock_t start__           = clock();
                        int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int board[]               = {1,2,3,4,5,6};
                        int expected__            = 1;

                        clock_t start__           = clock();
                        int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int board[]               = {5,1,2,3,4};
                        int expected__            = 5;

                        clock_t start__           = clock();
                        int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int board[]               = {5,7,14,6,16,10,8,17,11,12,18,3,4,13,2,15,9,1,20,19};
                        int expected__            = 11;

                        clock_t start__           = clock();
                        int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int board[]               = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int board[]               = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int board[]               = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = CyclesInPermutations().maxCycle(vector <int>(board, board + (sizeof board / sizeof board[0])));
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
