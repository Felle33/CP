#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_map>
#include <map>
#include <set>
#include <iomanip>

#define all(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

typedef long long li;
typedef pair<int, int> pt;

const int INF = int(1e9);

int W, H;
int x1, y1, x2, y2;
int w, h;

inline bool read() {
	if(!(cin >> W >> H))
		return false;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> w >> h;
	return true;
}

inline void solve() {
	int ans = INF;
	if (x2 - x1 + w <= W) {
		ans = min(ans, max(0, w - x1));
		ans = min(ans, max(0, x2 - (W - w)));
	}
	if (y2 - y1 + h <= H) {
		ans = min(ans, max(0, h - y1));
		ans = min(ans, max(0, y2 - (H - h)));
	}
	if (ans == INF)
		cout << -1 << endl;
	else
		cout << double(ans) << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif	
	cout << fixed << setprecision(9);
	int t; cin >> t;
	while(t--) {
		(read());
		solve();
	}
	return 0;
}