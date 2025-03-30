class Solution {
public:
    void Merge(vector<vector<int>>& merged, vector<int> temp) {
        if (merged.empty()) 
            merged.push_back(temp);
        else if (merged.back()[1] >= temp[0])  // ✅ Fix: Use '>=' to check overlap
            merged.back()[1] = max(merged.back()[1], temp[1]);
        else
            merged.push_back(temp);
    }

    vector<int> partitionLabels(string s) {
        vector<int> ans;
        unordered_map<char, vector<int>> mpp;

        // Store first and last occurrence of each character
        for (int i = 0; i < s.size(); i++) {
            if (mpp.find(s[i]) == mpp.end())
                mpp[s[i]] = {i, i};  // Initialize both first and last position
            else
                mpp[s[i]][1] = i;  // Update last occurrence
        }

        // Collect all intervals in a vector
        vector<vector<int>> intervals;
        for (auto itr : mpp)
            intervals.push_back(itr.second);

        // Sort intervals by start index
        sort(intervals.begin(), intervals.end());

        // Merge intervals
        vector<vector<int>> merged;
        for (auto temp : intervals)
            Merge(merged, temp);

        // Compute partition lengths
        for (auto itr : merged)
            ans.push_back(itr[1] - itr[0] + 1);

        return ans;
    }
};
