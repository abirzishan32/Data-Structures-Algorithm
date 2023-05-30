#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define div 1000003
#define mod 1000000007
#define MOD 998244353
#define N 10000005
#define fr(i, a, b) for (int i = a; i < b; i++)
#define fri(i, a, b) for (int i = a; i >= b; i--)
#define pb push_back
#define pyn(flag) cout << (flag ? "YES" : "NO") << endl;
#define vin cin >> v[i]
#define vsort sort(v.begin(), v.end())
#define vrev reverse(v.begin(), v.end())
#define yout cout << "YES" << endl
#define nout cout << "NO" << endl

vector<int> iterativeDFS(int start, vector<vector<int> >& adj, vector<bool>& visited) {
    vector<int> result;
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            visited[node] = true;
            result.push_back(node);
        }

        for (auto it : adj[node]) {
            if (!visited[it]) {
                st.push(it);
            }
        }
    }

    return result;
}

vector<int> topologicalSort(int n, vector<vector<int> >& adj) {
    vector<bool> visited(n, false);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            vector<int> nodes = iterativeDFS(i, adj, visited);
            result.insert(result.end(), nodes.begin(), nodes.end());
        }
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;
    vector<vector<int> > adj(V);

    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    vector<int> topo = topologicalSort(V, adj);

    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
