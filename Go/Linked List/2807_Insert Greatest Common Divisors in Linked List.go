/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func findGCD(a, b int) int {
	var check, limit int
	if a < b {
		limit, check = a, b
	}
	limit, check = b, a
	gcd := 0
	for i := 1; i <= limit; i++ {
		if (check%i) == 0 && (limit%i) == 0 {
			if i > gcd {
				gcd = i
			}
		}
	}
	if gcd == 0 {
		return limit
	}
	return gcd
}
func insertGreatestCommonDivisors(head *ListNode) *ListNode {
	temp := head
	for temp.Next != nil {
		next := temp.Next
		gcd := findGCD(temp.Val, next.Val)
		newNode := &ListNode{Val: gcd, Next: next}
		temp.Next = newNode
		temp = next
		next = temp.Next
	}
	return head
}