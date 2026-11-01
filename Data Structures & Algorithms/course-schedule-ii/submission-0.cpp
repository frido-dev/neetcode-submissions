class Solution {
public:
    bool isCycleDfs(int src, vector<bool> &vis, vector<bool> &recPath, vector<vector<int>> &edges) {
        vis[src] = true;
        recPath[src] = true;

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0];

            if (src == u) {
                if (!vis[v]) {
                    if (isCycleDfs(v, vis, recPath, edges)) {
                        return true;
                    }
                } else if (recPath[v]) {
                    return true;
                }
            }
        }

        recPath[src] = false;
        return false;
    }

    void topoSort(int src, vector<vector<int>> &edges, stack<int> & s, vector<bool> &vis) {
        vis[src] = true;

        for(int i = 0; i <edges.size(); i++) {
            int u = edges[i][1];
            int v = edges[i][0];

            if (src == u) {
                if(!vis[v]) {
                    topoSort(v, edges, s, vis);
                }
            }
        }
        s.push(src);
    }

    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vector<bool> vis(n, false);
        vector<bool> recPath(n, false);
        stack<int> s;
        vector<int> ans;

        for (int i = 0; i<n; i++) {
            if (!vis[i]) {
                if (isCycleDfs(i, vis, recPath, edges)) {
                    return ans;
                }
            }
        }

        vis.assign(n, false);

        for (int i = 0; i<n; i++) {
            if (!vis[i]) {
                topoSort(i, edges, s, vis);
            }
        }

        while(s.size() > 0) {
            ans.push_back(s.top());
            s.pop();
        }

        return ans;
    }
};
