struct DSU {
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n) {
        for (int i = 1; i <= n; ++i) par[i] = i;
    }
    int find(int i) {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(int i, int j) {
        return find(i) == find(j);
    }
    int get_size(int i) {
        return sz[find(i)];
    }
    int count() {
        return c;
    }
    int unite(int i, int j) {
        if ((i = find(i)) == (j = find(j))) return -1;
        else --c;
        if (rnk[i] > rnk[j]) swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j]) rnk[j]++;
        return j;
    }
};

void mst(int n, int m) {
    vector<array<int, 3>> ed;
    for (int i = 1; i < m + 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        ed.push_back({w, u, v});
    }
    // if you want to find Maximum Spanning Tree,
    // then you should sort all edge of graph 
    // in decreasing order of weights.
    sort(ed.begin(), ed.end());
    ll ans = 0;
    DSU d(n);
    for (auto e : ed) {
        int u = e[1], v = e[2], w = e[0];
        if (d.same(u, v)) continue;
        ans += w;
        d.unite(u, v);
    }
    //print ans
}
