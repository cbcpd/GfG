
class Solution {
  public:
    int minOperations(vector<int>& arr) {
        double sum = 0.0;
        priority_queue<float> pq;
        
        for(auto i : arr){
            pq.push(i);
            sum += i;
        }
        
        double half = sum / 2;
        int res = 0;
        
        while(sum > half){
            float num = pq.top(); pq.pop();
            num /= 2;
            sum  = (double)sum - num;
            pq.push(num);
            res++;
        }
        return res;
    }
};