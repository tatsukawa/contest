#include <vector>

using namespace std;

class KeyDungeonDiv2 {
public:
    int countDoors(vector <int> doorR, vector <int> doorG, vector <int> keys) {
        int res = 0;

        for(int i = 0; i < doorR.size(); i++)
            if(requireKeys(doorR[i] - keys[0]) + requireKeys(doorG[i] - keys[1]) <= keys[2]) res++;

        return res;
    }

    int requireKeys(int x) { return (x < 0 ? 0 : x); }
};
