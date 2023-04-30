// 1295. Find Numbers with Even Number of Digits

class Solution
{
public:
  int findNumbers(vector<int> &nums)
  {
    int evenCounter = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int cntDigit = floor(log10(nums[i]) + 1);
      if (cntDigit % 2 == 0)
      {
        evenCounter++;
      }
    }
    return evenCounter;
  }
};

// Read: https://www.geeksforgeeks.org/program-count-digits-integer-3-different-methods/