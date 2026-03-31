
class Solution {
  public:
  
  int solve(int i, int canbuy, vector<int>& arr, int k, vector<vector<int>> &dp)
  {
      if(i==arr.size())
      return 0;
      
      if(dp[i][canbuy]!=-1)
      return dp[i][canbuy];
      
      if(canbuy)
      {
          return dp[i][canbuy]= max(-arr[i] + solve(i+1,!canbuy,arr,k,dp) , solve(i+1,canbuy, arr,k,dp));
      }
      else
      {
          return dp[i][canbuy]= max( +arr[i]-k + solve(i+1,1,arr, k,dp) , solve(i+1,0,arr,k,dp) );
      }
  }
    int maxProfit(vector<int>& arr, int k) {
        // Code here
        
        // 1 -> buy
        // 0 -> sell
        int n = arr.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,1,arr,k,dp);
    }
};