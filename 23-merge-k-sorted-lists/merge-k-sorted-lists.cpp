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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue< pair<int,ListNode*> , vector<pair<int,ListNode*>> , greater<pair<int,ListNode*>>>pq;
        ListNode *dummynode= new ListNode(-1);
        ListNode*temp=dummynode;
        int n = lists.size();
        for(int i=0;i<n;i++)
        {
            if(lists[i])   //To check if the Node is having a value.If it is empty it is not considered
            {
            pq.push({lists[i]->val , lists[i]});
            }
        }
        while(!pq.empty())
        {
            auto itr = pq.top();
            pq.pop();
            temp->next=itr.second;         
            if(itr.second->next)
            pq.push({itr.second->next->val ,itr.second->next });
            temp=temp->next;
        }
        return dummynode->next;
    }
};