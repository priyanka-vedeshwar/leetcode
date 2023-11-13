/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func create(nums []int, beg, end int) *TreeNode {

	if end < beg {
		return nil
	}
	mid := beg + (end-beg)/2
	node := TreeNode{Val: nums[mid], Left: nil, Right: nil}
	node.Left = create(nums, beg, mid-1)
	node.Right = create(nums, mid+1, end)

	return &node
}
func sortedArrayToBST(nums []int) *TreeNode {
	root := create(nums, 0, len(nums)-1)
	return root
}