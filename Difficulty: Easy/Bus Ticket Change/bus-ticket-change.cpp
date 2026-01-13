class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int fiveCount=0;
        int tenCount=0;
        for(auto it:arr){
            if(it==5) fiveCount++;
            else if(it==10){
                tenCount++;
                fiveCount--;
                if(fiveCount<0) return false;
            }
            else{
                if(tenCount<=0){
                    fiveCount-=2;
                }
                else tenCount--;
                fiveCount--;
                if(fiveCount<0) return false;
            }
        }
        return true;
    }
};