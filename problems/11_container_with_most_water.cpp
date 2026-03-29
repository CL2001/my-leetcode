//Problem: https://leetcode.com/problems/container-with-most-water/
//Difficulty: Medium

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_vol = 0;

        while (right > left)
        {
            int dist = right - left;
            int smaller = min(height[left], height[right]);
            int vol = smaller * dist;
            max_vol = max(max_vol, vol);

            if (smaller == height[left])
                left++;
            else
                right--;
        }
        return max_vol;

    }
};