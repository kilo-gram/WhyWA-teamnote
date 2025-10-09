// It is possible both undigraph and digraph.
const int N = 5e5 + 9;

vector<pair<int, int>> g[N];
int vis[N], par[N], e_id[N];
vector<int> cycle; // simple cycle, contains edge ids

bool dfs(int u) {
    if (!cycle.empty()) return 1;
    vis[u] = 1;
    for (auto [v, id] : g[u]) {
        if (v != par[u]) {
            if (vis[v] == 0) {
                par[v] = u;
                e_id[v] = id;
                if (dfs(v)) return 1;
            }
            else if (vis[v] == 1) {
                // cycle here
                cycle.push_back(id);
                for (int x = u; x != v; x = par[x]) {
                    cycle.push_back(e_id[x]);
                }
                return 1;
            }
        }
    }
    vis[u] = 2;
    return 0;
}
void solve(int n, int m) {
    for (int i = 1; i < m + 1; i++) {
        int u, v;
        cin >> u >> v;
        u++;
        v++;
        g[u].push_back({v, i});
    }
    for (int u = 1; u < n + 1; u++) {
        if (vis[u] == 0 && dfs(u)) {
            // this graph is acyclic
            for (auto x : cycle) {
                // any cycle
            }
            return;
        }
    }
}
