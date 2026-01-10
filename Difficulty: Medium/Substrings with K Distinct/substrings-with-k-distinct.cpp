
class Solution {
  public:
  
    int helper(string &s, int k) {
        int n = s.length();
        vector<int> mp(26, 0);
        int cnt = 0;
        int i = 0, j = 0, ans = 0;
        
        
        while(j < n) {
            mp[s[j] - 'a']++;
            
            if(mp[s[j] - 'a'] == 1) cnt++;
            
            while(cnt > k) {
                mp[s[i] - 'a']--;
                if(mp[s[i] - 'a'] == 0) cnt--;
                i++;
            }
            
            j++;
            ans += (j-i+1);
        }
        
        return ans;
    }
  
    int countSubstr(string& s, int k) {
        // code here.
        return helper(s,k) - helper(s,k-1);
    }
};