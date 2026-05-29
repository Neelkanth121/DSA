class Solution {
public:
    int minElement(vector<int>& nums) {
        int ans = INT_MAX;
        for(int i=0;i<nums.size();i++) {
            int s = 0;
            int N = nums[i];
            while(N > 0) {
                s = s + (N%10);
                N = N/10;
            }
            ans = min(ans,s);
        }
        return ans;
    }
};