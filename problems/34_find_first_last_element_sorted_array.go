func searchRange(nums []int, target int) []int {
	start := 0
	end := len(nums) - 1

	index := -1

	for start <= end {
		middle := start + (end-start)/2
		if nums[middle] == target {
			index = middle
			break
		} else if nums[middle] > target {
			end = middle - 1
		} else {
			start = middle + 1
		}
	}

	if index == -1 {
		return []int{-1, -1}
	}

	first := -1
	first_start := 0
	first_end := index
	for first_start <= first_end {
		middle := first_start + (first_end-first_start)/2
		if middle == 0 && nums[middle] == target {
			first = middle
			break
		} else if middle > 0 && (nums[middle] == target && nums[middle-1] != target) {
			first = middle
			break
		} else if nums[middle] == target {
			first_end = middle - 1
		} else {
			first_start = middle + 1
		}
	}

	last := -1
	last_start := index
	last_end := len(nums) - 1
	for last_start <= last_end {
		middle := last_start + (last_end-last_start)/2
		if middle == len(nums)-1 && nums[middle] == target {
			last = middle
			break
		} else if middle < len(nums)-1 && (nums[middle] == target && nums[middle+1] != target) {
			last = middle
			break
		} else if nums[middle] == target {
			last_start = middle + 1
		} else {
			last_end = middle - 1
		}
	}

	return []int{first, last}
}