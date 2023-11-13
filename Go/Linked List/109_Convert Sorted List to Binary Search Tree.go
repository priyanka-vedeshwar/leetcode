/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findMiddle(start, end *ListNode) *ListNode {
	if start == end {
		return nil
	}
	beg, next := start, start
	for next != end && next.Next != end {
		beg = beg.Next
		next = next.Next.Next
	}
	return beg
}
func BuildTree(start, end *ListNode) *TreeNode {
	mid := findMiddle(start, end)
	if mid == nil {
		return nil
	}
	node := &TreeNode{Val: mid.Val}
	node.Left = BuildTree(start, mid)
	node.Right = BuildTree(mid.Next, end)
	return node
}
func sortedListToBST(head *ListNode) *TreeNode {
	if head == nil {
		return nil
	}
	if head.Next == nil {
		return &TreeNode{Val: head.Val}
	}
	return BuildTree(head, nil)
}