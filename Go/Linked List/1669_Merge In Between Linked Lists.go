/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func mergeInBetween(list1 *ListNode, a int, b int, list2 *ListNode) *ListNode {
	cur := list1
	temp := &ListNode{}
	count := 0
	for cur != nil {
		if count == a-1 {
			temp = cur.Next
			cur.Next = list2
			break
		}
		cur = cur.Next
		count += 1
	}
	count += 1
	temp1 := cur
	for temp1.Next != nil {
		temp1 = temp1.Next
	}
	for temp != nil {
		if count == b+1 {
			temp1.Next = temp
		}
		count += 1
		temp = temp.Next
	}
	return list1
}