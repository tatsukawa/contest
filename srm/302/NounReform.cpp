#include <vector>
#include <string>

using namespace std;

class NounReform {
public:
    vector <string> makePlural(vector<string> nouns) {
        for(int i = 0; i < nouns.size(); i++) nouns[i] = convert(nouns[i]);
        return nouns;
    }

    string convert(string s) {
        if(s.size() == 0) return "";
        if(s.size() == 1 && (s == "s" || s == "z" || s == "x")) return s + "es";

        int n = s.size();
        char suffix1 = s[n - 1];
        char suffix2 = s[n - 2];

        if(suffix1 == 'y')
            if(suffix2 == 'a' || suffix2 == 'i' || suffix2 == 'e' || suffix2 == 'u' || suffix2 == 'o') return s + "s";
            else return s.substr(0, n - 1) + "ies";
        else if(suffix1 == 's' || suffix1 == 'z' || suffix1 == 'x' || (suffix1 == 'h' && (suffix2 == 'c' || suffix2 == 's'))) return s + "es";

        return s + "s";
    }
};
