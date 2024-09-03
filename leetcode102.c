/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define SIZE 1000
struct TreeNode *queue[SIZE];

int front = -1;
int rear  = -1;

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
        printf("Queue is null!\n");
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

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int cur_lev = 0;
    int nxt_lev = 1;
    int num_cur_lev = 0;
    int num_per_lev[SIZE] = {1};
    struct TreeNode *node = root;
    int **result = malloc(sizeof(int*) * SIZE);
    *returnColumnSizes = malloc(sizeof(int) * SIZE);

    memset(result, 0, sizeof(int*) * SIZE);
    memset(*returnColumnSizes, 0, sizeof(int) * SIZE);

    if (!root)
    {
        *returnSize = 0;
        *returnColumnSizes[0] = 0;
        return result;
    }

    while (node)
    {
        if (num_cur_lev >= num_per_lev[cur_lev])
        {
            cur_lev++;
            nxt_lev++;
            num_cur_lev = 0;
        }

        result[cur_lev] = malloc(sizeof(int) * num_per_lev[cur_lev]);

        if (node->left)
        {
            inqueue(node->left);
            num_per_lev[nxt_lev]++;
        }

        if (node->right)
        {
            inqueue(node->right);
            num_per_lev[nxt_lev]++;
        }

        result[cur_lev][num_cur_lev++] = node->val;
        node = delqueue();
    }

    result = realloc(result, sizeof(int*) * (cur_lev + 1));
    *returnColumnSizes = realloc(*returnColumnSizes, sizeof(int) * (cur_lev + 1));
    *returnSize = (cur_lev + 1);

    return result;
}