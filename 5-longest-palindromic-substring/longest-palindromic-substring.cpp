class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        if (s.size() == 1) return s;
        
        int start = 0, maxLength = 1;
        
        for (int i = 0; i < s.size(); ++i) {
            // Odd length palindromes
            int low = i, high = i;
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                int currentLength = high - low + 1;
                if (currentLength > maxLength) {
                    start = low;
                    maxLength = currentLength;
                }
                --low;
                ++high;
            }
            
            // Even length palindromes
            low = i, high = i + 1;
            while (low >= 0 && high < s.size() && s[low] == s[high]) {
                int currentLength = high - low + 1;
                if (currentLength > maxLength) {
                    start = low;
                    maxLength = currentLength;
                }
                --low;
                ++high;
            }
        }
        
        return s.substr(start, maxLength);
    }
};
