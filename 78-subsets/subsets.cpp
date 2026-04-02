class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sub_set;
        int n = nums.size();
        int m = 1<<n;
        for(int i = 0;i<m;i++){
            vector<int> temp={};
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    temp.push_back(nums[j]);
                }
            }
            sub_set.push_back(temp);
        }
        return sub_set;
    }
};