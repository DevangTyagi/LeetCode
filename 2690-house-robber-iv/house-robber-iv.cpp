class Solution {
public:
bool check_valid(vector<int>& nums, int cap, int k) {
    int count = 0;
    for(int i=0;i<nums.size();i++) {
        if(nums[i] <= cap) {
            i++;
            count++;
        }
    }
    return count >= k;
}
    int minCapability(vector<int>& nums, int k) {
        int l = *min_element(nums.begin(),nums.end());
        int r = *max_element(nums.begin(),nums.end());
        int ans = 0;
        // auto check_valid = [&](){

        // }
        while(l <= r ) {
             int mid  = l + (r-l)/2;
             if(check_valid(nums,mid,k)) {
                ans = mid;
                r = mid - 1;
             }
             else
             l = mid + 1;
        }
        return ans;
    }
};