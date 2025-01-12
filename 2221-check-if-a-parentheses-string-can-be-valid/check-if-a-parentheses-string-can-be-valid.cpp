class Solution {
public:
    bool canBeValid(string s, string locked) {
      if(s.size()%2 != 0)
       return false;
      stack<int>flexi;
      stack<int>open;
      for(int i=0;i<s.size();i++){ 
         if(locked[i] == '0')
            flexi.push(i);
         else if(s[i] == '('){
            open.push(i);
         }
         else {
            if(!open.empty() && s[i] == ')')
            open.pop();
            else if( open.empty() && !flexi.empty() && s[i] == ')' )
            flexi.pop();
            else
            return false;
         }
      }
       while(!open.empty() && !flexi.empty() && flexi.top() > open.top()){
            open.pop();
            flexi.pop();
        }
       
      return open.empty();
    }
};