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
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

bool cmp(pii a, pii b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void solve(){
    int n, k; cin >> n >> k;
    vector<pii> a(n);
    rep(i, n) {
        cin >> a[i].first;
        a[i].second = i + 1;
        if(a[i].first % k == 0) a[i].first = k;
        if(a[i].first > k) {
            a[i].first = a[i].first % k;
        }
    }

    sort(all(a), cmp);
    for(pii p : a) {
        cout << p.second << ' ';
    }
    cout << '\n';
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