#include <bits/stdc++.h>

#define get_variable_name(x) #x
#define debug(x) cout << #x << " = " << x << endl
#define rep(i, begin, end) for(int (i) = (begin); (i) < (end); (i)++)

using namespace std;
using ll = int64_t;

struct compare {
	bool operator() (const pair<ll, int> &l, const pair<ll, int>& r) const {
		if(l.first > r.first) {
			return l.second > r.second;
		} else {
			return false;
		}
	}
};

int main() {
    ios::sync_with_stdio(false);

	int j, k;
	ll N, D, K, ans = 0;
	cin >> N >> D >> K;

	multiset<pair<ll,int>, compare> a;
	vector<ll> x(N);

	for(int i = 0; i < N; i++) {
		cin >> x[i];
	}

	for(int i = 0; i < D; i++) {
		a.insert({x[i],i});
	}

	for(int i = 0; i < N; i++) {

		if(i+D < N) {
			a.insert({x[i+D], i+D});
		}
		auto it = a.lower_bound({x[i], i});
		a.erase(it);

		pair<ll, int> l = {x[i], i};

		if(a.size() == 0) break;;
		auto r = *(a.begin());
		int y = -l.first + r.first;

		if (y > ans)
		{
		    ans = y;
		    j = l.second;
		    k = r.second;
		}
	}

	cout << ans * K << endl;
	if (ans == 0)
	    return 0;
	cout << j << ' ' << k << endl;
}
