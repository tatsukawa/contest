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

const long long MOD = 1000000007;

struct E {
    long long value;
    long long sum;
};

bool operator<(const E &l, const E &r) {
    return l.value < r.value;
}

class LittleElephantAndArray {
    public:
        int getNumber(long long A, int N) {
            vector<E> dp = {E{0, 1}};
            vector<string> vs;

            for(long long i = 0; i <= N; i++) {
                long long x = A + i;
                vs.push_back(to_string(x));
            }

            for(const auto &x : vs) {
                vector<E> vp;

                for(int i = 1; i < (1 << x.size()); i++) {
                    long long n = 0;
                    
                    for(int j = 0; j < x.size(); j++) {
                        if(i & (1 << j)) {
                            n *= 10;
                            n += (x[j] - '0');
                        }
                    }

                    auto t = E{n, 0};
                    auto it = upper_bound(dp.begin(), dp.end(), t);

                    if(it != dp.begin()) t.sum = it[-1].sum;

                    vp.push_back(t);
                }

                sort(vp.begin(), vp.end());

                for(int i = 1; i < vp.size(); i++) 
                    vp[i].sum = (vp[i].sum + vp[i - 1].sum) % MOD;

                dp.swap(vp);
            }

            return dp.back().sum;
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
                        long long A               = 1;
                        int N                     = 9;
                        int expected__            = 1;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndArray().getNumber(A, N);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        long long A               = 10;
                        int N                     = 2;
                        int expected__            = 15;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndArray().getNumber(A, N);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        long long A               = 4747774;
                        int N                     = 1;
                        int expected__            = 8369;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndArray().getNumber(A, N);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        long long A               = 6878542150015LL;
                        int N                     = 74;
                        int expected__            = 977836619;

                        clock_t start__           = clock();
                        int received__            = LittleElephantAndArray().getNumber(A, N);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            long long A               = ;
                            int N                     = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = LittleElephantAndArray().getNumber(A, N);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            long long A               = ;
                            int N                     = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = LittleElephantAndArray().getNumber(A, N);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            long long A               = ;
                            int N                     = ;
                            int expected__            = ;

                            clock_t start__           = clock();
                            int received__            = LittleElephantAndArray().getNumber(A, N);
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
