class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
       int n=nums.size();
       int max_index=0;
       for(int i=0;i<n;i++){
        if(max_index < i) return false;
        max_index = max(max_index,i+nums[i]);
       }
       return true;
    }
};