
class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        map<int,int> mp;
        
        for(int i=0;i<k-1;i++){
            mp[arr[i]]++;
           
        }
        
        vector<int> ans;
        for(int i=k-1;i<arr.size();i++){
            mp[arr[i]]++;
           
            if(i-k>=0){
                if(mp[arr[i-k]]==1)
                mp.erase(arr[i-k]);
                else
                mp[arr[i-k]]--;
            }
            
            map<int,int>:: iterator it=prev(mp.end());
           
            ans.push_back(it->first);
        }
        return ans;
    }
};
