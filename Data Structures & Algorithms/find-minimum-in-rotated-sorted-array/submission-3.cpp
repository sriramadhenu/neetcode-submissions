class Solution {
public:
    int findMin(vector<int> &nums) {
        // find the minimum in the vector
        // if the first index is less than the last index, no rotations, or [size] amount of rotations
        int n = nums.size();
        int low = 0, high = n - 1;
        if (nums[low] < nums[high]){
            return nums[low];
        } else {
            // do a variant of binary search
            // find the midpoint (mid)
            // if nums[mid] is greater than nums[low], the smallest number is on the right half
            // if nums[mid] is less than nums[low], the smallest number is on the left half
            // nums[mid] CANNOT be less than nums[low] AND greater than nums[high]
            while (low < high){
                int mid = low + (high - low) / 2;
                if (nums[mid] > nums[high]) low = mid + 1;
                else high = mid;
            }
        }
        return nums[low];
    }
};
