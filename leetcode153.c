int findMin(int* nums, int numsSize) {
    int front = 0;
    int rear  = numsSize - 1;
    int mid;

    while (front <= rear)
    {
        mid = (rear - front)/2 + front;

        if (nums[front] < nums[rear])
            return nums[front];

        if (nums[mid] < nums[mid + 1])
            return nums[mid];
        else if (nums[mid] > nums[rear])
            front = mid + 1;
        else if (nums[mid] < nums[front])
            rear = mid - 1;
    }
    return nums[front];
}