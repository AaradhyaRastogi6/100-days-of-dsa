#include <stdio.h>
#include <stdlib.h>

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int *result = (int *)malloc(2 * sizeof(int));

    for (int i = 0; i < numsSize - 1; i++)
    {
        for (int j = i + 1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    *returnSize = 0;
    return result;
}

int main()
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int *result = twoSum(nums, 4, target, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d ", result[i]);
    }

    free(result);
    return 0;
}
