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

const ll MOD = 1e9 + 7;

ll area(vector<ll> rect) {
	ll width = rect[2] - rect[0];
	ll height = rect[3] - rect[1];
	return width * height;
}

// return 0 if it doesn't intersect
int inter_area(vector<ll> s1, vector<ll> s2) {
	int bl_a_x = s1[0], bl_a_y = s1[1], tr_a_x = s1[2], tr_a_y = s1[3];
	int bl_b_x = s2[0], bl_b_y = s2[1], tr_b_x = s2[2], tr_b_y = s2[3];

	ll l1 = min(tr_a_x, tr_b_x) - max(bl_a_x, bl_b_x);
	ll l2 = min(tr_a_y, tr_b_y) - max(bl_a_y, bl_b_y);

	if(l1 <= 0 || l2 <= 0) return 0;

	return l1 * l2;
}

// return true if x,y is covered by the rectangle s
bool covered(ll x, ll y, vector<ll> s){
	return x >= s[0] && x <= s[2] && y >= s[1] && y <= s[3];
}

ll exponentiation(ll b, ll e){
    ll res = 1;
    b %= MOD;
    while(e > 0){
        if(e & 1)
            res = res * b % MOD;
        
        b = b * b % MOD;
        e >>= 1;
    }

    return res;
}

void solve(){
    int n, x;
    cin >> n >> x;

    vector<int> prices(n);
    vector<int> pages(n);
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }

    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }

    for(int m = 1; m <= x; m++){
        if(m >= prices[n - 1]) dp[n - 1][m] = pages[n - 1];
    }

    for(int i = n - 2; i >= 0; i--){
        ll cost = prices[i];
        ll page = pages[i];

        for(int m = 1; m <= x; m++){
            ll skip = dp[i + 1][m];
            ll buy = 0;

            if(m >= cost) buy = page + dp[i + 1][m - cost];

            dp[i][m] = max(skip, buy);
        }
    }

    cout << dp[0][x];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}