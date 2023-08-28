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
#define mp make_pair
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))

using namespace std;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<unsigned long long> vull;
typedef vector<vector<int>> vvi;
typedef long long ll;
typedef pair<int,int> pii;

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
const int MAX = 2e5 + 1;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

void solve(){
    ll n, m, d; cin >> n >> m >> d;
    vll a(n);
    rep(i, n) cin >> a[i];
    priority_queue<ll> pq;

    multiset<ll> prefMov;
    ll sum = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
        ll cur = sum + a[i] - d * (i + 1);
        ans = max(ans, cur);
        if(a[i] > 0) {
            prefMov.insert(a[i]);
            sum += a[i];
            int s = prefMov.size();
            if(s >= m) {
                auto it = prefMov.begin();
                sum -= *it;
                prefMov.erase(it);
            }
        }
    }

    cout << ans << '\n';
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