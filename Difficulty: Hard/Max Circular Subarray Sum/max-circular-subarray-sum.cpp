
class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int mx=INT_MIN,curr=0,total=0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
            curr+=arr[i];
            if(mx<curr)
                mx=curr;
            if(curr<0)
                curr=0;
        }
        // cout<<curr<<":"<<mx<<":"<<total;
        curr = arr[0];
        int mn = arr[0];
    
        for(int i = 1; i < arr.size(); i++) {
            curr+=arr[i];
            if(curr>arr[i])
            curr =arr[i];
            if(mn>curr)
            mn = curr;
        }
        if(mx<0)
            return mx;
        // cout<<total<<":"<<mx<<":"<<mn<<endl;

        return max(mx,total-mn);
    }
};