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

class MatrixTransforming {
public:
    int minPushes(vector<string> a, vector<string> b) {
        int res = 0;
        for(int i = 0; i + 2 < a.size(); i++) {
            for(int j = 0; j + 2 < a[0].size(); j++) {
                if(a[i][j] == b[i][j]) continue;
                for(int k = 0; k < 3; k++) {
                    for(int l = 0; l < 3; l++) {
                        a[i + k][j + l] = (a[i + k][j + l] == '0' ? '1' : '0');
                    }
                }
                res++;
            }
        }

        return (a == b ? res : -1);
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
			string a[]                = {"111","111","111"};
			string b[]                = {"000","000","000"};
			int expected__            = 1;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 1: {
			string a[]                = {"1"};
			string b[]                = {"0"};
			int expected__            = -1;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 2: {
			string a[]                = {"001","100","100","000","011","010","100","100","010",
"010","010","110","101","101","000","110","000","110"};
			string b[]                = {"001","100","011","000","100","010","011","100","101",
"101","010","001","010","010","111","110","111","001"};
			int expected__            = 7;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}
		case 3: {
			string a[]                = {
"0000",
"0010",
"0000"
};
			string b[]                = {
"1001",
"1011",
"1001"
};
			int expected__            = 2;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}

		// custom cases

/*      case 4: {
			string a[]                = ;
			string b[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 5: {
			string a[]                = ;
			string b[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
			return verify_case(casenum__, expected__, received__, clock()-start__);
		}*/
/*      case 6: {
			string a[]                = ;
			string b[]                = ;
			int expected__            = ;

			clock_t start__           = clock();
			int received__            = MatrixTransforming().minPushes(vector <string>(a, a + (sizeof a / sizeof a[0])), vector <string>(b, b + (sizeof b / sizeof b[0])));
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
