//Problem: https://leetcode.com/problems/two-sum/
//Difficulty: Easy

// Basic (O(n²))
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> sol(2);
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (target == nums[i] + nums[j])
                {
                    sol[0] = i;
                    sol[1] = j;
                    return sol;
                }
            }
        }
        return sol;
    }
};


// Hash table (std::unordered_map) (O(n))
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> sol(2);
        unordered_map<int, int> searched;
        for (int i = 0; i < nums.size(); i++)
        {
            int remainder = target - nums[i];
            auto it = searched.find(remainder);
            if (it != searched.end())
            {
                sol[0] = it->second;
                sol[1] = i;
                return sol;
            }
            searched[nums[i]] = i;
        }
        return sol;
    }
};