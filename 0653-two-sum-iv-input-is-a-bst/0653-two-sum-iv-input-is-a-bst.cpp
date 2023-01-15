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
    vector<int>v;
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,int>m;
        inorder(root);
        int i=0;
        int j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]==k)
                return true;
            if(v[i]+v[j]>k)
                j--;
            else
                i++;
        }
        return false;
    }
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};