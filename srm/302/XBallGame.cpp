#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

class XBallGame {
public:
    map<string, vector<string> > mv;
    vector <string> newStatistics(vector<string> placeboard) {
        vector<string> ans;

        for(int i = 0; i < placeboard.size(); i++)
            mv[extractName(placeboard[i])].push_back(extractPosition(placeboard[i]));

        for(int i = 0; i < placeboard.size(); i++) {
            string name = extractName(placeboard[i]);
            string position = extractPosition(placeboard[i]);
            string res = name + "-" + position;
            sort(mv[name].begin(), mv[name].end());
            for(int i = 0; i < mv[name].size(); i++)
                if(mv[name][i] != position) res += "," + mv[name][i];
            ans.push_back(res);
        }

        return ans;
    }

    string extractName(string s) { return s.substr(0, s.find("-")); }

    string extractPosition(string s) { return s.substr(s.find("-") + 1); }
};
