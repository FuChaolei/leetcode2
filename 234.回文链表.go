/*
 * @lc app=leetcode.cn id=234 lang=golang
 *
 * [234] 回文链表
 *
 * https://leetcode.cn/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (52.33%)
 * Likes:    1483
 * Dislikes: 0
 * Total Accepted:    490.2K
 * Total Submissions: 936.6K
 * Testcase Example:  '[1,2,2,1]'
 *
 * 给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [1,2,2,1]
 * 输出：true
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [1,2]
 * 输出：false
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点数目在范围[1, 10^5] 内
 * 0 <= Node.val <= 9
 *
 *
 *
 *
 * 进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	s, f := head, head
	if f == nil {
		return true
	}
	for f.Next != nil && f.Next.Next != nil {
		f = f.Next.Next
		s = s.Next
	}
	reverse(s)
	l := head
	for s.Next != nil {
		if l.Val != s.Next.Val {
			return false
		}
		s = s.Next
		l = l.Next
	}
	return true
}
func reverse(s *ListNode) {
	pre := s
	cur := pre.Next
	for cur != nil {
		tail := cur.Next
		if cur.Next != nil {
			cur.Next = tail.Next
		} else {
			return
		}
		tail.Next = pre.Next
		pre.Next = tail
	}
}

// @lc code=end

