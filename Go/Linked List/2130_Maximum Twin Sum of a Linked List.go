import "math"

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
//method1
//find mid
//reverse second half of LL
//iterate first and second to get sum

//or
//method2
//find middle
//push to stack
//traverse through LL after middle while calculating twin sum

func findMid(head *ListNode) (first, prev *ListNode) {
	if head == nil {
		return nil, nil
	}
	if head.Next == nil {
		return
	}
	first, next := head, head
	for next != nil && next.Next != nil {
		prev = first
		first = first.Next
		next = next.Next.Next
	}
	return first, prev
}

func reverseAndSum(head, mid, prev *ListNode) int {
	if mid == nil {
		return 0
	}
	cur, next := mid, mid
	for cur != nil {
		next = cur.Next
		cur.Next = prev
		prev, cur = cur, next
	}
	//prev now = head of reversed LL
	temp := head
	maxSum := math.MinInt64
	for prev.Next != temp {
		sum := temp.Val + prev.Val
		if sum > maxSum {
			maxSum = sum
		}
		temp, prev = temp.Next, prev.Next
	}
	sum := temp.Val + prev.Val
	if sum > maxSum {
		return sum
	}
	return maxSum
}

func pairSum(head *ListNode) int {
	//find mid
	mid, prev := findMid(head)
	//reverse second half of LL and find sum
	return reverseAndSum(head, mid, prev)
}