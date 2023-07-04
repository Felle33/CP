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
const ll DIM = 1e6;
const ll INF = 1e9;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

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
    int n, m;
    cin >> n >> m;

    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    r1--, c1--, r2--, c2--;
    int res1 = 0;

    for(int i = 0; i < 4; i++){
        int newR1 = r1 + DY[i];
        int newC1 = c1 + DX[i];

        if(newR1 < 0 || newC1 < 0 || newR1 == n || newC1 == m) continue;
        res1++;
    }

    int res2 = 0;

    for(int i = 0; i < 4; i++){
        int newR2 = r2 + DY[i];
        int newC2 = c2 + DX[i];

        if(newR2 < 0 || newC2 < 0 || newR2 == n || newC2 == m) continue;
        res2++;
    }

    cout << min(res1, res2) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}