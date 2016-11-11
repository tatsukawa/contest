#include <vector>
#include <algorithm>

using namespace std;

class InsertionSortCount {
public:
    int countMoves(vector<int> A) {
        return insertSort(A);
    }

    int insertSort(vector<int> A) {
        int ret = 0;
        int n = A.size();
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            bool ok = true;
            for(vector<int>::iterator it = ans.begin(); it != ans.end(); it++) {
                if((*it) > A[i]) {
                    ok = false;
                    ret += i - (it - ans.begin());
                    ans.insert(it, A[i]);
                    break;
                }
            }

            if(ok) ans.push_back(A[i]);
        }

        return ret;
    }
};
