
class Solution {
public:
    std::string reverseWords(std::string s) 
    {
        int left = 0;
        int right = s.length() - 1;

        // Skip leading spaces
        while (left <= right && s[left] == ' ') left++;
        
        // Skip trailing spaces
        while (right >= left && s[right] == ' ') right--;
        
        std::string temp = "";
        std::string ans = "";
        
        while (left <= right) {
            char ch = s[left];
            if (ch != ' ') {
                temp += ch;
            } else if (ch == ' ' && !temp.empty()) {
                if (!ans.empty()) ans = temp + " " + ans;
                else ans = temp;
                temp = "";
            }
            left++;
        }
        
        if (!temp.empty()) {
            if (!ans.empty()) ans = temp + " " + ans;
            else ans = temp;
        }
        
        return ans;
    }
};

