const int N = 1e5 + 9;
vector<int> g[N];
bool vi[N];
vector<int> ord;
void dfs(int u) {
    vi[u] = true;
    for (auto v : g[u]) {
        if (!vi[v]) {
            dfs(v);
        }
    }
    ord.push_back(u);
}

void find(int n) {
    for (int i = 1; i <= n; i++) {
        if (!vi[i]) {
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());

    // check is feasible
    vector<int> pos(n + 1);
    for (int i = 0; i < (int) ord.size(); i++) {
        pos[ord[i]] = i;
    }
    for (int u = 1; u <= n; u++) {
        for (auto v : g[u]) {
            // We need to consider self loops too!
            if (pos[u] >= pos[v]) { 
                //print impossible
                return;
            }
        }
    }

    // print the order
    for (auto u : ord) cout << u << ' ';
}
