
class Solution {
  public:
    virtual int getDistanceFromOrigin(vector<int> &v){
        return (v[0]*v[0] + v[1]*v[1]);
    }
    
    virtual vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
      vector<vector<int>> ans;
      priority_queue<pair<int, int>> maxHeap;
      
      int n = points.size();
      
      for(int i=0;i<n;i++){
          int distance = getDistanceFromOrigin(points[i]);
          maxHeap.push({distance, i});
          
          if(maxHeap.size() > k)
            maxHeap.pop();
      }
      
      while(!maxHeap.empty()){
          auto z = maxHeap.top();
          maxHeap.pop();
          int i=z.second;
          ans.push_back(points[(z.second)]);
      }
      
      return ans;
    }
};