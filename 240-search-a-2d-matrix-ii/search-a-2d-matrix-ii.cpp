class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0;i<matrix.size();i++){
            int left = 0;
            int right = matrix[0].size()-1;
            while(right>=left){
                int mid = left + (right - left) / 2;
                if(matrix[i][mid] > target){
                    right = mid - 1;
                }
                else if(matrix[i][mid] < target){
                    left = mid + 1;
                }
                else{
                    return true;
                }
            }
        }
        return false;
    }
};