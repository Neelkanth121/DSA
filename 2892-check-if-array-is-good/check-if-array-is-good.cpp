class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> hash;
        int max_num = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            max_num = max(max_num,nums[i]);
        }
        for(int i = 0;i<nums.size();i++){
            hash[nums[i]]++;
            if((max_num != nums[i]) && (hash[nums[i]] > 1)) return false;
        }
        if((nums.size() != max_num+1) || (hash[max_num]!=2)) return false;
        return true;
    }
};