const int N = 2e5 + 9;

vector<int> g[N];
int farthest(int s, int n, vector<int> &d) {
    static const int inf = N;
    d.assign(n + 1, inf); d[s] = 0;
    vector<bool> vis(n + 1);
    queue<int> q; q.push(s);
    vis[s] = 1; int last = s;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) {
            if (vis[v]) continue;
            d[v] = d[u] + 1;
            q.push(v); vis[v] = 1;
        }
        last = u;
    }
    return last;
}

void solve(int n) {
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> dx, dy;
    int x = farthest(1, n, dx);
    int y = farthest(x, n, dx);
    farthest(y, n, dy);
    int ans = 0;
    for (int i = 1; i < n + 1; i++) ans = max(dy[i], ans);
    // print ans.
}
