#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <omp.h>
#include <stdio.h>


using namespace std;


  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int carry = 0;
        ListNode *head = NULL;
        ListNode *cur = NULL;
        while(l1 != NULL && l2 != NULL)
        {
            int tmp = l1->val+l2->val+carry;
            int carry = tmp/10;cout <<carry<< tmp << endl;
            if(head == NULL)
            {
                cur = head = new ListNode(tmp%10);
            }
            else
            {
                cur = cur->next = new ListNode(tmp%10);
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        cout << carry << endl;
        while(l1 != NULL)
        {
            int tmp = l1->val + carry;
            int carry = tmp/10;
            if(head == NULL)
            {
                cur = head = new ListNode(tmp%10);
            }
            else
            {
                cur = cur->next = new ListNode(tmp%10);
            }
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            int tmp = l2->val + carry;
            int carry = tmp/10;
            if(head == NULL)
            {
                cur = head = new ListNode(tmp%10);
            }
            else
            {
                cur = cur->next = new ListNode(tmp%10);
            }
            l2 = l2->next;
        }
        if(carry > 0)
        {
            cur = cur->next = new ListNode(carry);
        }
        cur->next = NULL;
        
        return head;
    }
};


int main(void)
{
    Solution s;
    ListNode *l1 = new ListNode(5);
    ListNode *l2 = new ListNode(5);
    ListNode *head = s.addTwoNumbers(l1, l2);
    cout << head->val << head->next<< endl;

    return 0;
}
