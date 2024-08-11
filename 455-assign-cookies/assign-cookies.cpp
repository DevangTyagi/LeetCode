class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        int count = 0;
        int i=0,j=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        if(s.size()==0)  return 0;
        while(i<g.size())
        {
            if(j==s.size()) break;
            if(s[j]>=g[i])
            {
                count++;
                i++;
                j++;
            }
            else 
            j++;
        }
        return count;
    }
};