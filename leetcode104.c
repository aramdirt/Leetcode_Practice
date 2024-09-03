/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define SIZE 1000
int front, rear;
struct TreeNode *queue[SIZE];

front = -1;
rear  = -1;

void inqueue(struct TreeNode *node)
{
    if (rear >= SIZE)
    {
        printf("Queue is full!\n");
        return;
    }

    queue[++rear] = node;

    if (front == -1)
        front++;

    return;
}

struct TreeNode *delqueue()
{
    struct TreeNode *tmp;

    if (front > rear || front == -1)
    {
        printf("Queue is empty!\n");
        return NULL;
    }

    tmp = queue[front++];

    if (front > rear)
    {
        front = -1;
        rear  = -1;
    }

    return tmp;
}

int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;

    int cur_lev = 0;
    int nxt_lev = 1;
    int num_of_cur_lev = 0;
    int num_per_lev[SIZE] = {1};
    struct TreeNode *node = root;

    while (node)
    {
        if (num_of_cur_lev == num_per_lev[cur_lev])
        {
            cur_lev++;
            nxt_lev++;
            num_of_cur_lev = 1;
        }

        if (node->left)
        {
            inqueue(node->left);
            num_per_lev[nxt_lev] += 1;
        }

        if (node->right)
        {
            inqueue(node->right);
            num_per_lev[nxt_lev] += 1;
        }

        num_of_cur_lev++;
        node = delqueue();
    }

    return cur_lev + 1;
}


#if 0
#define MAX(a,b) (a > b ? a : b)

int maxDepth(struct TreeNode* root) {
    if (!root)
        return 0;
    else if (root->left && !root->right)
        return 1 + maxDepth(root->left);
    else if (!root->left && root->right)
        return 1 + maxDepth(root->right);

    return 1 + MAX(maxDepth(root->left), maxDepth(root->right));
}
#endif
