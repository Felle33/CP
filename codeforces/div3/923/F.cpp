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
const ll DIM = 2e5;
const ll INF = 1e15;
const int INF_INT = 1e9;
const ll LL_MAX = 9223372036854775807;
vector<int> DX = {0, 1, -1, 0};
vector<int> DY = {1, 0, 0, -1};
string DIR = "RDUL";

typedef struct {
    int u, v, w;
} Edge;

bool cmp(Edge& a, Edge& b) {
    return a.w > b.w;
}

struct DSU {
	int n;
	vector<int> p;
    vector<unsigned int> r;

	DSU() {}

    DSU(int N) {
        p = vector<int>(N);
        r = vector<unsigned int>(N, 1);

        for(int i = 0; i < N; i++){
            p[i] = i;
        }
    }

    int get(int x) { return p[x] == x ? x : p[x] = get(p[x]); }

    bool unite(int x, int y) {
        x = get(x), y = get(y);
        if(x == y) return false;
        if(r[x] == r[y]) 
            r[x]++;
        
        if(r[x] > r[y]){
			p[y] = x;
		}
        else {
			p[x] = y;
		}  
        return true;
    }

    void reset() {
		for(int i = 0; i < n; i++){
            p[i] = i;
			r[i] = 1;
        }
	}
};

void solve(){
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    rep(i, m) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }

    sort(all(edges), cmp);

    for(auto& edge : edges) {
        
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    std::cout.precision(10);
    cout << std::fixed;

    int t;
    cin >> t;

    while(t--){
        solve();
    }
}