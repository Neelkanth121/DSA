class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int odd = 1;
        int oddsum = 1;
        int even = 2;
        int evensum = 2;
        for(int i=1;i<n;i++) {
            odd = odd + 2;
            oddsum = oddsum + odd;
            even = even + 2;
            evensum = evensum + even;
        }
        int ans = 1;
        for(int i=1;i<=odd;i++) {
            if(((oddsum % i) == 0) && ((evensum % i) == 0)) ans = i;
        }

        return ans;
    }
};