
class Solution {
  public:
    int bfs(int start,vector<vector<int>>& adj,int& node){
        vector<int> dist(adj.size(),-1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int maxDist = 0;
        node = start;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                if(dist[v]==-1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    if(dist[v]>maxDist){
                        maxDist = dist[v];
                        node = v;
                    }
                }
            }
        }
        return maxDist;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            
            
        }
        
        int farNode ;
        bfs(0,adj,farNode);
        return bfs(farNode,adj,farNode);
    }
};
