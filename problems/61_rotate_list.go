package problems

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil {
		return head
	}

	current := head
	len := 1
	for current.Next != nil {
		len++
		current = current.Next
	}

	newHeadIndex := len - (k % len)
	if newHeadIndex == len {
		return head
	}

	var prevNewHead *ListNode
	newHead := head
	for _ = range newHeadIndex {
		prevNewHead = newHead
		newHead = newHead.Next
	}
	prevNewHead.Next = nil

	current = newHead
	for current.Next != nil {
		current = current.Next
	}
	current.Next = head

	return newHead
}
