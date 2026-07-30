class Solution {
public:
    int maxArea(vector<int>& heights) {
        int bestArea = 0;

        int left = 0, right = heights.size() - 1;
        while (left < right){
            int height = min(heights[left], heights[right]);
            int width = right - left;
            int area = height * width;
            bestArea = max(bestArea, area);
            if (heights[left] < heights[right]) left++;
            else right--;
        }
        return bestArea;
    }
};
