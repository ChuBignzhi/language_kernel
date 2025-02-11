//逆转链表
#include <iostream>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val, ListNode *next);
    ~ListNode();
};

ListNode::ListNode(int val, ListNode *next){
    this->val = val;
    this->next = next;
}

ListNode::~ListNode(){}

ListNode* reverse_list(ListNode* head){ // 迭代
    ListNode *prev = nullptr;
    ListNode *curr = head;
    while(curr != nullptr){
        ListNode *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode* reverseList(ListNode* head){ //递归
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode *new_head = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

int main()
{
    ListNode *node5 = new ListNode(5, nullptr);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);

    // ListNode *new_head =  reverse_list(node1);

    ListNode *pre = nullptr;
    ListNode *new_head =  reverseList(node1);
    
    ListNode *current = new_head;
    while (current != nullptr)
    {
        cout << current->val <<" ";
        current = current->next;
    }
    current = new_head;
    while (current != nullptr)
    {
        ListNode *next = current->next;
        delete current;
        current = next;
    }
    
    return 0;
}

