//Problem: https://leetcode.com/problems/string-to-integer-atoi/
//Difficulty: Medium

class Solution {
public:
    int myAtoi(string s) {
        if (s.size() == 0)
            return 0;

        // Find the symbol and first digit placement
        bool positive = true;
        int idx;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
                continue;
            else if (s[i] == '-')
            {
                positive = false;
                idx = i + 1;
                break;
            }
            else if (s[i] == '+')
            {
                idx = i + 1;
                break;
            }
            else if (s[i] >= '0' && s[i] <= '9')
            {
                idx = i;
                break;
            }
            else
                return 0;
        }

        int num = 0;
        int tenth_power = 0;

        // convert to number
        for (int i = idx; i < s.size(); i++)
        {
            if (s[i] < '0' || s[i] > '9')
                return num;
            else if (positive)
            {
                int digit = s[i] - '0';
                if ((std::numeric_limits<int>::max() - digit) / 10 < num)
                    return std::numeric_limits<int>::max();
                num = num * 10 + digit;
            }
            else
            {
                int digit = s[i] - '0';
                if ((std::numeric_limits<int>::min() + digit) / 10 > num)
                    return std::numeric_limits<int>::min();
                num = num * 10 - digit;
            }
        }
        return num;
    }
};