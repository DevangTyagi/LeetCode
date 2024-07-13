class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>ans;
        deque<int>dq;
        for(int i=0;i<nums.size();i++)
        {
            if(!dq.empty() && dq.front() == i-k) dq.pop_front();  //Front is out of the bound
            while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();  // smaller elements are removed from the deque
            dq.push_back(i);
            if(i>=k-1) ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};