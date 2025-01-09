//BFS

vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        vector<int> res;
        vector<bool> visited(adj.size(), false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            
            res.push_back(node);
            
            for(int neigh : adj[node]) {
                if(!visited[neigh]) {
                    q.push(neigh);
                    visited[neigh] = true;
                }
            }
        }
        
        return res;
    }
