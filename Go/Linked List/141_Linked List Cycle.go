/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func hasCycle(head *ListNode) bool {
	first, next := head, head
	for next != nil && next.Next != nil {
		first = first.Next
		next = next.Next.Next
		if first == next {
			return true
		}
	}
	return false
}