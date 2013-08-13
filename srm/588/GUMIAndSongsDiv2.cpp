#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class GUMIAndSongsDiv2 {
public:
    int maxSongs(vector<int> duration, vector<int> tone, int T) {
        vector<pair<int, int> > vp;
        int n = duration.size(), ans = 0;

        for(int i = 0; i < n; i++)
            vp.push_back(make_pair(tone[i], duration[i]));

        sort(vp.begin(), vp.end());

        for(int i = 0; i < (1 << n); i++) {
            int res = 0, t = -1, before = 0;

            for(int j = 0; j < n; j++) {
                if(1 & (i >> j)) {
                    t += (t == -1 ? vp[j].second + 1 : vp[j].second + abs(vp[j].first - before));
                    if(t > T) break;
                    res++, before = vp[j].first;
                }

                ans = max(ans, res);
            }
        }

        return ans;
    }
};
