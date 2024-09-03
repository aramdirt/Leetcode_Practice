int search(int* nums, int numsSize, int target){
    int front = 0;
    int rear  = numsSize - 1;
    int mid;

    while (front <= rear)
    {
        mid = (rear - front)/2 + front;

        if (nums[front] == target)
            return front;

        if (nums[rear] == target)
            return rear;

        if (nums[mid] == target)
            return mid;

        if (nums[mid] < nums[rear])
        {
            if (target > nums[mid] && target < nums[rear])
                front = mid + 1;
            else
                rear = mid - 1;
        }
        else if (nums[mid] > nums[front])
        {
            if (target < nums[mid] && target > nums[front])
                rear = mid - 1;
            else
                front = mid + 1;
        }
        else
            return - 1;
    }
    return -1;
}