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
    int getMax(TreeNode* root){
        while(root->right!=NULL) root = root->right;
        return root->val;
    }
    int getMin(TreeNode* root){
        while(root->left!=NULL) root = root->left;
        return root->val;
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==NULL && root->right==NULL) return true;
        else if(root->left==NULL)
                if(getMin(root->right)>root->val && isValidBST(root->right)) return true; else return false;
        else if(root->right==NULL)
                if(getMax(root->left)<root->val && isValidBST(root->left)) return true; else return false;
        else if(getMax(root->left)<root->val && isValidBST(root->right) && isValidBST(root->left) && getMin(root->right)>root->val) return true;
        else return false;
    }
};
