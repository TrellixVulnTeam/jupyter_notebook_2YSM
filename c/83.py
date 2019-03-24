class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head:
            return head

        pos=head
        
        while pos:
            cur=pos.next

            while cur and cur.val==pos.val:
                cur=cur.next
            
            pos.next=cur 
            pos=cur
        
        return head
