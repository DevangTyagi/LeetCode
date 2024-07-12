class Solution {
public:
    string removeKdigits(string num, int k) 
    {
      stack<char>st;
      if(num.size()==1 && k>0) return "0";

      for(int i=0;i<num.size();i++)
      {
        while(!st.empty() && k>0 && st.top()>num[i]) 
        {
            st.pop();
            --k;
        }
        if(!st.empty() || num[i]!='0')
        st.push(num[i]);
      }

        while(!st.empty() && k>0)
        {
            st.pop();
            k--;
        }
        
      string ans;
      if(st.empty()) return "0";
      while(!st.empty())
      {
        ans+=st.top();
        st.pop();
      }
      reverse(ans.begin(),ans.end());
      return ans;
    }
};