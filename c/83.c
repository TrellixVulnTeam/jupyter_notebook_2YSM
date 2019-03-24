/*
给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。

示例 1:

输入: 1->1->2
输出: 1->2
示例 2:

输入: 1->1->2->3->3
输出: 1->2->3
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdlib.h>
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode *pre = head;
    struct ListNode *cur = head;
    while(pre!=NULL && cur!=NULL){
        if (pre->val == cur->val) {
            /* code */
            pre->next=cur->next;
            cur = pre->next;
        }
        else
        {
            pre = cur;
            cur = cur->next;
        }        
    }
    return head;
}
