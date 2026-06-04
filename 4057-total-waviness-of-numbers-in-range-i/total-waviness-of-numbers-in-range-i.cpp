class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        while((log10(num1) <= 2) && (num1 <= num2)) {
            num1++;
        }
        if(num1 > num2) return 0;
        for(int i=num1;i<=num2;i++) {
            int left = 0;
            string n1 = to_string(i);
            for(int j=1;j<n1.size() - 1;j++) {
                if((n1[j-1] - '0') < (n1[j] - '0')) {
                    if((n1[j] - '0') > (n1[j + 1] - '0')) ans++;
                }
                if((n1[j-1] - '0') > (n1[j] - '0')) {
                    if((n1[j] - '0') < (n1[j + 1] - '0')) ans++;
                }
            }
        }
        return ans;
    }
};