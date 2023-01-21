class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        std::unordered_map<int, ListNode*> prefix;
        ListNode *dummyNode = new ListNode(0, head);
        int sum = 0;
        prefix[0] = dummyNode;
        while(head)
        {
            sum += head->val;
            prefix[sum] = head;
            head = head->next;
        }
        sum = 0;
        head = dummyNode;
        while(head)
        {
            sum += head->val;
            if(prefix[sum] != head)
            {
                head->next = prefix[sum]->next;
            }
            head = head->next;
        }
        return dummyNode->next;
    }
};
