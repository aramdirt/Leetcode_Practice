bool hasPathSum(struct TreeNode* root, int targetSum) {
    if (!root)
        return false;

    if ((targetSum - root->val) == 0)
        return true;

    if (!root->left && !root->right)
        return false;

    return hasPathSum(root->left,  targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}