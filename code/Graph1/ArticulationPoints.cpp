const int N = 3e5 + 9;

// art = check an Articulation point.
// low = maybe restore parent? and update parent of the current node to min(low[u], low[v])
// dis = check whether a current vertex is visited or not.
int T, low[N], dis[N], art[N];
vector<int> g[N];
void dfs(int u, int pre = 0) {
    low[u] = dis[u] = ++T;
    int child = 0;
    for(auto v : g[u]) {
        if(!dis[v]) {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] >= dis[u] && pre != 0) art[u] = 1;
            ++child;
        }
        else if(v != pre) low[u] = min(low[u], dis[v]);
    }
    if(pre == 0 && child > 1) art[u] = 1;
}
