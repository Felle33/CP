#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <cstring>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>

#define all(x) (x).begin(), (x).end()
#define mp make_pair
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 99999999999999997;
const ll DIM = 1e6;
const int INF = 1e9;
const ll LLINF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
const int LOG = 22;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};

int n, m;
vector<pii> a;

// dp[i][j] = max flavour knowing i am at i-th pos and i have j dollars
int rec(int i, int j, vvi& dp) {
    if(j < 0) return -INF;
    if(i == n) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans = max(rec(i + 1, j, dp), a[i].second + rec(i + 1, j - a[i].first, dp));

    dp[i][j] = ans;
    return ans;
}

void solve(){
    cin >> m >> n;

    a.resize(n);
    rep(i, n) cin >> a[i].first >> a[i].second;

    if(m >= 2000) {
        vvi dp(n, vi(m + 201, -1));
        cout << rec(0, m + 200, dp) << "\n";
    } else {
        vvi dp(n, vi(m + 1, -1));
        cout << rec(0, m, dp) << "\n";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    solve();
}