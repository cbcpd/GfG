
class Solution {
    
    int solve(vector<int>adj[],int i,int n){
        
      
        vector<int>dis(n,INT_MAX);
        
        vector<int>par(n,-1);
        
       
        queue<int>q;
        

    par[i]=i;
        q.push(i);
        
         dis[i]=0;
         
         int mini=INT_MAX;
        
        
        while(!q.empty()){
            
            int curr=q.front();
            
            q.pop();
            
            for(auto it:adj[curr]){
                
                if(dis[it] == INT_MAX){
                    
                    dis[it]=dis[curr]+1;
                    
                    par[it]=curr;
                    
                    q.push(it);
                }
                
                else if(par[curr]!=it){
                   
                   
                  
                
                mini=min(mini,dis[curr]+1+dis[it]);
                 
                
                    
                }
                
            }
        }
        
        return  mini;
    }
  public:
    int shortCycle(int V, vector<vector<int>>& edges) {
        
        
        int n=edges.size();
        

      vector<int>adj[V];
      
      for(auto it:edges){
          
          int u=it[0];
          int v=it[1];
          
          
          adj[u].push_back(v);
          adj[v].push_back(u);
      }
      
      
      int mini=INT_MAX;
      
      for(int i=0;i<V;i++){
          
          
          mini=min(mini,solve(adj,i,V));
          
      }
      
      
      
      return mini==INT_MAX?-1:mini;
      
        
    }
};

