/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil || (head.Next == nil && n == 1) {
		return nil
	}
	p2 := &ListNode{Next: head}
	count := n //2
	for i := 0; i < count; i++ {
		p2 = p2.Next
	}
	p1 := &ListNode{Next: head}
	for p2.Next != nil {
		p1, p2 = p1.Next, p2.Next
	}
	p1.Next = p1.Next.Next
	return head
}