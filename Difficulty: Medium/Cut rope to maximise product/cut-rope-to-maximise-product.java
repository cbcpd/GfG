class Solution {
    int dp[];
    public int maxProduct(int n) {
        // code here
        dp = new int[n+1];
        Arrays.fill(dp, -1);
        return fun(n);
        
    }
    
    int fun(int n){
        
        if(n==0 || n==1)
        return 0;
        
        if(dp[n]!=-1)
        return dp[n];
        
        int ans=0;
        for(int i=1; i<n; i++){
            //cut at i
            int curr_prod = i*(n-i);
            int rem_prod = i*fun(n-i);
            ans = Math.max(ans, Math.max(curr_prod,rem_prod ));
        }
       return dp[n]=ans;
        
    }
}
