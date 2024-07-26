class Solution {
public:
    int numberOfSubstrings(string s) 
    {
       int count = 0;
       vector<int>pos{-1,-1,-1};
       for(int i=0;i<s.size();i++)
       {
        pos[s[i]-'a'] = i;
        if(pos[0]!=-1 && pos[1]!=-1 && pos[2]!=-1)
        {
            count = count + (1 + min(pos[0],min(pos[1],pos[2])));
        }
       }
       return count;
    }
};