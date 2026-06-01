class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int ans = 0;
        sort(cost.begin(),cost.end());
        int left = cost.size() - 2;
        while(left >= 0) {
            ans = ans + cost[left] + cost[left + 1];
            left = left - 3;
        }
        if((left + 1) >= 0) {
            ans = ans + cost[left + 1];
        }
        if(ans == 0) return cost[0];
        return ans;
    }
};