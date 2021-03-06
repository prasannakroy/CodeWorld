/*****************************
*  Author :: Prasanna Kumar  *
*****************************/

/***********************************
* Unus pro omnibus, omnes pro uno  *
***********************************/
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
using namespace std;
using namespace std::chrono;

#define __AcHiLlEs ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define __AnAkLuSmOs freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#define int unsigned long long
#define span(a) a.begin(), a.end()
#define sum(n) ((int)n * (int)(n + 1)) / 2
#define sumr(l, r) sum(r) - sum(l)

struct edge {
	int a, b, w;
};

template<typename t>
class Graph {
public:
    vector<vector<pair<t, t>>> adj; // Adjecency List of Graph
    vector<vector<t>> dist; // Distance matrix (Distance of each node to each other node)
    vector<bool> vis; // Bool array to check if shortest paths from this node is already calulated or not.
    t n, m; // n = number of nodes, m = number of edges

    Graph(t n, t m) : n(n), m(m) { // Constructor to initialize graph with n nodes and m edges
        adj.resize(n + 1); // Initialize adjecenct list for node numbers 1 to n
        dist.resize(n + 1); // Initialize Distance matrix for node numbers 1 to n
        vis.resize(n + 1, 0); // Initialize vis array with 0 marking all nodes unvisited
    }

    void join(t x, t y, t d) { // Join two nodes with an edge of weight d
        adj[x].push_back({y, d}); 
        // adj[y].push_back({x, d});
    }

    int dijkstra(t s, t e = 1) {
        if (vis[s]) return dist[s][e]; // If all shortest paths from s are already computed return value
        vis[s] = 1; // Mark node visited
        dist[s].resize(n + 1, LLONG_MAX); // Initialize dist from s to all nodes with max value
        dist[s][s] = 0; // Make dist from source to itself 0

        priority_queue<pair<t, t>> q; // initialize priority queue to make heap (I will be using negetive values for making minheap rather than making actual min heap)
        q.push({0, s}); // Insert source node with it's distance

        while (!q.empty()) { // Run the while loop while queue is not empty
            auto p = q.top(); // Save the minimum distance node pair in p
            q.pop(); // Pop the queue
            t u = p.second; // The node number
            if (-p.first != dist[s][u]) continue; // If the node is already computed and hence it's distance is updated therefore continue.
            for (auto &i: adj[u]) { // Run loop in adjecency list of the obtained node and relax all possible node distances
                t T = i.first; // node number
                t d = i.second; // node distance
                if (dist[s][T] > dist[s][u] + d) { // If distance is modifiable
                    dist[s][T] = dist[s][u] + d; // update distance
                    q.push({-dist[s][T], T}); // insert in queue (negetive value to make it act like min-heap)
                }
            }
        }
        return dist[s][e]; // when loop is over return the distance computed
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Graph<int> gph1(n, m), gph2(n, m); // declare graph
    vector<edge> edgeList;
    for (int i = 0; i < m; i++) {
        int x, y, d; 
        cin >> x >> y >> d;
        edgeList.push_back({x, y, d});
        gph1.join(x, y, d); // add edges
        gph2.join(y, x, d);
    }
    gph1.dijkstra(1);
    gph2.dijkstra(n);
    int res = LLONG_MAX;
    for (auto &i: edgeList) 
    	res = min(res, gph1.dist[1][i.a] + gph2.dist[n][i.b] + (i.w / 2));
   	cout << res << "\n";
}

signed main() {
    // auto start = high_resolution_clock::now();
    #ifndef ONLINE_JUDGE 
        __AnAkLuSmOs    
    #endif

    __AcHiLlEs

    int t(1);
    // cin >> t;
    for (int i = 1; i <= t; /*cout << "Case " << i << ": ",*/ solve(), i++);
    // auto stop = high_resolution_clock::now();
    // double duration = duration_cast<microseconds>(stop - start).count();
    // cout << fixed << setprecision(4) << duration / 1000000 << "\n";  
    return 0;
}