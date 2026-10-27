class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maximum = 0;
        int left = 0, right = heights.size() - 1;
        while (left < right){
            int product = min(heights[left], heights[right]) * (right - left);
            maximum = max(maximum, product);
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return maximum;
    }
};
