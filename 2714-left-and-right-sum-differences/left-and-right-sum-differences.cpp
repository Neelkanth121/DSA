class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        int s1 = 0;
        for(int i=nums.size() - 2;i >= 0;i--) {
            s1 = s1 + nums[i + 1];
            st.push(s1);
        }
        vector<int> ans;
        ans.push_back(st.top());
        st.pop();
        int sum = 0;
        for(int i=1;i<nums.size();i++) {
            sum = sum + nums[i - 1];
            int a = abs(st.top() - sum);
            ans.push_back(a);
            st.pop();
        }
        return ans;
    }
};