class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = (m * n) - 1;
        while(right>=left){
            int mid = (left + right)/2;
            if(target > matrix[mid/m][mid%m]){
                left = mid + 1;
            }
            else if(target < matrix[mid/m][mid%m]){
                right = mid - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};