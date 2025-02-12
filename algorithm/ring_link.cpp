//环形链表

#include <iostream>
#include <set>
#include <unordered_set>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int val, ListNode *next);
    ~ListNode();
    bool operator<(const ListNode &node) const {
        return this->val < node.val;
    }
};

ListNode::ListNode(int val, ListNode *next){
    this->val = val;
    this->next = next;
}

ListNode::~ListNode(){}

// bool hasCycle(ListNode* head){
//     set<ListNode*> set;
//     while (head != nullptr){
//         if(set.find(head) != set.end()) return true;
//         set.insert(head);
//         head = head->next;
//     }
//     return false;
// }

void deleteList(ListNode* head){
    unordered_set<ListNode*> nodeSet; // 用于检测和删除节点
    ListNode* current = head;
    while (current != nullptr){
        if(nodeSet.find(current) != nodeSet.end()) break; 
        // 如果发现环，则停止删除
        nodeSet.insert(current);
        ListNode* next = current->next;
        delete current;
        current = next;
    }
}

bool hasCycle(ListNode* head){
    set<ListNode> set;
    while (head != nullptr){
        if(!set.insert(*head).second) return true;
        head = head->next;
    }
    return false;
}


bool hasCycle_2(ListNode* head){
    if (head ==  nullptr || head->next == nullptr){
        return false;
    }
    ListNode* slow = head;
    ListNode* quick = head->next;
    while(slow != quick){
        if(quick == nullptr || quick->next ==  nullptr){
            return false;
        }
        slow = slow->next;
        quick = quick->next->next;
    }
    return true;
}

int main()
{
    ListNode *node5 = new ListNode(5, nullptr);
    ListNode *node4 = new ListNode(4, node5);
    ListNode *node3 = new ListNode(3, node4);
    ListNode *node2 = new ListNode(2, node3);
    ListNode *node1 = new ListNode(1, node2);
    node5->next = node3;

    if (hasCycle(node1)){
        cout << "Cycle detected!" << endl;
    }
    else{
        cout << "No cycle detected." << endl;
    }

    if (hasCycle_2(node1)){
        cout << "Cycle detected!" << endl;
    }
    else{
        cout << "No cycle detected." << endl;
    }
    
    deleteList(node1);
    return 0;   
}