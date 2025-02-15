//打家劫舍终极版,二叉树版本
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
using namespace std;

class TreeNode{
public:
    int val;
    unique_ptr<TreeNode> left;
    unique_ptr<TreeNode> right;

    explicit TreeNode(int x, TreeNode* left=nullptr, TreeNode* right=nullptr)
        :val(x),
         left(left?unique_ptr<TreeNode>(left):nullptr),
         right(right?unique_ptr<TreeNode>(right):nullptr){}
};

vector<int> dfs(TreeNode* node){
    if(node == nullptr){
        vector<int> best(2,0);
        return best;
    }
    
    vector<int> sLeft = dfs(node->left.get());
    vector<int> sRight = dfs(node->right.get());
    int select = node->val + sLeft[1] + sRight[1];
    int nonslect = max(sLeft[0], sLeft[1]) + max(sRight[0], sRight[1]);
    vector<int> result = {select, nonslect};\

    return result;
}

int main()
{
    auto node5 = make_unique<TreeNode>(1);
    auto node4 = make_unique<TreeNode>(3);
    auto node3 = make_unique<TreeNode>(3, nullptr, node5.release());
    auto node2 = make_unique<TreeNode>(1, nullptr, node4.release());
    auto node1 = make_unique<TreeNode>(1, node2.release(), node3.release());

    vector<int> best = dfs(node1.get());

    cout << max(best[0], best[1]) <<endl;

    return 0;
}