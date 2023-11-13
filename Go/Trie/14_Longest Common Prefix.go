import "fmt"

type Node struct {
	children map[rune]*Node
	end      bool
}

func insert(head *Node, word string) {
	temp := head
	for _, c := range word {
		index := rune(c)
		if _, ok := temp.children[index]; !ok {
			temp.children[index] = &Node{
				children: make(map[rune]*Node),
			}
		}
		temp = temp.children[index]
	}
	temp.end = true
}

func MinStr(strs []string) string {
	minStr := strs[0]
	for _, str := range strs {
		if len(str) < len(minStr) {
			minStr = str
		}
	}
	return minStr
}

func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}
	head := &Node{
		children: make(map[rune]*Node),
	}
	for _, str := range strs {
		insert(head, str)
	}
	var res string
	minStr := MinStr(strs)
	fmt.Println("Min str is ", minStr)
	temp := head
	for _, s := range minStr {
		if len(temp.children) == 1 {
			res += string(s)
			temp = temp.children[s]
		} else {
			return res
		}
	}
	return res
}