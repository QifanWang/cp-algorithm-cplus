struct CutPoints {
    int n; // number of vec
    vector<vector<int>> G; // graph

    set<int> cutpoints; // answer, type can be vector<bool>, set<int> ... Just be careful about multiple addition
    vector<bool> vis;
    vector<int> tin, low;
    int timer;

    void init(int N) {
        n = N;
        G.assign(N, vector<int>());
    }

    void ADD_CUTPOINTS(int v){
        // remember: the same node v may be added for many times.
        // this function might change when problem changes.
        cutpoints.insert(v);
    }

    void dfs(int v, int p = -1) {
        vis[v] = true;
        tin[v] = low[v] = timer ++;

        int children = 0;
        for (int to : G[v]) {
            if(to == p) continue;
            if(vis[to]) {
                low[v] = min(low[v], tin[to]);
            } else {
                children ++;
                dfs(to, v);
                low[v] = min(low[v], low[to]);
                if(p != -1 && tin[v] <= low[to])
                    ADD_CUTPOINTS(v);
            }
        }
        if(p == -1 && children > 1)
            ADD_CUTPOINTS(v);
    }

    void solve() {
        cutpoints.clear();
        vis.assign(n, false);
        tin.assign(n, -1);
        low.assign(n, -1);
        timer = 0;

        for (int i = 0; i < n; ++i) {
            if(!vis[i])
                dfs(i);
        }
    }
};
