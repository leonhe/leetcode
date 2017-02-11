#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};


class Solution {
public:
    Solution():result(0){};
    ListNode* addTwoNumbers(ListNode*, ListNode*);
private:
    ListNode result;
};

ListNode* Solution::addTwoNumbers(ListNode *l1,ListNode *l2){
    ListNode *next_node=l1;
    ListNode *l2_next_node=l2;
    int temp=0;
    ListNode *result_next_node=&this->result;
    while(next_node && l2_next_node){
        int sum=next_node->val+l2_next_node->val;
        if(sum>=10){
            result_next_node->val=sum%10;
            temp=1;
        }else{
            result_next_node->val=sum+temp;
            temp=0;
        }
        next_node=next_node->next;
        l2_next_node=l2_next_node->next;
        if(next_node && l2_next_node){
            result_next_node->next= new ListNode(0);
            result_next_node=result_next_node->next;
        }
    }
    return &this->result;
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
