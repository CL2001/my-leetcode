//Problem: https://leetcode.com/problems/reverse-integer/
//Difficulty: Medium

class Solution {
public:
    int reverse(int x)
    {
        std::string x_str = std::to_string(x);
        std::reverse(x_str.begin(), x_str.end());

        if (x_str.back() == '-')
        {
            x_str.pop_back();
            x_str = '-' + x_str;
        }

        int n_x;
        try
        {
            n_x = std::stoi(x_str);
        }
        catch (exception)
        {
            n_x = 0;
        }

        return n_x;
    }
};