/*
 * @lc app=leetcode.cn id=143 lang=cpp
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
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return;
        }
        ListNode *half = gethalf(head);
        ListNode *l1 = head;
        ListNode *l2 = half->next;
        half->next = nullptr;
        l2 = reverse(l2);
        merge(l1, l2);
    }

private:
    ListNode *gethalf(ListNode *head)
    {
        ListNode *s = head, *f = head;
        while (f && f->next)
        {
            f = f->next->next;
            s = s->next;
        }
        return s;
    }
    ListNode *reverse(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode dummy(0);
        ListNode *pre = &dummy;
        ListNode *cur = head;
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre->next;
            pre->next = cur;
            cur = nxt;
        }
        return dummy.next;
    }
    void merge(ListNode *l1, ListNode *l2)
    {
        while (l1 && l2)
        {
            ListNode *tmp = l1->next;
            ListNode *tmp2 = l2->next;
            l1->next = l2;
            l2->next = tmp;
            l1 = tmp;
            l2 = tmp2;
        }
    }
};
// @lc code=end
