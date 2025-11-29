
class Solution {
  public:
    int countSetBits(int n) {
        if (n == 0) return 0;
    
        int msb = log2(n);
        int p = 1 << msb;
    
        int bitsBeforeP = msb * (1 << (msb - 1));
    
        int msbBits = n - p + 1;
    
        int rest = countSetBits(n - p);
    
        return bitsBeforeP + msbBits + rest;
    }

};
