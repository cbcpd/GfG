
class Solution {
  public:
    int maxScore(string &s, vector<vector<char>> &jumps) {
        // code here
        int n=s.length();
        vector<int>graph[26];
        for(auto &pr:jumps){
            int u=pr[0]-'a';
            int v=pr[1]-'a';
            if(u==v)continue;
            graph[u].push_back(v);
        }
        
        for(int i=0;i<26;i++){
            graph[i].push_back(i);
        }
        
        vector<int>prefix(n+1,0),dp(n+1,0);
        
        vector<vector<int>> charPrefix(26,vector<int>(n+1,0));
        
        for(int i=0;i<26;i++){
            
            for(int j=1;j<=n;j++){
                
                int ele=s[j-1]-'a';
                charPrefix[i][j]+=charPrefix[i][j-1];
                if(ele==i){
                    charPrefix[i][j]+=int(s[j-1]);
                }
                
            }
        }
        // cout<<endl;
        vector<int>pos(26,-1);
        int ans=0;
        
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+int(s[i-1]);
        }
        for(int i=n;i>=1;i--){
            
            int curEle=(s[i-1]-'a');
            
            for(auto &prev:graph[curEle]){
                int forwPos=pos[prev];
                if(forwPos==-1)continue;
                int sameCharPrefix=charPrefix[prev][forwPos]-charPrefix[prev][i-1];
                int tp=dp[forwPos]+ (prefix[forwPos]-prefix[i-1]-sameCharPrefix);
                // cout<<i<<" " <<forwPos<<" "<<sameCharPrefix<<" " <<tp<<endl;
                dp[i]=max(dp[i],tp);
            }
          
                 pos[curEle]=i;
        
           
        }
        
        return dp[1];
    }
};