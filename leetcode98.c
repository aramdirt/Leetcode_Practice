/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool isValidBST_greater(struct TreeNode *node, int num)
{
    if (!node)
        return true;

    if (node->val > num)
    {
        return isValidBST_greater(node->left, num) && isValidBST_greater(node->right, num);
    }
    else
    {
        return false;
    }
}

bool isValidBST_lower(struct TreeNode *node, int num)
{
    if (!node)
        return true;

    if (node->val < num)
    {
        return isValidBST_lower(node->left, num) && isValidBST_lower(node->right, num);
    }
    else
    {
        return false;
    }
}

bool isValidBST(struct TreeNode* root) {
    if (!root)
        return true;

    if (!root->left && !root->right)
        return true;

    if (!root->left)
        return root->right->val > root->val && isValidBST(root->right) && isValidBST_greater(root->right, root->val);

    if (!root->right)
        return root->left->val < root->val && isValidBST(root->left) && isValidBST_lower(root->left, root->val);

    if (root->left && root->right)
    {
        return root->left->val < root->val && root->right->val > root->val && isValidBST(root->left) && isValidBST(root->right) && isValidBST_greater(root->right, root->val) && isValidBST_lower(root->left, root->val);
    }
    else
        return false;
    
}