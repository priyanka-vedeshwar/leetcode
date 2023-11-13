import "sort"

func topKFrequent(words []string, k int) []string {
	wordCount := map[string]int{}
	res := []string{}
	for _, w := range words {
		if _, ok := wordCount[w]; !ok {
			wordCount[w] = 1
			res = append(res, w)
		}
		wordCount[w] += 1
	}

	sort.Slice(res, func(i, j int) bool {
		if wordCount[res[i]] == wordCount[res[j]] {
			return res[i] < res[j]
		}
		return wordCount[res[i]] > wordCount[res[j]]
	})

	return res[:k]
}