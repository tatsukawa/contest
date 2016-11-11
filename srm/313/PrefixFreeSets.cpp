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

class PrefixFreeSets {
    public:
        int maxElements(vector <string> words) {
            int res = 0;
            bool used[51];
            memset(used, 0, sizeof used);
            sort(words.begin(), words.end());
            int n = words.size();

            for(int i = n - 1; i >= 0; i--) {
                if(used[i]) continue;
                for(int j = i - 1; j >= 0; j--) {
                    bool flag = true;
                    for(int k = 0; k < words[j].size(); k++) {
                        if(words[i][k] != words[j][k]) { flag = false; }
                    }
                    if(flag) { used[j] = true; }
                }
                res++;
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
                        string words[]            = {"hello","hi","h","run","rerun","running"};
                        int expected__            = 4;

                        clock_t start__           = clock();
                        int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        string words[]            = {"a","b","cba","cbc","cbb","ccc"};
                        int expected__            = 6;

                        clock_t start__           = clock();
                        int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        string words[]            = {"a","ab","abc","abcd","abcde","abcdef"};
                        int expected__            = 1;

                        clock_t start__           = clock();
                        int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        string words[]            = {"topcoder","topcoder","topcoding"};
                        int expected__            = 2;

                        clock_t start__           = clock();
                        int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            string words[]            = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            string words[]            = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            string words[]            = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = PrefixFreeSets().maxElements(vector <string>(words, words + (sizeof words / sizeof words[0])));
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
