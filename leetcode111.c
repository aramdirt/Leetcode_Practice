#define MIN(a,b) (a < b ? a : b)

int minDepth(TreeNode* root) {
    if (!root)
        return 0;
    else if (!root->left && root->right)
        return 1 + minDepth(root->right);
    else if (root->left && !root->right)
        return 1 + minDepth(root->left);

    return 1 + MIN(minDepth(root->left), minDepth(root->right));
}