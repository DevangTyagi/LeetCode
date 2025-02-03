class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc_len = 1;
        int dec_len = 1;
        int maxlen = 1;
        for(int i=1;i<nums.size();i++) {
            if(nums[i] > nums[i-1]) {
                inc_len++;
                dec_len = 1;
                maxlen = max(maxlen , inc_len);
            }
            else if(nums[i] < nums[i-1]) {
                dec_len++;
                inc_len = 1;
                maxlen = max(maxlen , dec_len);
            } 
            else{
                inc_len = 1;
                dec_len = 1;
            }
        }
        return max(maxlen,max(inc_len,dec_len));
    }
};