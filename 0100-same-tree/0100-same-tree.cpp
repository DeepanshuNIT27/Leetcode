/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
bool sameTree(TreeNode* p,TreeNode* q){

    if(p == nullptr &&  q==nullptr) return true;
    if(p==nullptr || q==nullptr) return false;
   bool ans = (p->val == q->val);
   bool ans1 = sameTree(p->left, q->left);
   bool ans2 = sameTree(p->right, q->right);

    return ans1 && ans2 && ans;
}
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return sameTree(p,q);

    }
};