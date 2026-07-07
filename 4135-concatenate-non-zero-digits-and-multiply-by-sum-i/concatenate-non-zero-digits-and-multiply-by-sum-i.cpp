class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0;
        long long sum = 0;
        long long dig = 1;
        while(n > 0) {
            if((n%10) != 0) {
                num = num + ((n%10) * dig);
                sum = sum + (n%10);
                dig = dig * 10;
            }
            n = n / 10;
        }
        return num*sum;
    }
};