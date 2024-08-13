class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        
        for (char c : s) {
            if (c == '(') {
                low++;
                high++;
            } else if (c == ')') {
                low = max(0, low - 1);
                high--;
            } else {  // c == '*'
                low = max(0, low - 1);  // '*' can act as ')'
                high++;  // '*' can act as '('
            }
            
            if (high < 0) {
                return false;  // more ')' than we can match
            }
        }
        
        return low == 0;  // all open parentheses are matched
    }
};
