type Trie struct {
	children map[rune]*Trie
	end      bool
}

func Constructor() Trie {
	return Trie{
		children: make(map[rune]*Trie)}
}

func (this *Trie) Insert(word string) {
	for _, w := range word {
		if _, ok := this.children[w]; !ok {
			this.children[w] = &Trie{
				children: make(map[rune]*Trie),
			}
		}
		this = this.children[w]
	}
	this.end = true
}

func (this *Trie) Search(word string) bool {
	for _, w := range word {
		if _, ok := this.children[w]; !ok {
			return false
		}
		this = this.children[w]
	}
	return this.end
}

func (this *Trie) StartsWith(prefix string) bool {
	for _, p := range prefix {
		if _, ok := this.children[p]; !ok {
			return false
		}
		this = this.children[p]
	}
	return true
}

/**
 * Your Trie object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Insert(word);
 * param_2 := obj.Search(word);
 * param_3 := obj.StartsWith(prefix);
 */