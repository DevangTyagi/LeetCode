class Solution {
public:
    int find_possible_subarrays(vector<int>& nums, int k)
    {
        int l=0,r=0,count=0,subarrays=0;
       while(r < nums.size())
       {
        if(nums[r]%2!=0)
        count++;
        while(count>k)
        {
            if(nums[l]%2!=0)
            {
                count--;
            }
            l++;
        }
        if(count<=k)
         subarrays += r-l+1;

         r++;
       }
       return subarrays;
    }
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
       int backward = find_possible_subarrays(nums,  k-1);
       int  forward = find_possible_subarrays(nums,  k);
       return forward - backward;
    }
};