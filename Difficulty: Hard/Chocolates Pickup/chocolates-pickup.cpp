
class Solution {
  public:
    int n, m;
    int d[3] = {-1, 0, 1};
    int helper(int r, int c1, int c2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp){
        //base case
        if(r>=n || c1<0 || c1>=m || c2<0 || c2>=m){
            return INT_MIN;
        }
        if(r==n-1){
            //2 cases
            //different cell
            if(c1!=c2){
                return grid[r][c1] + grid[r][c2];
            }
            //same cell
            else{
                return grid[r][c1];
            }
        }
        
        
        
        //stuff
        if(dp[r][c1][c2]!=-1)return dp[r][c1][c2];
        int maxi = INT_MIN;
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                int curr = (c1==c2) ? (grid[r][c1]) : (grid[r][c1] + grid[r][c2]);
                maxi = max(
                    maxi, curr+helper(r+1, c1+d[i], c2+d[j], grid, dp)
                    );
            }
        }
        
        return dp[r][c1][c2]=maxi;
        
    }
    int maxChocolate(vector<vector<int>>& grid) {
        // code here
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return helper(0, 0, m-1, grid, dp);
    }
};