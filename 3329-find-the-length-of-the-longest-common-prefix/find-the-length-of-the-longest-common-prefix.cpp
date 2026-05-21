class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> hash;
        for(int i=0;i<arr1.size();i++) {
            int n = arr1[i];
            int div = 1;
            while((n/div) > 0) {
                hash[n/div]++;
                div = div*10;
            }
        }
        int ans = 0;
        for(int i=0;i<arr2.size();i++) {
            int n = arr2[i];
            int div = 1;
            while((n/div) > 0) {
                if(hash[n/div] > 0) {
                    int len = log10(n/div) + 1;
                    ans = max(ans,len);
                }
                div = div*10;
            }
        }
        return ans;
    }
};