class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=0,neg=0,zero=0;
        int size = nums.size();
        for(auto it : nums) {
            if(it < 0) neg++;
            else if(it == 0) zero++;
            else break;
        }
        pos = size - neg - zero;
        return max(neg,pos);
    }
};