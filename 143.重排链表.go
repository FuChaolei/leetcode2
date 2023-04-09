/*
 * @lc app=leetcode.cn id=143 lang=golang
 *
 * [143] 重排链表
 *
 * https://leetcode.cn/problems/reorder-list/description/
 *
 * algorithms
 * Medium (64.57%)
 * Likes:    1113
 * Dislikes: 0
 * Total Accepted:    227.4K
 * Total Submissions: 352.1K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L 的头节点 head ，单链表 L 表示为：
 *
 *
 * L0 → L1 → … → Ln - 1 → Ln
 *
 *
 * 请将其重新排列后变为：
 *
 *
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 *
 * 不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4]
 * 输出：[1,4,2,3]
 *
 * 示例 2：
 *
 *
 *
 *
 * 输入：head = [1,2,3,4,5]
 * 输出：[1,5,2,4,3]
 *
 *
 *
 * 提示：
 *
 *
 * 链表的长度范围为 [1, 5 * 10^4]
 * 1 <= node.val <= 1000
 *
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
func reorderList(head *ListNode) {
	if head == nil || head.Next == nil {
		return
	}
	half := get_half(head)
	l2 := reverse(half)
	l1 := head
	merge(l1, l2)
}
func get_half(head *ListNode) *ListNode {
	l, r := head, head
	// for r != nil && r.Next != nil {
	// 	r = r.Next.Next
	// 	l = l.Next
	// }
	if r==nil {
		return nil
	}
	for r.Next!=nil && r.Next.Next!=nil {
		l=l.Next
		r=r.Next.Next
	}
	res := l.Next
	l.Next = nil
	return res
}
func reverse(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	dummy := &ListNode{
		Next: head,
	}
	cur := head
	pre := dummy
	for cur.Next != nil {
		tail := cur.Next
		cur.Next = tail.Next
		tail.Next = pre.Next
		pre.Next = tail
	}
	return dummy.Next
}
func merge(l1 *ListNode, l2 *ListNode) {
	for l1 != nil && l2 != nil {
		tmp1 := l1.Next
		tmp2 := l2.Next
		l1.Next = l2
		l2.Next = tmp1
		l1 = tmp1
		l2 = tmp2
	}
}

// @lc code=end

