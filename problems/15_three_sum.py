class Solution(object):
    def threeSum(self, nums):
        res = []
        sorted_nums = sorted(nums)

        for i, num in enumerate(sorted_nums[:-1]):
            if i > 0 and num == sorted_nums[i - 1]:
                continue

            left = i + 1
            right = len(sorted_nums) - 1

            while left < right:
                total = num + sorted_nums[left] + sorted_nums[right]

                if total == 0:
                    res.append([num, sorted_nums[left], sorted_nums[right]])

                    left += 1
                    right -= 1

                    while left < right and sorted_nums[left] == sorted_nums[left - 1]:
                        left += 1

                    while left < right and sorted_nums[right] == sorted_nums[right + 1]:
                        right -= 1

                elif total < 0:
                    left += 1
                else:
                    right -= 1

        return res

"""
class Solution(object):
    def threeSum(self, nums):
        "" "
        :type nums: List[int]
        :rtype: List[List[int]]
        " ""
        s = set()
        for i, num1 in enumerate(nums):
            seen = set()
            for num2 in nums[i + 1:]:
                to_find = -num1 - num2
                if to_find in seen:
                    res = [num1, num2, to_find]
                    max_ = max(res)
                    min_ = min(res)
                    s.add((min_, 0 - max_ - min_, max_))
                seen.add(num2)

        l = []
        for t in s:
            l.append(list(t))
        return l
"""