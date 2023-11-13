/*
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preOrderSum(root *TreeNode, low, high int, sum *int) int {
	if root == nil {
		return *sum
	}
	if root.Val >= low && root.Val <= high {
		*sum += root.Val
	}
	preOrderSum(root.Left, low, high, sum)
	preOrderSum(root.Right, low, high, sum)
	return *sum
}
func rangeSumBST(root *TreeNode, low int, high int) int {
	sum := 0
	return preOrderSum(root, low, high, &sum)
}