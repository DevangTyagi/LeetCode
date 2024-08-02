class Solution {
public:
    int minSwaps(vector<int>& nums) 
    {
        int l=0,r=0,ones=0,zeroes=0;
        int swap=0,ans=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            ones++;
        }
        if(ones==0) return 0;
        while(r<2*nums.size())
        {
            if(nums[r%nums.size()]==0)
            swap++;
            while(r-l+1>ones)
            {
                if(nums[l%nums.size()]==0)
                swap--;
                l++;
            }
            if(r-l+1==ones)
            {
                ans=min(ans,swap);
            }
            r++;
        }
        return ans;
    }
};