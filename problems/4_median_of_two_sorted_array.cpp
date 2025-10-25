//Problem: https://leetcode.com/problems/median-of-two-sorted-arrays/
//Difficulty: Hard

// Basic (O(log(m+n)))
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int nums1_size = nums1.size();
        int nums2_size = nums2.size();
        int total_size = nums1_size + nums2_size;
        int total_middle = (total_size + 1) / 2;
        bool total_even = total_size % 2 == 0;

        // Make nums 1 smaller
        if (nums2_size < nums1_size)
            return findMedianSortedArrays(nums2, nums1);

        // Set window for nums1
        int window_left = 0;
        int window_right = nums1_size;

        while (window_left <= window_right)
        {
            // Set the upper bounds of the middle values
            int mid1_index = (window_right + window_left) / 2;
            int mid2_index = total_middle - mid1_index;

            // Define the middle values
            int lmid1 = (mid1_index > 0) ? nums1[mid1_index - 1] : INT_MIN;
            int rmid1 = (mid1_index < nums1_size) ? nums1[mid1_index] : INT_MAX;
            int lmid2 = (mid2_index > 0) ? nums2[mid2_index - 1] : INT_MIN;
            int rmid2 = (mid2_index < nums2_size) ? nums2[mid2_index] : INT_MAX;


            // End conditions (if the 4 values are the 4 middle vals)
            if (lmid1 <= rmid2 && lmid2 <= rmid1)
            {
                if (total_even)
                {
                    return (max(lmid1, lmid2) + min(rmid1, rmid2)) / 2.0;
                }
                else 
                {
                    return max(lmid1, lmid2);
                }
            }
            // No solutions found, adjusting windows
            if (rmid1 < lmid2)
            {
                window_left = mid1_index + 1;
            }
            else 
            {
                window_right = mid1_index - 1;
            }

        }
        return 0.0;
    }
};