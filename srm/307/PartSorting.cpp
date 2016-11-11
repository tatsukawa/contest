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

class PartSorting {
    public:
        vector<int> process(vector<int> data, int nSwaps ) {
            int n = data.size();

            for(int i = 0; 0 < nSwaps && i < n; i++) {
                int max_value = data[i];
                int idx = i;

                for(int j = i, c = 0; j < n && c <= nSwaps; j++, c++)
                    if(max_value < data[j])
                        max_value = data[j], idx = j;

                for(int j = idx; j > i; j--)
                    swap(data[j], data[j - 1]);
                nSwaps -= idx - i;
            }

            return data;
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

    template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << "{"; for (typename vector<T>::const_iterator vi=v.begin(); vi!=v.end(); ++vi) { if (vi != v.begin()) os << ","; os << " " << *vi; } os << " }"; return os; }

    int verify_case(int casenum, const vector <int> &expected, const vector <int> &received, clock_t elapsed) {
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
                        int data[]                = {10, 20, 30, 40, 50, 60, 70};
                        int nSwaps                = 1;
                        int expected__[]          = {20, 10, 30, 40, 50, 60, 70 };

                        clock_t start__           = clock();
                        vector <int> received__   = PartSorting().process(vector <int>(data, data + (sizeof data / sizeof data[0])), nSwaps);
                        return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                    }
            case 1: {
                        int data[]                = {3, 5, 1, 2, 4} ;
                        int nSwaps                = 2;
                        int expected__[]          = {5, 3, 2, 1, 4 };

                        clock_t start__           = clock();
                        vector <int> received__   = PartSorting().process(vector <int>(data, data + (sizeof data / sizeof data[0])), nSwaps);
                        return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                    }
            case 2: {
                        int data[]                = {19, 20, 17, 18, 15, 16, 13, 14, 11, 12};
                        int nSwaps                = 5;
                        int expected__[]          = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11 };

                        clock_t start__           = clock();
                        vector <int> received__   = PartSorting().process(vector <int>(data, data + (sizeof data / sizeof data[0])), nSwaps);
                        return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                    }

                    // custom cases

                          case 3: {
                            int data[ ]                = {
89, 103, 107, 90, 97, 85, 12, 29, 71, 10, 94, 18, 15, 36, 55, 13, 77, 86, 5, 4, 48, 47, 3, 43, 25, 41, 74, 119, 8, 113, 42, 98, 14, 80, 37, 110, 11, 115, 87, 21, 127, 28, 124, 61, 102, 39, 70, 38, 81, 73
                            };
                            int nSwaps                = 10;
                            int expected__[]          =
                            {107, 103, 97, 90, 89, 85, 94, 12, 29, 71, 10, 18, 15, 36, 55, 13, 77, 86, 5, 4, 48, 47, 3, 43, 25, 41, 74, 119, 8, 113, 42, 98, 14, 80, 37, 110, 11, 115, 87, 21, 127, 28, 124, 61, 102, 39, 70, 38, 81, 73

                            }
                                ;

                            clock_t start__           = clock();
                            vector <int> received__   = PartSorting().process(vector <int>(data, data + (sizeof data / sizeof data[0])), nSwaps);
                            return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                            }
                    /*      case 4: {
                            int data[]                = ;
                            int nSwaps                = ;
                            int expected__[]          = ;

                            clock_t start__           = clock();
                            vector <int> received__   = PartSorting().process(vector <int>(data, data + (sizeof data / sizeof data[0])), nSwaps);
                            return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int data[]                = ;
                            int nSwaps                = ;
                            int expected__[]          = ;

                            clock_t start__           = clock();
                            vector <int> received__   = PartSorting().process(vector <int>(data, data + (sizeof data / sizeof data[0])), nSwaps);
                            return verify_case(casenum__, vector <int>(expected__, expected__ + (sizeof expected__ / sizeof expected__[0])), received__, clock()-start__);
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
