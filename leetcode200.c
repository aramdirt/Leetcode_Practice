void visit(char **grid, int x, int y, int gridSize, int *gridColSize)
{
    if (x < 0 || y < 0 || x >= gridSize)
        return;

    if (y >= gridColSize[x])
        return;

    if (grid[x][y] == '0')
        return;

    grid[x][y] = '0';
    visit(grid, x, y - 1, gridSize, gridColSize);
    visit(grid, x, y + 1, gridSize, gridColSize);
    visit(grid, x + 1, y, gridSize, gridColSize);
    visit(grid, x - 1, y, gridSize, gridColSize);
    return;
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    int x, y, result;

    result = 0;
    for (x = 0; x < gridSize; x++)
    {
        for (y = 0; y < gridColSize[x]; y++)
        {
            if (grid[x][y] == '1')
            {
                visit(grid, x, y, gridSize, gridColSize);
                result++;
            }
        }
    }
    return result;
}