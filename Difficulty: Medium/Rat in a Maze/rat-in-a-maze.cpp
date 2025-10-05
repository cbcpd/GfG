
class Solution {
  public:
    string dirs="DLUR";
    int dr[4]={1,0,-1,0};
    int dc[4]={0,-1,0,1};
    void recur(vector<vector<int>>& maze,int n,int r,int c,string& path,vector<string>& paths,vector<vector<int>>& vis){
        if(r==n-1 && c==n-1){
            paths.push_back(path);
            return;
        }
        for(int i=0;i<4;i++){
            int nr=r+dr[i], nc=c+dc[i];
            if(nr>=0 && nr<n && nc>=0 && nc<n && maze[nr][nc] && !vis[nr][nc]){
                vis[nr][nc]=1;
                path.push_back(dirs[i]);
                recur(maze,n,nr,nc,path,paths,vis);
                vis[nr][nc]=0;
                path.pop_back();
            }
        }
    }    
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> paths;
        if(!maze[0][0]) return paths;
        int n=maze.size();
        string path="";
        vector<vector<int>> vis(n,vector<int>(n,0));
        vis[0][0]=1;
        recur(maze,n,0,0,path,paths,vis);
        sort(paths.begin(), paths.end());
        return paths;
    }
};