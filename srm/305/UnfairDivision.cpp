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

class UnfairDivision {
    public:
        int albertsShare(vector<int> assets) {
            int res = 0;
            int n = assets.size();

            for(int i = 1; i < n; i++) {
                int bestbetty = 0, albert = 0;
                for(int j = 1; j < n; j++) {
                    if(i == j) continue;

                    int l = min(i, j), r = max(i, j);
                    int v[] = {accumulate(&assets[0], &assets[l], 0), accumulate(&assets[l], &assets[r], 0), accumulate(&assets[r], &assets[n], 0)};

                    sort(v, v + 3);

                    if(v[1] > bestbetty || (v[1] == bestbetty && albert > v[0])) {
                        bestbetty = v[1];
                        albert = v[0];
                    }
                }
                res = max(res, albert);
            }

            return res;
        }
};
