// 896. Monotonic Array

class Solution
{
public:
  bool isMonotonic(vector<int> &nums)
  {
    bool incOrder = true, descOrder = true;
    for (int i = 1; i < nums.size(); i++)
    {
      incOrder &= nums[i - 1] <= nums[i];
      descOrder &= nums[i - 1] >= nums[i];
    }
    return incOrder || descOrder;
  }
};