#include<bits/stdc++.h>
using namespace std;

void deleteNode(ListNode* node) {
  ListNode *nxt = node->next;        
  node->val = nxt->val;
  node->next = nxt->next;
  free(nxt);
}
