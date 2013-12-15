#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int W, H, N, x, y, nx, ny, ans = 0;
	cin >> W >> H >> N;

	cin >> x >> y;
	nx = x, ny = y;

	for(int i = 1; i < N; i++) {
		cin >> x >> y;

		// left
		if(x <= nx && y >= ny) {
			ans += (nx - x) + (y - ny);			
		} else if(x >= nx && y <= ny) {
			ans += (x - nx) + (ny - y);
		} else {
			int n = max(abs(x - nx), abs(y - ny));
			ans += n;
		}

		nx = x;
		ny = y;
	}

	cout << ans << endl;
}

