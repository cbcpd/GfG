
class Solution {
  public:
    int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp)
    {
        if(j>=s2.size())
        {
            return 0;
        }
        if(i>=s1.size())
        {
            return INT_MAX;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int l=INT_MAX;
        if (s1[i] == s2[j]) 
        {
            int take = solve(i + 1, j + 1, s1, s2, dp);
            int notake = solve(i + 1, j, s1, s2, dp);
            if (take != INT_MAX) 
            {
                take += 1;
            }
            if (notake != INT_MAX) 
            {
                notake += 1;
            }
            l = min(take, notake);
        } 
        else 
        {
            int temp = solve(i + 1, j, s1, s2, dp);
            if (temp != INT_MAX) 
            {
                l = 1 + temp;
            }
        }

        return dp[i][j]=l;
    }
    string minWindow(string& s1, string& s2) {
        // Code here
        int n1=s1.size(),n2=s2.size(),start=-1,len=INT_MAX;
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        for(int i=0;i<n1;i++)
        {
            if(s1[i]==s2[0])
            {
                int nn=solve(i,0,s1,s2,dp);
                if(nn<len)
                {
                    len=nn;
                    start=i;
                }
            }
        }
        if(start!=-1)
        {
            return s1.substr(start,len);
        }
        return "";
    }
};

