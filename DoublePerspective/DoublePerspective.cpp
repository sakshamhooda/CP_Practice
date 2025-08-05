#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <tuple>

using namespace std;

struct Edge {
    int u, v, id;
};

int calculate_f(const vector<Edge>& edges) {
    if (edges.empty()) {
        return 0;
    }
    vector<pair<int, int>> intervals;
    for (const auto& edge : edges) {
        intervals.push_back({edge.u, edge.v});
    }
    sort(intervals.begin(), intervals.end());
    int total_length = 0;
    int current_start = intervals[0].first;
    int current_end = intervals[0].second;
    for (size_t i = 1; i < intervals.size(); ++i) {
        if (intervals[i].first < current_end) {
            current_end = max(current_end, intervals[i].second);
        } else {
            total_length += current_end - current_start;
            current_start = intervals[i].first;
            current_end = intervals[i].second;
        }
    }
    total_length += current_end - current_start;
    return total_length;
}

namespace Biconnected {
    vector<int> adj[6005];
    int tin[6005], low[6005];
    int timer;
    vector<pair<int, int>> edge_stack;
    bool visited[6005];
    set<int> cyclic_nodes;

    void find_bccs(int u, int p = -1) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        
        for (int v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {
                if (tin[v] < tin[u]) {
                    low[u] = min(low[u], tin[v]);
                    edge_stack.push_back({u, v});
                }
            } else {
                edge_stack.push_back({u, v});
                find_bccs(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    set<int> bcc_nodes;
                    vector<pair<int,int>> current_bcc_edges;
                    while (true) {
                        pair<int, int> edge = edge_stack.back();
                        edge_stack.pop_back();
                        current_bcc_edges.push_back(edge);
                        bcc_nodes.insert(edge.first);
                        bcc_nodes.insert(edge.second);
                        if ((edge.first == u && edge.second == v) || (edge.first == v && edge.second == u)) break;
                    }
                    if (bcc_nodes.size() >= 3) {
                        for(int node : bcc_nodes) {
                            cyclic_nodes.insert(node);
                        }
                    }
                }
            }
        }
    }

    int calculate_g(const vector<int>& nodes, const vector<Edge>& edges) {
        if (nodes.empty()) return 0;
        for (int node : nodes) {
            adj[node].clear();
            visited[node] = false;
        }
        cyclic_nodes.clear();
        for (const auto& edge : edges) {
            adj[edge.u].push_back(edge.v);
            adj[edge.v].push_back(edge.u);
        }
        timer = 0;
        edge_stack.clear();
        for (int node : nodes) {
            if (!visited[node]) {
                find_bccs(node);
            }
        }
        return cyclic_nodes.size();
    }
}

void solve() {
    int n;
    cin >> n;
    vector<Edge> all_edges(n);
    vector<vector<int>> adj(2 * n + 2);
    vector<bool> is_vertex(2 * n + 2, false);
    for (int i = 0; i < n; ++i) {
        cin >> all_edges[i].u >> all_edges[i].v;
        all_edges[i].id = i + 1;
        adj[all_edges[i].u].push_back(all_edges[i].v);
        adj[all_edges[i].v].push_back(all_edges[i].u);
        is_vertex[all_edges[i].u] = true;
        is_vertex[all_edges[i].v] = true;
    }

    vector<tuple<int, int, int, vector<int>>> component_values;
    for (int l = 1; l <= 2 * n; ++l) {
        if (!is_vertex[l]) continue;
        
        vector<int> q;
        q.push_back(l);
        set<int> visited_nodes;
        visited_nodes.insert(l);
        int head = 0;
        
        while(head < q.size()){
            int u = q[head++];
            for(int v : adj[u]){
                if(v >= l && visited_nodes.find(v) == visited_nodes.end()){
                    visited_nodes.insert(v);
                    q.push_back(v);
                }
            }
        }

        if (visited_nodes.size() <= 1) continue;

        vector<int> component_nodes_vec;
        int r = l;
        for(int node : visited_nodes){
            component_nodes_vec.push_back(node);
            r = max(r, node);
        }

        vector<Edge> component_edges;
        for(const auto& edge : all_edges){
            if(visited_nodes.count(edge.u) && visited_nodes.count(edge.v)){
                component_edges.push_back(edge);
            }
        }
        
        int f = calculate_f(component_edges);
        int g = Biconnected::calculate_g(component_nodes_vec, component_edges);
        int val = f - g;
        vector<int> edge_ids;
        for(auto& edge : component_edges) edge_ids.push_back(edge.id);
        component_values.emplace_back(l, r, val, edge_ids);
    }

    vector<long long> dp(2 * n + 2, 0);
    vector<tuple<int, vector<int>>> choices(2 * n + 2, {-1, {}});

    for (int i = 1; i <= 2 * n; ++i) {
        dp[i] = dp[i-1];
        choices[i] = {i-1, {}};
    }
    
    for (const auto& comp : component_values) {
        int l, r, val;
        vector<int> ids;
        tie(l, r, val, ids) = comp;
        if (l > 0 && dp[l-1] + val > dp[r]) {
            dp[r] = dp[l-1] + val;
            choices[r] = {l-1, ids};
        }
    }
    
    set<int> result_indices_set;
    int current = 2 * n;
    while (current > 0) {
        auto& choice = choices[current];
        int prev_idx = get<0>(choice);
        if (prev_idx != -1) {
            for (int id : get<1>(choice)) {
                result_indices_set.insert(id);
            }
            current = prev_idx;
        } else {
            current--;
        }
    }
    
    vector<int> result_indices(result_indices_set.begin(), result_indices_set.end());
    cout << result_indices.size() << endl;
    for (size_t i = 0; i < result_indices.size(); ++i) {
        cout << result_indices[i] << (i == result_indices.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}