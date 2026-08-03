class Solution {
  public:
    int maxSumWithK(vector<int>& arr, int k) {
        // code here
        int i,n=arr.size(),crr=arr[0],ans=0;
        vector<int> mx(n, INT_MIN);
        
        mx[0]=arr[0];
        for(i=1;i<n;i++) {
            crr=max(arr[i], crr+arr[i]);
            mx[i]=crr;
        }
        
        crr=0;
        for(i=0;i<k;i++) crr+=arr[i];
        ans=crr;
        
        
        for(i=k;i<n;i++) {
            crr=crr+arr[i]-arr[i-k];
            ans=max(ans, crr);
            ans=max(ans, crr+mx[i-k]);
        }
        
        
        
        
        
        
        return ans;
    }
};
//GFG POTD solution for 03 August