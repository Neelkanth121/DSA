class Solution {
public:
    void nextGreaterElement(vector<int>& height,vector<int>& next) {
        stack<int> st;
        for(int i=height.size() - 1;i>=0;i--) {
            while((!st.empty()) && (st.top() <= height[i])) st.pop();
            if(st.empty()) next[i] = -1;
            else{
                next[i] = st.top();
            }
            if((!st.empty()) && (st.top() < height[i])) st.push(height[i]);
            if(st.empty()) st.push(height[i]);
        }
    }
    void lastGreaterElement(vector<int>& height,vector<int>& next) {
        stack<int> st;
        for(int i=0;i<height.size();i++) {
            while((!st.empty()) && (st.top() <= height[i])) st.pop();
            if(st.empty()) next[i] = -1;
            else{
                next[i] = st.top();
            }
            if((!st.empty()) && (st.top() < height[i])) st.push(height[i]);
            if(st.empty()) st.push(height[i]);
        }
    }
    int trap(vector<int>& height) {
        vector<int> next(height.size(),0);
        vector<int> last(height.size(),0);
        nextGreaterElement(height,next);
        lastGreaterElement(height,last);
        int result = 0;
        for(int i=0;i<height.size();i++) {
            if(next[i] == -1 || last[i] == -1) continue;
            int a = min(last[i],next[i]);
            result = result + (a - height[i]);
        }
        return result;
    }
};