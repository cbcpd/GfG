
class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int j = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){ // it move none-zero element in left
            if (arr[i] != 0){
                arr[j++] = arr[i];
            }
        }
        while(j<n){ // it fill zero in remaining prositions
            arr[j++] = 0;
        }
    }
};