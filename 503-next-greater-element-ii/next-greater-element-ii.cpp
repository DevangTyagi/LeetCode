class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
       stack<int>S;
       int n = nums.size();
       vector<int>Greater_ele(n,-1);
       for(int i=2*n-1;i>=0;i--)
       {
        while(!S.empty() && S.top()<=nums[i%n]) S.pop();
        Greater_ele[i%n] = S.empty() ? -1 : S.top();
        S.push(nums[i%n]);
       }  
       return Greater_ele;
    }
};