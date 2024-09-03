int searchInsert(int* nums, int numsSize, int target) {
    int front, rear, mid;

    front = 0;
    rear  = numsSize - 1;
    while (front <= rear)
    {
        mid = (rear - front)/2 + front;

        if (nums[mid] == target)
            return mid;

        if (target > nums[mid])
            front = mid + 1;
        else
            rear = mid - 1;
    }

    return front;
}