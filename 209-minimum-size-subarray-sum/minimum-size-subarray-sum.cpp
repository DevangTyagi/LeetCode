class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
     int ans = INT_MAX;
     int i=0,j=0;
     int sum = 0;
     while(i<=j && j < nums.size()){
      sum += nums[j];
      if(sum < k && j-i+1 >= nums.size())
      return 0;
      while(sum >= k && i <= j){
        ans = min(ans,j-i+1);
        sum -= nums[i];
        ++i;
      }
      j++;
     }
     return ans; 
    }
};
