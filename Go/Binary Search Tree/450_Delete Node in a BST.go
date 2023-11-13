/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func nextVal(head *TreeNode) int {
	if head == nil {
		return 0
	}
	temp := head
	for temp.Left != nil {
		temp = temp.Left
	}
	return temp.Val
}

func findAndDel(root *TreeNode, key int) *TreeNode {
	if root == nil {
		return nil
	}
	if root.Val == key {
		//leaf node
		if root.Left == nil && root.Right == nil {
			root = nil
			return nil
		}
		//one child
		if root.Left != nil && root.Right == nil {
			temp := root.Left
			root = nil
			return temp
		}
		if root.Right != nil && root.Left == nil {
			temp := root.Right
			root = nil
			return temp
		}
		//two children
		temp := nextVal(root.Right)
		root.Val = temp
		root.Right = findAndDel(root.Right, temp)
	} else if root.Val > key {
		root.Left = findAndDel(root.Left, key)
	} else {
		root.Right = findAndDel(root.Right, key)
	}
	return root
}
func deleteNode(root *TreeNode, key int) *TreeNode {
	//find the node.
	//replace found node with the inorder successor.
	//run delete recurssion on node.right subtree.
	return findAndDel(root, key)
}