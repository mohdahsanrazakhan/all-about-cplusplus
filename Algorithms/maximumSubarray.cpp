/*
 * LeetCode: 53. Maximum Subarray
 * TC and SC of "Kadane's Algorithm"
 * Time Complexity is O(n)
 * Space Complexity is O(1)
 */

// Way 1:
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > maxSum)
            maxSum = sum;
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}

// Way 2:
int maxSubArray(vector<int> &nums)
{
    int maxSum = INT_MIN, sum = 0;
    for (auto it : nums)
    {
        sum += it;
        maxSum = max(sum, maxSum);
        if (sum < 0)
            sum = 0;
    }
    return maxSum;
}