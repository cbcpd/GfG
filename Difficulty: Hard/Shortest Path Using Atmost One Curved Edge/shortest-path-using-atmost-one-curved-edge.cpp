
class Solution {
  public:
    int shortestPath(int V, int a, int b, vector<vector<int>> &edges) {
        vector<vector<vector<int>>> adj(V);
        for(auto& it:edges){
            adj[it[0]].push_back({it[1], it[2], 0});
            adj[it[0]].push_back({it[1], it[3], 1});
            adj[it[1]].push_back({it[0], it[2], 0});
            adj[it[1]].push_back({it[0], it[3], 1});
        }
        vector<vector<int>> dist(V, vector<int>(2, 1e9));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0,a,0});
        dist[a][0]=0;
        // dist[a][1]=0;
        while(!pq.empty()){
            int dis=pq.top()[0];
            int node=pq.top()[1];
            int flag=pq.top()[2];
            pq.pop();
            if(node==b) return dis;
            for(auto& it:adj[node]){
                int nd=it[0];
                int wt=it[1];
                int f=it[2];
                if(flag==0){
                    if(wt+dis<dist[nd][f]){
                        dist[nd][f]=wt+dis;
                        pq.push({dist[nd][f], nd, f});
                    }
                }
                if(flag && f==0) {
                    if(wt+dis<dist[nd][flag]){
                        dist[nd][flag]=wt+dis;
                        pq.push({dist[nd][flag], nd, flag});
                    }
                }
            }
        }
        return min(dist[b][1], dist[b][0]);
    }
};