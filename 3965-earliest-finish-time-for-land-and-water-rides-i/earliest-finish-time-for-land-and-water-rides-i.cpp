class Solution {
public:
    int solve(vector<int>& start1,vector<int>& duration1,vector<int>& start2,vector<int>& duration2) {
        int finish1 = INT_MAX;
        for(int i=0;i<start1.size();i++) {
            finish1 = min(finish1,(start1[i] + duration1[i]));
        }
        int finish2 = INT_MAX;
        for(int i=0;i<start2.size();i++) {
            finish2 = min(finish2,(max(finish1,start2[i]) + duration2[i]));
        }
        return finish2;
    }
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws, vector<int>& wd) {
        int water_land = solve(ls,ld,ws,wd);
        int land_water = solve(ws,wd,ls,ld);
        return min(water_land,land_water);
    }
};