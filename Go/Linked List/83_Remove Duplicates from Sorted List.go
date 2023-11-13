/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func deleteDuplicates(head *ListNode) *ListNode {
	cur := head
	if head == nil {
		return nil
	}
	next := head.Next
	for next != nil {
		if next.Val != cur.Val {
			cur, next = cur.Next, next.Next
		} else {
			cur.Next = next.Next
			next = next.Next
		}
	}
	return head
} 