/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type Linkedlist struct {
	head *ListNode
}

func (list *Linkedlist) Add(val int) {
	node := &ListNode{Val: val, Next: nil}
	if list.head == nil {
		list.head = node
		return
	}
	temp := list.head
	for temp.Next != nil {
		temp = temp.Next
	}
	temp.Next = node
}

func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
	p1 := l1
	p2 := l2
	res := &Linkedlist{}
	sum, rem := 0, 0
	for p1 != nil && p2 != nil {
		sum = ((p1.Val+p2.Val)%10 + rem) % 10
		rem = (p1.Val + p2.Val + rem) / 10
		res.Add(sum)
		p1 = p1.Next
		p2 = p2.Next
	}
	if p2 == nil {
		for p1 != nil {
			sum = ((p1.Val + rem) % 10) % 10
			rem = (p1.Val + rem) / 10
			res.Add(sum)
			p1 = p1.Next
		}
	} else if p1 == nil {
		for p2 != nil {
			sum = ((p2.Val + rem) % 10) % 10
			rem = (p2.Val + rem) / 10
			res.Add(sum)
			p2 = p2.Next
		}
	}
	if rem != 0 {
		res.Add(rem)
	}
	return res.head
}