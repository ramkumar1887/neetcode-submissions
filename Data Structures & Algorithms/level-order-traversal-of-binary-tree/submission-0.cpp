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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<TreeNode*> children;
        vector<TreeNode*> parents;
        parents.push_back(root);
        vector<int> nestList;
        while(!parents.empty()){
            nestList.clear();
            children.clear();
            for(TreeNode* p: parents){
                if(p!=NULL){
                    nestList.push_back(p->val);
                    children.push_back(p->left);
                    children.push_back(p->right);
                }
            }
            parents = children;
            if(!nestList.empty()) result.push_back(nestList);
        }
        return result;
    }
};
