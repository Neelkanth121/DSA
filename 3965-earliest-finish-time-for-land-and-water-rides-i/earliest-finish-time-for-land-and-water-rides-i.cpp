class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int n = ls.size();
        int m = ws.size();
        int ans = INT_MAX;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                int time = ls[i] + ld[i];
                if(time < ws[j]) {
                    time = ws[j] + wd[j];
                }
                else{
                    time = time + wd[j];
                }
                ans = min(time,ans);
            }
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                int time = ws[i] + wd[i];
                if(time < ls[j]) {
                    time = ls[j] + ld[j];
                }
                else{
                    time = time + ld[j];
                }
                ans = min(time,ans);
            }
        }
        return ans;
    }
};