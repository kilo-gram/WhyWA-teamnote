const int N = 3e5 + 5;

int bridge = 0;
vector<int> adj[N];
int lv[N];
int dp[N];

void dfs (int v) {
    dp[v] = 0;
    for (int u : adj[v]) {
        if (lv[u] == 0) {
            lv[u] = lv[v] + 1;
            dfs(u);
            dp[v] += dp[u];
        } else if (lv[u] < lv[v]) {
            dp[v]++;
        } else if (lv[u] > lv[v]) {
            dp[v]--;
        }
    }

    dp[v]--;

    if (lv[v] > 1 && dp[v] == 0) {
        bridge++;
    }
}
