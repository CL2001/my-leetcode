//Problem: https://leetcode.com/problems/longest-substring-without-repeating-characters/
//Difficulty: Medium

// Basic (O(n))
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        
        int max = 0;
        int back = -1;
        unordered_map<char, int> searched;
        for (int front = 0; front < s.size(); front++)
        {   
            auto it = searched.find(s[front]);
            if (it != searched.end())
            {
                int new_back = it->second;
                for (int i = back + 1; i < new_back + 1; i++)
                {
                    searched.erase(s[i]);
                }
                back = new_back;
            }
            else {
                int current_size = front - back;
                max = (current_size > max) ? current_size : max;
            }
            searched[s[front]] = front;
        }
        return max;
    }
};