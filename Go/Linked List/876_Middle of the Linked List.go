/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func middleNode(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	cur := head
	next := cur
	for next != nil && next.Next != nil {
		cur, next = cur.Next, next.Next.Next
	}
	return cur
}