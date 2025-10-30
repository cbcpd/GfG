
class Solution {
  public:
    void fill(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        map<pair<int,int>,int>vis;
        for(int i=0;i<n;i++){
            if(grid[i][0]=='O')
            q.push({i,0});
            if(grid[i][m-1]=='O')
            q.push({i,m-1});
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]=='O')
            q.push({0,j});
            if(grid[n-1][j]=='O')
            q.push({n-1,j});
        }
        int dx[4]={0,0,-1,1};
        int dy[4]={-1,1,0,0};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            vis[{x,y}]=1;
            for(int i=0;i<4;i++){
                int nx=dx[i]+x;
                int ny=dy[i]+y;
                if(nx>=0&&ny>=0&&nx<n&&ny<m &&grid[nx][ny]=='O'){
                    if(!vis[{nx,ny}]){
                        vis[{nx,ny}]=1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='O'){
                    if(!vis[{i,j}]){
                        grid[i][j]='X';
                    }
                }
            }
        }
    }
};