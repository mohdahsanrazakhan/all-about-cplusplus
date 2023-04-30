// 977. Squares of a Sorted Array

class Solution
{
public:
  vector<int> sortedSquares(vector<int> &nums)
  {
    for (int i = 0; i < nums.size(); i++)
    {
      int temp = nums[i];
      temp *= temp;
      nums[i] = 0;
      nums[i] = temp;
    }
    sort(nums.begin(), nums.end());
    return nums;
  }
};