class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> hash;
        for(auto it: nums) {
            hash[it]++;
        }

        int ans = 0;
        for(int i=0;i<nums.size();i++) {
            if(hash[nums[i]] == 0) continue;
            int cnt = 1;
            hash[nums[i]] = 0;
            int x = nums[i] - 1;
            while(hash[x] > 0) {
                cnt++;
                hash[x] = 0;
                x--;
            }
            int y = nums[i] + 1;
            while(hash[y] > 0) {
                cnt++;
                hash[y] = 0;
                y++;
            }

            ans = max(ans,cnt);
        }

        return ans;
    }
};