class Solution {
    int n, m;
    Integer[][] dp;
    public int count(int n, int m) {
        // code here
        this.n = n;
        this.m = m;
        dp = new Integer[n][m+1];
        int ans = 0;
        for(int i = 1; i <= m; i++){
            ans += help(1, i);
        }
        return ans;
    }
    private int help(int id, int prev){
        if(id == n){
            return 1;
        }
        if(dp[id][prev] != null) return dp[id][prev];
        int ans = 0;
        for(int i = 1; i <= m; i++){
            if(prev%i == 0 || i%prev == 0){
                ans += help(id+1, i);
            }
        }
        return dp[id][prev] = ans;
    }
}