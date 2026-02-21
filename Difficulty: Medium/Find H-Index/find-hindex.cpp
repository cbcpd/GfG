
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0, high = n;

        while(low <= high){
            int mid = (low + high)/2;
            int count = 0;

            for(int c : citations)
                if(c >= mid) count++;

            if(count >= mid)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return high;
    }
};