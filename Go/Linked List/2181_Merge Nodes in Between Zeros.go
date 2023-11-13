/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/*
	func Add(val int,node *ListNode){
	    temp:=&ListNode{Val:val,Next:nil}
	    if node==nil{
	        node=temp
	        return
	    }
	    cur:=node
	    for cur.Next!=nil{
	        cur=cur.Next
	    }
	    cur.Next=temp
	}

	func mergeNodes(head *ListNode) *ListNode {
	   // flag:=false
	    cur:=head
	    nums:=[]int{}
	    sum:=0
	    for cur!=nil{
	        if cur.Val != 0{
	            sum=sum+cur.Val
	        }else if cur.Val == 0{
	            fmt.Println("sum formed is ",sum)
	            nums=append(nums,sum)
	            sum=0
	        }
	        cur=cur.Next
	    }
	    var newHead =new(ListNode)
	    for i:=0;i<len(nums);i++{
	        if nums[i]==0{
	            continue}
	        Add(nums[i],newHead)
	    }
	    return newHead.Next
	}
*/
func mergeNodes(head *ListNode) *ListNode {
	cur := head.Next
	prevZero := head
	prevPrevZero := head
	sum := 0
	for cur != nil {
		if cur.Val == 0 {
			prevZero.Val = sum
			prevZero.Next = cur
			prevPrevZero = prevZero
			prevZero = cur
			sum = 0
		}
		sum += cur.Val
		cur = cur.Next
	}
	prevPrevZero.Next = nil
	return head
}