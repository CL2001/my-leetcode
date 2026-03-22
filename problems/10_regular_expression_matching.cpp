//Problem: https://leetcode.com/problems/regular-expression-matching/
//Difficulty: Hard


class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();

        bool match = !s.empty() && (p[0] == '.' || s[0] == p[0]);

        if (p.size() > 1 && p[1] == '*')
            return isMatch(s, p.substr(2)) || (match && isMatch(s.substr(1), p));

        return match && isMatch(s.substr(1), p.substr(1));
    }
};