/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 *
 * https://leetcode.cn/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (57.50%)
 * Likes:    2288
 * Dislikes: 0
 * Total Accepted:    586.2K
 * Total Submissions: 1M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 给你一个链表数组，每个链表都已经按升序排列。
 *
 * 请你将所有链表合并到一个升序链表中，返回合并后的链表。
 *
 *
 *
 * 示例 1：
 *
 * 输入：lists = [[1,4,5],[1,3,4],[2,6]]
 * 输出：[1,1,2,3,4,4,5,6]
 * 解释：链表数组如下：
 * [
 * ⁠ 1->4->5,
 * ⁠ 1->3->4,
 * ⁠ 2->6
 * ]
 * 将它们合并到一个有序链表中得到。
 * 1->1->2->3->4->4->5->6
 *
 *
 * 示例 2：
 *
 * 输入：lists = []
 * 输出：[]
 *
 *
 * 示例 3：
 *
 * 输入：lists = [[]]
 * 输出：[]
 *
 *
 *
 *
 * 提示：
 *
 *
 * k == lists.length
 * 0 <= k <= 10^4
 * 0 <= lists[i].length <= 500
 * -10^4 <= lists[i][j] <= 10^4
 * lists[i] 按 升序 排列
 * lists[i].length 的总和不超过 10^4
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
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        int n = lists.size() - 1;
        return merge(lists, 0, n);
    }

private:
    ListNode *merge(vector<ListNode *> &lists, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        if (l == r)
        {
            return lists[l];
        }
        if (l == r - 1)
        {
            return mergeTwo(lists[l], lists[r]);
        }
        int mid = l + (r - l + 1) / 2;
        auto left = merge(lists, l, mid);
        auto right = merge(lists, mid + 1, r);
        return mergeTwo(left, right);
    }
    ListNode *mergeTwo(ListNode *l, ListNode *r)
    {
        if (l == nullptr)
        {
            return r;
        }
        if (r == nullptr)
        {
            return l;
        }
        ListNode dummy(0);
        ListNode *pre = &dummy;
        while (l && r)
        {
            if (l->val < r->val)
            {
                pre->next = l;
                l = l->next;
            }
            else
            {
                pre->next = r;
                r = r->next;
            }
            pre = pre->next;
        }
        pre->next = l ? l : r;
        return dummy.next;
    }
};
// @lc code=end
