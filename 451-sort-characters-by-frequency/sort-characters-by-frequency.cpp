
class Solution {
public:
    string frequencySort(string s) {
        // Step 1: Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
            freqMap[c]++;
        }
        
        // Step 2: Create a vector of pairs (character, frequency)
        vector<pair<char, int>> freqVec(freqMap.begin(), freqMap.end());
        
        // Step 3: Sort the vector based on frequency in decreasing order
        sort(freqVec.begin(), freqVec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return b.second < a.second;
        });
        
        // Step 4: Build the result string
        string result;
        for (const auto& p : freqVec) {
            result.append(p.second, p.first);
        }
        
        return result;
    }
};