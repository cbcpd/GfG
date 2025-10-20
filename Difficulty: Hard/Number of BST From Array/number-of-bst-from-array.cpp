class CatalanProvider{
  public:
    virtual vector<int> getCatalan(int n){
        vector<int> v(n+1, 0);
        v[0] = 1;
        
        for(int i=1;i<=n;i++){
            int c=0;
            
            for(int j=0;j<i;j++){
                c += (v[j]*v[i-1-j]);
            }
            v[i] = c;
        }
        return v;
    }
};
class Solution {
  public:
    vector<int> countBSTs(vector<int>& arr) {
        // Code here
        int n = arr.size();
      vector<int> catalan(n+1, 0);
      CatalanProvider *cp = new CatalanProvider();
      catalan = cp->getCatalan(n);
      
      vector<int> ans(n, 0);
      
      for(int i=0;i<n;i++){
          int left = 0;
          for(int j=0;j<n;j++){
              if(arr[j] < arr[i])
                left++;
          }
          
          int right = n-1-left;
          
          ans[i] = catalan[left]*catalan[right];
      }
      
      return ans;
    }
};