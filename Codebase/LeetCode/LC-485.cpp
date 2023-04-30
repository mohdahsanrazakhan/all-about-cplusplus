// 485. Max Consecutive Ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 1) {
                cnt++;
                maxOnes = max(maxOnes, cnt);
            }
            else {
                cnt = 0;
            }
        }
        return maxOnes;
    }
};