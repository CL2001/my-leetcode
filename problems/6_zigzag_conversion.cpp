class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;

        string output(s.size(), ' ');

        // Define pattern
        int pattern_loop = (numRows - 1) * 2;
        vector<string> row(numRows);
        int max_per_row = s.size() / pattern_loop + 1;
        for (int i = 0; i < numRows; i ++)
        {
            row[i].reserve(max_per_row);
        }

        // Add values to new row strings
        for (int i = 0; i < s.size(); i++)
        {
            int num_in_pattern = i % pattern_loop;
            if (num_in_pattern < numRows)
            {
                row[num_in_pattern].push_back(s[i]);
            }
            else 
            {
                row[2 * numRows - num_in_pattern - 2].push_back(s[i]);
            }
        }

        // Concact the strings
        string final_str = row[0];
        for (int i = 1; i < numRows; i++)
        {
            final_str += row[i];
        }
        return final_str;

    }
};