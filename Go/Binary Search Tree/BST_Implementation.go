package main

import (
	"fmt"
)

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func insert(head *TreeNode, val int) *TreeNode {
	newNode := &TreeNode{Val: val, Left: nil, Right: nil}
	if head == nil {
		head = newNode
		return head
	}
	if val <= head.Val {
		head.Left = insert(head.Left, val)
	} else {
		head.Right = insert(head.Right, val)
	}
	return head
}

// Root,Left,Right
func preOrder(head *TreeNode) {
	if head == nil {
		return
	}
	fmt.Printf("%d \t ", head.Val)
	preOrder(head.Left)
	preOrder(head.Right)
}

// Left,Root,Right
func inOrder(head *TreeNode) {
	if head == nil {
		return
	}
	inOrder(head.Left)
	fmt.Printf("%d \t ", head.Val)
	inOrder(head.Right)
}

// Left,Right,Root
func postOrder(head *TreeNode) {
	if head == nil {
		return
	}
	postOrder(head.Left)
	postOrder(head.Right)
	fmt.Printf("%d \t ", head.Val)
}

func searchNode(head *TreeNode, val int) bool {
	if head == nil {
		return false
	}
	if head.Val == val {
		return true
	} else if head.Val > val {
		return searchNode(head.Left, val)
	} else {
		return searchNode(head.Right, val)
	}
	return false
}

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

func deleteNode(head *TreeNode, val int) *TreeNode {
	if head == nil {
		return head
	}
	if head.Val > val {
		head.Left = deleteNode(head.Left, val)
	} else if head.Val < val {
		head.Right = deleteNode(head.Right, val)
	} else if head.Val == val {
		//head has no child
		if head.Left == nil && head.Right == nil {
			head = nil
			return head
		}
		//head has one child
		if head.Left != nil && head.Right == nil {
			temp := head.Left
			head = nil
			return temp
		} else if head.Right != nil && head.Left == nil {
			temp := head.Right
			head = nil
			return temp
		}
		//head has two children
		temp := nextVal(head.Right)
		head.Val = temp
		head.Right = deleteNode(head.Right, temp)
	}
	return head
}

func main() {
	var head *TreeNode
	head = insert(head, 8)
	head = insert(head, 6)
	head = insert(head, 7)
	head = insert(head, 5)
	head = insert(head, 9)
	head = insert(head, 10)
	fmt.Println("\n inOrder traversal")
	inOrder(head)
	fmt.Println("\n preOrder traversal")
	preOrder(head)
	fmt.Println("\n postOrder traversal")
	postOrder(head)
	fmt.Println("\n Element 5 present in current Tree? ", searchNode(head, 5))
	fmt.Println("\n Element 4 present in current Tree? ", searchNode(head, 4))
	deleteNode(head, 5)
	fmt.Println("\n inOrder traversal after deleting a node")
	inOrder(head)
}
