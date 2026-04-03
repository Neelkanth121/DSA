class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        if(num.size()==k){
            return "0";
        }
        for(int i=0;i<num.size();i++){
            while(!st.empty() && int(st.top())>int(num[i]) && k>0){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k>0){
            st.pop();
            k--;
        }
        string ans = "";
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        while(ans.size() > 0 && ans[0]=='0'){
            ans.erase(0,1);
        }
        if(ans.empty()){
            ans = "0";
        }
        return ans;
    }
};