// 785. Is Graph Bipartite?
// link: https://leetcode.com/problems/is-graph-bipartite/description/

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0); //0=uncolored

    for(int i=0; i<n; i++) {
        if(color[i] != 0) {
            continue;
        }
        queue<int> q;
        q.push(i);
        color[i] = 1;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            for(int neigh: graph[node]) {
                if(color[neigh] == color[node]) {
                    return false;
                }
                else if(color[neigh] == 0) {
                    color[neigh] = -color[node];
                    q.push(neigh);
                }
            }
        }
    }
    return true;
}
