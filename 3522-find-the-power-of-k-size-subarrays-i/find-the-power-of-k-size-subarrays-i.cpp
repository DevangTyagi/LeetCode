class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) 
    {
        vector<int>ans;
        for(int i=0;i<nums.size()-k+1;i++)
        {
            bool consecutive = true;
            for(int j=i+1;j<i+k;j++){
             if(nums[j] != nums[j-1]+1)
             consecutive = false;
            }
            if(consecutive)
            ans.push_back(nums[i+k-1]);
            else
            ans.push_back(-1);
        }
        return ans;
    }
};