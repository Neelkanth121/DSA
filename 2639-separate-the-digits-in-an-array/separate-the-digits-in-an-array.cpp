class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        stack<int> st;
        for(int i=0; i<nums.size(); i++){
            int n = nums[i];
            while(n>0){
                st.push(n%10);
                n = n/10;
            }
            while(!st.empty()){
                ans.push_back(st.top());
                st.pop();
            }
        }
        return ans;
    }
};