/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
using namespace std;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define i_64 long long

std::vector<i_64> v[100001];
i_64 dist[100001][2];
i_64 h[100001], c[100001];
bool visited[100001][2];
int n, r;

void dijkstra() {
    priority_queue<pair<int, pair<int, int>>, std::vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({c[1],{1, 0}});
    q.push({c[1],{1, 1}});
    dist[1][0] = dist[1][1] = c[1];
    while(!q.empty()){
        pair<int, pair<int, int>> temp = q.top();
        int mode = temp.second.second;
        int src = temp.second.first;
        q.pop();
        if(visited[src][mode]) continue;
        visited[src][mode] = true;
        for(auto &u : v[src]){
            if (mode) {
                if(h[src] <= h[u] and dist[u][1] > dist[src][1]){
                    dist[u][1] = dist[src][1];
                    q.push({dist[u][1], {u,1}});
                }
                if(h[src] >= h[u] and dist[u][0] > dist[src][1] + c[src]){
                    dist[u][0] = dist[src][1] + c[src];
                    q.push({dist[u][0], {u,0}});
                }
            }
            else {
                if(h[src] >= h[u] and dist[u][0] > dist[src][0]){
                    dist[u][0] = dist[src][0];
                    q.push({dist[u][0],{u,0}});
                }
                if(h[src] <= h[u] and dist[u][1] > dist[src][0] + c[src]){
                    dist[u][1] = dist[src][0] + c[src];
                    q.push({dist[u][1],{u,1}});
                }
            }
        }
    }
}

void solve() {
    i_64 x, y;
    cin >> n >> r;
    for (int i = 0; i <= n; i++) dist[i][0] = dist[i][1] = LLONG_MAX;
    for (i_64 i = 1; i <= n; i++) cin >> h[i];
    for (i_64 i = 1; i <= n; i++) cin >> c[i];
    for (i_64 i = 0; i < r; i++) {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dijkstra();
    if (visited[n][0] or visited[n][1]) cout << min(dist[n][1], dist[n][0]) << "\n";
    else cout << "-1\n";
}

signed main() {
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs
  
    i_64 t(1);
    // cin >> t;
    for (i_64 i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    return 0;
}
