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

int findIndexLIS(vector<int>& lis, int num) {
    int l = -1, r = lis.size() - 1;

    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(lis[m] < num) l = m;
        else r = m;
    }

    return r;
}

int findIndexLDS(vector<int>& lds, int num) {
    int l = -1, r = lds.size() - 1;

    while(l + 1 < r) {
        int m = l + (r - l) / 2;

        if(lds[m] > num) l = m;
        else r = m;
    }

    return r;
}

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi lis, lds, lisForIndex(n), ldsForIndex(n);

    // LIS che finisce nel punto partendo da dx
    for(int i = n - 1; i >= 0; i--) {
        int x = a[i];

        if(lis.empty() || x > lis.back()) {
            lis.pb(x);
            lisForIndex[i] = lis.size();
        } else {
            int idx = findIndexLIS(lis, x);
            lisForIndex[i] = idx + 1;
            lis[idx] = x;
        }
    }

    // LDS che finisce nel punto partendo da dx
    for(int i = n - 1; i >= 0; i--) {
        int x = a[i];

        if(lds.empty() || x < lds.back()) {
            lds.pb(x);
            ldsForIndex[i] = lds.size();
        } else {
            int idx = findIndexLDS(lds, x);
            ldsForIndex[i] = idx + 1;
            lds[idx] = x;
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans = max(ans, lisForIndex[i] + ldsForIndex[i] - 1);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    //freopen("catch.in", "r", stdin);
	//freopen("catch.out", "w", stdout);
    int t; cin >> t;
    while(t--) solve();
}