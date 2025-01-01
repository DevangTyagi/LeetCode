class Solution {

public:
    int maxScore(string s) 
    {
        int ones = 0, curr_0 = 0, curr_1 = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '1') 
                ones++;      
        }
        for (int i = 0; i < s.size() - 1; i++){
            if (s[i] == '0')  
                curr_0++;
            else   
                curr_1++;
            ans = max(ans, curr_0 + (ones - curr_1));
        }
        
        return ans;
    }
};
