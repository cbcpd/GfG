
class Solution {
 public:
    vector<int> subsetXOR(int n) {
        vector<int> ans;
        if(n%4 == 0)
        {
            for(int i=1; i<=n; i++) ans.push_back(i);
        }
        else if(n%4 == 1)
        {
            for(int i=1; i<=n-2; i++) ans.push_back(i);
            ans.push_back(n);
        }
        else if(n%4 == 2)
        {
            for(int i=2; i<=n; i++) ans.push_back(i);
        }
        else if(n%4 == 3)
        {
            for(int i=1; i<=n-1; i++) ans.push_back(i);  
        }
        return ans;
    }
};
