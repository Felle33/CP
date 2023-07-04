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

    vector<vector<int>> graph(n);
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n);
    vector<int> parent(n);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    parent[0] = -1;
    int ans = 0;

    while(!q.empty()){
        int cycles = q.size();
        ans++;

        while(cycles--){
            int node = q.front();
            q.pop();

            for(int adj : graph[node]){
                if(adj == n - 1){
                    parent[adj] = node;
                    cout << ans + 1 << '\n';

                    vector<int> path;
                    int child = adj;

                    while(parent[child] != -1){
                        path.push_back(child + 1);
                        child = parent[child];
                    }
                    path.push_back(1);

                    reverse(all(path));

                    for(int t : path) cout << t << " ";
                    return;
                }

                if(!visited[adj]){
                    q.push(adj);
                    parent[adj] = node;
                    visited[adj] = true;
                }
            }
        }
    }

    cout << "IMPOSSIBLE";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    /* freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout); */

    solve();
}