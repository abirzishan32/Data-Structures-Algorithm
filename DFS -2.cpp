void dfs(int startNode, vector<vector<int>>& adj, vector<bool>& vis) {
    stack<int> s;
    s.push(startNode);
    vis[startNode] = true;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        cout<<node<<' ';
        st.push(node);

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                vis[neighbor] = true;
                s.push(neighbor);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj(V);
    vector <bool> vis(n, false);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
  dfs(1, adj, vis);

    return 0;
}
