class Solution {
public:
    void move_zeroes_right(vector<int>& nums) {
        if (nums.size() < 2)
            return;
        int i = 0, j = 0;
        while (i < nums.size() && j < nums.size()) {
            if (nums[i] == 0) {
                while (j < nums.size() && nums[j] == 0)
                    j++;
                if (i < nums.size() && j < nums.size()) {
                    swap(nums[i], nums[j]);
                    i++;
                }

            } else {
                i++;
                j++;
            }
        }
        return;
    }
    vector<int> applyOperations(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1]) {
                nums[i] = nums[i] * 2;
                nums[i + 1] = 0;
            }
        }
        move_zeroes_right(nums);
        return nums;
    }
};