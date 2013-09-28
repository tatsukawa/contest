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

class LittleElephantAndBooks {
    public:
        int getNumber(vector <int> pages, int number) {
            sort(pages.begin(), pages.end());
            return accumulate(pages.begin(), pages.begin() + number + 1, 0) - pages[number - 1];
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
                        int pages[]               = {1, 2};
                        int number                = 1;
                        int expected__            = 2;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int pages[]               = {74, 7, 4, 47, 44};
                        int number                = 3;
                        int expected__            = 58;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int pages[]               = {3, 1, 9, 7, 2, 8, 6, 4, 5};
                        int number                = 7;
                        int expected__            = 29;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int pages[]               = {74, 86, 32, 13, 100, 67, 77};
                        int number                = 2;
                        int expected__            = 80;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int pages[]               = ;
                            int number                = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int pages[]               = ;
                            int number                = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int pages[]               = ;
                            int number                = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = LittleElephantAndBooks().getNumber(vector <int>(pages, pages + (sizeof pages / sizeof pages[0])), number);
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
