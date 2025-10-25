//Problem: https://leetcode.com/problems/longest-palindromic-substring/
//Difficulty: Medium

// Basic (O(n²))
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1)
        {
            return s;
        }
        if (s.length() == 2 && s[0] == s[1])
        {
            return s;
        }
        if (s.length() == 2)
        {
            return string() + s[0]; 
        }
        string longest;
        for (int i = 1; i < s.length() - 1; i++)
        {
            string palyndrome = string() + s[i]; 
            int j_inc = i + 1;
            int j_dec = i - 1;
            while (j_dec >= 0 && s[i] == s[j_dec])
            {
                palyndrome.insert(palyndrome.begin(), s[j_dec]); 
                j_dec--;
            }
            while (j_inc < s.length() && s[i] == s[j_inc])
            {
                palyndrome.push_back(s[j_inc]);
                j_inc++;
            }        
            while (j_dec >= 0 && j_inc < s.length())
            {
                if (s[j_dec] == s[j_inc])
                {
                    palyndrome.insert(palyndrome.begin(), s[j_dec]); 
                    palyndrome.push_back(s[j_inc]);
                    j_inc++;
                    j_dec--;
                    continue;
                }
                break;
            }
            longest = (longest.length() >= palyndrome.length()) ? longest : palyndrome;
        }
        return longest;
    }
};