class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int lowV = 0, highV = n - 1;
        while (lowV <= highV){
            int midV = lowV + (highV - lowV) / 2;
            int m = matrix[midV].size();
            int low = 0, high = m - 1;

            if (target < matrix[midV][low]) highV = midV - 1;
            else if (target > matrix[midV][high]) lowV = midV + 1;
            else {
                while (low <= high){
                    int mid = low + (high - low) / 2;
                    if (matrix[midV][mid] == target) return true;
                    else if (target > matrix[midV][mid]) low = mid + 1;
                    else high = mid - 1;
                }
                return false;
            }
        }
        return false;
    }
};
