class Solution {
public:
    int helper(vector<int>& finish1, vector<int>& duration1, vector<int>& finish2, vector<int>& duration2) {
        int one = INT_MAX;
        for(int i=0;i<finish1.size();i++) {
            one = min(one,(finish1[i] + duration1[i]));
        }
        int second = INT_MAX;
        for(int i=0;i<finish2.size();i++) {
            second = min(second,max(one,finish2[i]) + duration2[i]);
        }
        return second;
    }
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int water_land = helper(ls,ld,ws,wd);
        int land_water = helper(ws,wd,ls,ld);
        return min(water_land,land_water);
    }
};