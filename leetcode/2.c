#include "stdio.h"
#include "stdlib.h"

struct ListNode {
    int val;
    struct ListNode *next;
};

int getNum(struct ListNode* node, int i){
    int cur = 0;
    while(node != NULL){
        if (cur == i){
            return node->val;
        }
        cur++;
        node = node->next;
    }
    return 0;
}

int endCalc(struct ListNode* l1, struct ListNode* l2, int i){
    int cur = 0;
    struct ListNode *node1 = l1,*node2 = l2;
    while(cur <= i){
        if (node1==NULL&&node2==NULL) return 1;
        if (node1!=NULL) node1 = node1->next;
        if (node2!=NULL) node2 = node2->next;
        cur++;
    }
    return 0;
}

void add(struct ListNode* cur, int sum){
    cur->val += sum;
    int delta = (cur->val)-(cur->val%10);
    cur->val-=delta;
    cur->next->val+=delta/10;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = (struct ListNode*)malloc(sizeof(struct ListNode));
    result->next=NULL;
    result->val=0;

    struct ListNode* cur = result;
    for(int i = 0;;i++){
        struct ListNode* next = (struct ListNode*)malloc(sizeof(struct ListNode));
        next->next = NULL;
        next->val = 0;
        cur->next = next;
        add(cur, getNum(l1, i) + getNum(l2, i));
        if (endCalc(l1, l2, i+1)){
            int delta = (cur->val)-(cur->val%10);
            cur->val-=delta;
            cur->next->val+=delta/10;
            break;
        }
    }
    return result;
}