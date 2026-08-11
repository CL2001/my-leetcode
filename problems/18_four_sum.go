package problems

import "sort"

func fourSum(nums []int, target int) [][]int {

	res := make([][]int, 0, 10)

	sort.Slice(nums, func(i, j int) bool {
		return nums[i] < nums[j]
	})

	for i := 0; i < len(nums)-3; i++ {
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		for j := i + 1; j < len(nums)-2; j++ {
			if j-1 != i && nums[j] == nums[j-1] {
				continue
			}

			left := j + 1
			right := len(nums) - 1

			for left < right {
				total := nums[i] + nums[j] + nums[left] + nums[right]
				if total == target {
					res = append(res, []int{nums[i], nums[j], nums[left], nums[right]})
					left++
					right--

					for left < right && nums[left] == nums[left-1] {
						left++
					}
					for left < right && nums[right] == nums[right+1] {
						right--
					}
				} else if total < target {
					left++
				} else {
					right--
				}
			}
		}
	}
	return res
}
