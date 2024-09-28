class Solution {
public:
    int beautySum(string s) {
        int totalBeauty = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);
            
            for (int j = i; j < n; j++)
            {
                freq[s[j] - 'a']++;                
                int maxFreq = 0;
                int minFreq = n;               
                for (int k = 0; k < 26; k++) {
                    if (freq[k] > 0) {
                        maxFreq = max(maxFreq, freq[k]);
                        minFreq = min(minFreq, freq[k]);
                    }
                }                
                totalBeauty += (maxFreq - minFreq);
            }
        }        
        return totalBeauty;
    }
};
