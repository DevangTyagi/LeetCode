class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<int, int> nextGreater;
        stack<int> s;

        // Traverse nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            // Maintain elements in decreasing order in the stack
            while (!s.empty() && s.top() <= nums2[i]) {
                s.pop();
            }

            // The top of the stack is the next greater element
            nextGreater[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        // Prepare the result for nums1
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(nextGreater[num]);
        }

        return ans;
    }
};
