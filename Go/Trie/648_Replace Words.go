import (
	"fmt"
	"strings"
)

type TrieNode struct {
	children map[rune]*TrieNode
	end      bool
}

func insert(head *TrieNode, str string) {
	temp := head
	for _, c := range str {
		if _, ok := temp.children[c]; !ok {
			temp.children[c] = &TrieNode{
				children: make(map[rune]*TrieNode),
			}
		}
		temp = temp.children[c]
	}
	temp.end = true
}
func search(root *TrieNode, word string) string {
	temp := root
	replace := []rune{}
	fmt.Println("seraching for word ", word)
	for _, w := range word {
		if temp.end {
			return string(replace)
		}
		if _, ok := temp.children[w]; !ok {
			return word
		}
		replace = append(replace, w)
		temp = temp.children[w]
	}
	return word
}

func replaceWords(dictionary []string, sentence string) string {
	if len(dictionary) == 0 || len(sentence) == 0 {
		return sentence
	}
	root := &TrieNode{
		children: make(map[rune]*TrieNode),
	}
	for _, dict := range dictionary {
		insert(root, dict)
	}
	words := strings.Split(sentence, " ")
	var res []string
	for _, word := range words {
		Rw := search(root, word)
		res = append(res, Rw)
	}
	return strings.Join(res, " ")
}