/*
 * LeetCode: 75. Sort Colors
 */

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        /*
         * First Solution: Sort the array
         * Time Complexity is O(nlogn)
         * Space Complexity is O(1)
         */
        sort(nums.begin(), nums.end());
        for (auto a : nums)
            cout << a << ", ";

        /*
         * Second Solution (Optimization): Counting Sort: In counting sort count the number of 0's, 1's and 2's occurence.
         * Using loop to print/fill up each of the elements in sorted order.
         * Time Complexity is O(N) for counting + O(N) for fill up 0, 1, 2. O(2N) means O(N)
         * Space Complexity is O(1)
         */

        /*
         * Optimized Solution: Using Dutch National Flag Algorithm:
         * Take 3 pointer: low pointer (points start node), mid pointer (points start node), and high pointer (points last node)
         * [0...low-1] -> 0
         * [high+1...n] -> 2
         * [low...mid-1] -> 1
         * As mid moving, it meets three checks
         * Check point: if mid element is 0
         *      Switch a[low], a[mid] and low++ , mid++
         * Check point: if mid element is 1
         *      mid++
         * Check point: if mid element is 2
         *      Switch a[mid], a[high] and high--
         *
         * Time Complexity is O(n)
         * Space Complexity is O(1)
         */
        int low = 0, high = nums.size() - 1, mid = 0;

        while (mid <= high)
        {
            switch (nums[mid])
            {
                // if the element is 0
            case 0:
                swap(nums[low++], nums[mid++]);
                break;

                // if the element is 1
            case 1:
                mid++;
                break;

                // if the element is 2
            case 2:
                swap(nums[mid], nums[high--]);
                break;
            }
        }
    }
};