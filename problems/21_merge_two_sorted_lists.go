package problems

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {
	if list1 == nil && list2 == nil {
		return list1
	} else if list1 == nil {
		return list2
	} else if list2 == nil {
		return list1
	}

	var rList *ListNode
	if list1.Val <= list2.Val {
		rList = list1
		list1 = list1.Next
		rList.Next = nil
	} else {
		rList = list2
		list2 = list2.Next
		rList.Next = nil
	}

	current := rList
	for list1 != nil || list2 != nil {
		if list1 == nil {
			current.Next = list2
			return rList
		}
		if list2 == nil {
			current.Next = list1
			return rList
		}

		if list1.Val <= list2.Val {
			current.Next = list1
			list1 = list1.Next
			current.Next.Next = nil
		} else {
			current.Next = list2
			list2 = list2.Next
			current.Next.Next = nil
		}
		current = current.Next

	}

	return rList
}
