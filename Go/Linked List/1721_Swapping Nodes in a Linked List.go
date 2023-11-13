/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func swapNodes(head *ListNode, k int) *ListNode {
	cur := head
	count := 1
	for count < k {
		count += 1
		cur = cur.Next
	}
	temp := head
	for next := cur.Next; next != nil; next = next.Next {
		temp = temp.Next
	}
	cur.Val, temp.Val = temp.Val, cur.Val
	return head
}
