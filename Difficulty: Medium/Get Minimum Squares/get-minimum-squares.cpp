
class Solution {
  public:
    bool isSquare(int x) {
    int sqRoot = sqrt(x);
    return (sqRoot * sqRoot == x);
}

// Function to count minimum squares that sum to n
int minSquares(int n) {
  
    // Case 1: ans = 1 if the number itself is a 
   // perfect square
    if (isSquare(n)) {
        return 1;
    }

    // Case 2: ans = 2 if the number is a sum of 
   // two perfect square
    // we check for each i if n - (i * i) is a perfect
    // square
    for (int i = 1; i * i <= n; i++) {
        if (isSquare(n - (i * i))) {
            return 2;
        }
    }

    // Case 4: ans = 4 if the number is a sum of 
   // four perfect square
    // possible if the number is representable in the form
    // 4^a (8*b + 7).
    while (n > 0 && n % 4 == 0) {
        n /= 4;
    }
    if (n % 8 == 7) {
        return 4;
    }

    // since all the other cases have been evaluated, 
   // the answer can only then be 3 if the program 
   // reaches here
    return 3;
}
};