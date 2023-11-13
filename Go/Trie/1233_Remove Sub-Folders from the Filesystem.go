import (
	"sort"
	"strings"
)

type TrieNode struct {
	children map[string]*TrieNode
	end      bool
}

func isFolder(head *TrieNode, folder []string) bool {
	for _, fName := range folder {
		if _, ok := head.children[fName]; !ok {
			head.children[fName] = &TrieNode{
				children: make(map[string]*TrieNode),
			}
		}
		if head.end {
			return false
		}
		head = head.children[fName]
	}
	head.end = true
	return true
}

func removeSubfolders(folder []string) []string {
	res := []string{}
	head := &TrieNode{children: make(map[string]*TrieNode)}
	sort.Slice(folder, func(i, j int) bool {
		return len(folder[i]) < len(folder[j])
	})
	for _, folders := range folder {
		if isFolder(head, strings.Split(folders, "/")) {
			res = append(res, folders)
		}
	}
	return res
}