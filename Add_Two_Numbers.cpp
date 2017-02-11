#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode*, ListNode*);
};

ListNode* Solution::addTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode result(0),*p=&result;
    int temp=0;
    while(l1 || l2 || temp){
        int sum=((l1)?l1->val:0)+((l2)?l2->val:0);
        int val = sum+temp;
        if(sum>=10){
            val=(sum%10)+temp;
            temp=1;
        }else if(val>=10){
            val=val%10;
            temp=1;
        }else{
            temp=0;
        }
        l1=(l1)?l1->next:NULL;
        l2=(l2)?l2->next:NULL;
        p->next= new ListNode(val);
        p=p->next;
    }
    return result.next;
}


int main(){
    ListNode lFirst(2);
    ListNode lSed(4);
    ListNode lThree(3);

    lFirst.next=&lSed;
    lSed.next=&lThree;

    ListNode sFirst(5);
    ListNode sSed(6);
    ListNode sThree(4);

    sFirst.next=&sSed;
    sSed.next=&sThree;
    Solution app;
    ListNode *node=app.addTwoNumbers(&lFirst,&sFirst);
    ListNode* next_node=node;
    while(next_node){
        std::cout<<next_node->val<<std::endl;
        next_node=next_node->next;
    }
    return 0;
}
