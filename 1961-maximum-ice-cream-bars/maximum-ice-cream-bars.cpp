class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        for(int i=0;i<costs.size();i++) {
            maxi = max(maxi,costs[i]);
        }

        vector<int> hash(maxi + 1,0);
        for(int i=0;i<costs.size();i++) {
            hash[costs[i]]++;
        }
        
        int ans = 0;
        for(int i=1;i<=maxi;i++) {
            for(int j=1;j<=hash[i];j++) {
                coins = coins - i;
                if(coins < 0) return ans;
                ans++;
            }
        }
        return ans;
    }
};