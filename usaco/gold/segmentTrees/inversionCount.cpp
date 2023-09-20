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
#include <bitset>
#include <array>

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

const ll MOD = 1e9 + 7;
const ll DIM = 1e6;
const ll INF = 1e15;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

struct Ordered_statistic_tree {
    int lastLevelSize;
    int elementsPresent = 0;
    vector<ll> tree;

    ll NEUTRAL_ELEMENT = 0LL;

    Ordered_statistic_tree(int n) {
        lastLevelSize = 1;
        while(lastLevelSize < n) lastLevelSize *= 2;
        tree.resize(2 * lastLevelSize, NEUTRAL_ELEMENT);
    }

    void insert(int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            tree[x] += 1;
            elementsPresent++;
            return;
        }

        int mid = (lx + rx) / 2;
        if(v < mid) {
            insert(v, 2 * x + 1, lx, mid);
        } else {
            insert(v, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void insert(int v) {
        insert(v, 0, 0, lastLevelSize);
    }

    void erase(int v, int x, int lx, int rx) {
        if(rx - lx == 1) {
            if(tree[x] >= 1) {
                tree[x] -= 1;
                elementsPresent--;
            }
            return;
        }

        int mid = (lx + rx) / 2;
        if(v < mid) {
            erase(v, 2 * x + 1, lx, mid);
        } else {
            erase(v, 2 * x + 2, mid, rx);
        }

        tree[x] = tree[2 * x + 1] + tree[2 * x + 2];
    }

    void erase(int v) {
        erase(v, 0, 0, lastLevelSize);
    }

    ll order_of_key(int v, int x, int lx, int rx) {
        if(rx - lx == 1) return 0;
        int mid = (lx + rx) / 2;

        if(v < mid) {
            return order_of_key(v, 2 * x + 1, lx, mid);
        }
        return tree[2 * x + 1] + order_of_key(v, 2 * x + 2, mid, rx);
    }

    ll order_of_key(int v) {
        if(v >= lastLevelSize) return tree[0];
        return order_of_key(v, 0, 0, lastLevelSize);
    }

    int find_by_order(int k, int x, int lx, int rx) {
        if(rx - lx == 1) {
            return lx;
        }

        int mid = (lx + rx) / 2;
        if(k < tree[2 * x + 1]) return find_by_order(k, 2 * x + 1, lx, mid);
        return find_by_order(k - tree[2 * x + 1], 2 * x + 2, mid, rx);
    }

    int find_by_order(int k) {
        if(k >= tree[0]) return -1;
        return find_by_order(k, 0, 0, lastLevelSize);
    }

    ll size() {
        return elementsPresent;
    }
};

void solve(){
    int n; cin >> n;
    vi a(n);
    rep(i, n) cin >> a[i];

    vi copy = a;
    sort(all(copy));
    map<int, int> com;
    rep(i, n) com[copy[i]] = i + 1;

    Ordered_statistic_tree ord(n + 1);

    ll ans = 0;
    rep(i, n) {
        ll num = ord.size() - ord.order_of_key(com[a[i]] + 1);
        ans += num;
        ord.insert(com[a[i]]);
    }

    cout << ans << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
}