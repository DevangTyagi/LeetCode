class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>Result;
        int i=0,j=0;
        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i][0] == nums2[j][0]) {
                int val = nums1[i][1] + nums2[j][1];
                Result.push_back({nums1[i][0] , val});
                ++i;
                ++j;
            }
            else if(nums1[i][0] < nums2[j][0]) {
                Result.push_back(nums1[i]);
                ++i;
            }
            else {
                Result.push_back(nums2[j]);
                ++j;
            }
        }
        while(i < nums1.size()){
            Result.push_back(nums1[i]);
            i++;
        }
        while(j < nums2.size()){
            Result.push_back(nums2[j]);
            j++;
        }
        return Result;
    }
};