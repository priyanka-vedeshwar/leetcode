/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */

func mergeTwoLists(list1 *ListNode, list2 *ListNode) *ListNode {

	if list1 == nil {
		return list2
	}
	if list2 == nil {
		return list1
	}
	if list1.Val > list2.Val {
		temp := list2
		list2 = list1
		list1 = temp
	}
	beg1, beg2 := list1, list2
	for beg1.Next != nil && beg2 != nil {
		if beg2.Val >= beg1.Val && beg2.Val < beg1.Next.Val {
			temp := beg2.Next
			beg2.Next = beg1.Next
			beg1.Next = beg2
			beg2 = temp
		}
		beg1 = beg1.Next
	}
	if beg2 != nil {
		beg1.Next = beg2
	}
	return list1
}