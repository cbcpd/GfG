
class Solution {
  public:
  bool helper(string &txt,string &pat,int i,int j,vector<vector<int>>&dp)
  {
      if(i<0 && j<0) return true;
      if(j<0 && i>=0) return false;
      
      if(i<0 && j>=0)
      {
          for(int k=0;k<=j;k++)
          {
              if(pat[k]!='*')
              return false;
          }
          return true;
      }
      if(dp[i][j]!=-1) return dp[i][j];
      
      if(txt[i]==pat[j] || pat[j]=='?')
      {
          return dp[i][j]=helper(txt,pat,i-1,j-1,dp);
      }
      if(pat[j]=='*')
      {
          return dp[i][j]=helper(txt,pat,i,j-1,dp) || helper(txt,pat,i-1,j,dp);
      }
      
      return false;
  }
    bool wildCard(string &txt, string &pat) {
        // code here
        vector<vector<int>>dp(txt.size()+1,vector<int>(pat.size()+1,-1));
        return helper(txt,pat,txt.size()-1,pat.size()-1,dp);
    }
};