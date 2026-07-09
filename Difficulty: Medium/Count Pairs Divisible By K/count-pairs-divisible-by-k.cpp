class Solution {
  public:
    int countKdivPairs(vector<int>& arr, int k) {
        // code here
        vector<int> rem(k,0);
            
        int n= arr.size();
        for(int i=0;i<n;i++){
            rem[arr[i]%k]++;
        }
        int i=1;
        int j=k-1;
        int ans=0;
        while(i<j){
            ans=ans+(rem[i]*rem[j]);
            i++;
            j--;
        }
        if(k%2==0){
            ans+=(rem[k/2]*(rem[k/2]-1))/2;
        }
        return ans+(rem[0]*(rem[0]-1))/2;
        
        
    }
};