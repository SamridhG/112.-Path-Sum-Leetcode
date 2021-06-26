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
    vector<vector<int> >A;
    void path(TreeNode *root,vector<int>B)
    {
        if(root->left==NULL && root->right==NULL)
        {
            B.push_back(root->val);
            A.push_back(B);
        }
        else
        {
            B.push_back(root->val);
            if(root->left)path(root->left,B);
            if(root->right)path(root->right,B);
        }
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root!=NULL)
        {
            vector<int>B;
            path(root,B);
            for(int i=0;i<A.size();i++)
            {
                if(accumulate(A[i].begin(),A[i].end(),0)==targetSum)
                {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
};
