// 561. Array Partition

class Solution
{
public:
  int arrayPairSum(vector<int> &nums)
  {
    // Sorting an array
    sort(nums.begin(), nums.end());

    int maxPairSum = 0;

    for (int i = 0; i < nums.size(); i += 2)
    {
      maxPairSum += nums[i];
    }
    return maxPairSum;
  }
};