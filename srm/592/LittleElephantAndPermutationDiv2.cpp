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

class LittleElephantAndPermutationDiv2 {
    public:
        long long getNumber(int N, int K) {
            long long ans = 0;
            vector<int> A;
            for(int i = 1; i <= N; i++) A.push_back(i);
            vector<int> B = A;

            do {

                long long sum = 0;
                for(int i = 0; i < N; i++) {
                    sum += max(A[i], B[i]);
                }

                if(sum >= K) ans++;

            } while(next_permutation(B.begin(), B.end()));

            long long n = 1;
            for(int i = N; i >= 2; i--) n *= i;
            return n * ans;
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

    int verify_case(int casenum, const long long &expected, const long long &received, clock_t elapsed) { 
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
                        int N                     = 1;
                        int K                     = 1;
                        long long expected__      = 1;

                        clock_t start__           = clock();
                        long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 1: {
                        int N                     = 2;
                        int K                     = 1;
                        long long expected__      = 4;

                        clock_t start__           = clock();
                        long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 2: {
                        int N                     = 3;
                        int K                     = 8;
                        long long expected__      = 18;

                        clock_t start__           = clock();
                        long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }
            case 3: {
                        int N                     = 10;
                        int K                     = 47;
                        long long expected__      = 13168189440000LL;

                        clock_t start__           = clock();
                        long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
                        return verify_case(casenum__, expected__, received__, clock()-start__);
                    }

                    // custom cases

                    /*      case 4: {
                            int N                     = ;
                            int K                     = ;
                            long long expected__      = ;

                            clock_t start__           = clock();
                            long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 5: {
                            int N                     = ;
                            int K                     = ;
                            long long expected__      = ;

                            clock_t start__           = clock();
                            long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
                            return verify_case(casenum__, expected__, received__, clock()-start__);
                            }*/
                    /*      case 6: {
                            int N                     = ;
                            int K                     = ;
                            long long expected__      = ;

                            clock_t start__           = clock();
                            long long received__      = LittleElephantAndPermutationDiv2().getNumber(N, K);
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
