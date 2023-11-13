import "math"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func rotateRight(head *ListNode, k int) *ListNode {
	if head == nil || head.Next == nil || k == 0 {
		return head
	}

	temp := head
	var count int = 1
	for temp.Next != nil {
		temp = temp.Next
		count += 1
	}
	if k > count {
		k = k % count
	}
	reqCount := int(math.Abs(float64(count - k)))
	if reqCount == 0 || k == 0 {
		return head
	}
	temp = head
	count = 1
	for temp.Next != nil {
		if count == reqCount {
			break
		}
		temp = temp.Next
		count += 1
	}
	headOrg := head
	head = temp.Next
	temp.Next = nil
	temp = head
	for temp.Next != nil {
		temp = temp.Next
	}
	temp.Next = headOrg
	return head
}