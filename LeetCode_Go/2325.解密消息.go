/*
 * @lc app=leetcode.cn id=2325 lang=golang
 *
 * [2325] 解密消息
 */

// @lc code=start
func decodeMessage(key string, message string) string {
	mp := make(map[rune]int)
	idx := 0
	for _, ch := range key {
		if ch == ' ' {
			continue
		}
		if _, ok := mp[ch]; !ok {
			mp[ch] = idx
			idx++
		}
	}
	var res string
	for _, ch := range message {
		if ch == ' ' {
			res += " "
		} else {
			res += string(mp[ch] + 'a')
		}
	}
	return res
}

// @lc code=end

