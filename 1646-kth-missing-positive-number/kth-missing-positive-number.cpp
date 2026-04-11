class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int i = 0;
        int num = 1;
        while(k>0){ 
            if(i<arr.size() && (num == arr[i])){
                i++;
                k++;
            }
            num++;
            k--;
        }
        return num-1;
    }
};