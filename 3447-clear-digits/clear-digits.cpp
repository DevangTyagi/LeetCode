class Solution {
public:
    string clearDigits(string s) {
        int count=0;
        string ans = "";
        for(int i=s.size()-1;i>=0;i--) {
          if(isdigit(s[i])) 
          count++;
          else if(count==0)
          ans.push_back(s[i]);
          else
          count--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};