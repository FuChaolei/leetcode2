/*
 * @lc app=leetcode.cn id=148 lang=golang
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (66.71%)
 * Likes:    1288
 * Dislikes: 0
 * Total Accepted:    207.4K
 * Total Submissions: 310.9K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 给你链表的头结点 head ，请将其按 升序 排列并返回 排序后的链表 。
 *
 * 进阶：
 *
 *
 * 你可以在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序吗？
 *
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：head = [4,2,1,3]
 * 输出：[1,2,3,4]
 *
 *
 * 示例 2：
 *
 *
 * 输入：head = [-1,5,3,4,0]
 * 输出：[-1,0,3,4,5]
 *
 *
 * 示例 3：
 *
 *
 * 输入：head = []
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 链表中节点的数目在范围 [0, 5 * 10^4] 内
 * -10^5
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
type pair struct {
	s, e *ListNode
}

func sortList(head *ListNode) *ListNode {
	tmp := head
	l := 0
	for tmp != nil {
		l++
		tmp = tmp.Next
	}
	dummy := &ListNode{
		Val:  0,
		Next: head,
	}
	for i := 1; i < l; i <<= 1 {
		tail := dummy
		cur := dummy.Next
		for cur != nil {
			left := cur
			right := split(left, i)
			cur = split(right, i)
			merged := merge(left, right)
			tail.Next = merged.s
			tail = merged.e
		}
	}
	return dummy.Next
}
func split(head *ListNode, k int) *ListNode {
	dummy := &ListNode{
		Val:  0,
		Next: head,
	}
	pre := dummy
	for k != 0 {
		k--
		if pre != nil {
			pre = pre.Next
		}
	}
	var res *ListNode
	if pre != nil {
		res = pre.Next
		pre.Next = nil
	} else {
		res = nil
	}
	return res
}
func merge(l1 *ListNode, l2 *ListNode) *pair {
	dummy := &ListNode{
		Val: 0,
	}
	tail := dummy
	for l1 != nil && l2 != nil {
		if l1.Val < l2.Val {
			tail.Next = l1
			l1 = l1.Next
		} else {
			tail.Next = l2
			l2 = l2.Next
		}
		tail = tail.Next
	}
	for l1 != nil {
		tail.Next = l1
		l1 = l1.Next
		tail = tail.Next
	}
	for l2 != nil {
		tail.Next = l2
		l2 = l2.Next
		tail = tail.Next
	}
	return &pair{s: dummy.Next, e: tail}
}

// @lc code=end

