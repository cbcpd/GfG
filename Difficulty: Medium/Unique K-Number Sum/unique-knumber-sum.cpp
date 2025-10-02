
class Solution {
  public:
    
    void solve(int idx,int n,int k,vector<int>temp,
        vector<vector<int>>&ans,int cursum)
        {
            
            if(temp.size()>=k)
            {
                if(cursum==n)
                {
                    ans.push_back(temp);
                }
                
                return;
            }
            
            for(int i=idx+1;i<=9;i++)
            {
                temp.push_back(i);
                solve(i,n,k,temp,ans,cursum+i);
                temp.pop_back();
            }
            return;
        }
    
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        
        vector<vector<int>>ans;
        vector<int>temp;
        
        solve(0,n,k,temp,ans,0);
        
        return ans;
    }
};