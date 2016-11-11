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

class MultiRead {
    public:
        int minCycles(string trace, int procs) {
            int n = trace.size();
            int res = 0, r, w;
            for(int i = 0, r, w; (r = w = 0) || i < n;) {
                for(int count = 0; i < n && count < procs; i++, count++) {
                    if(trace[i] == 'W') w++;
                    if(trace[i] == 'R') r++;

                    if(r > 0 && w == 1)  break;
                    if(r == 0 && w == 1) {
                        i++;
                        break;
                    }
                }
                res++;
            }

            return res;
        }
};
