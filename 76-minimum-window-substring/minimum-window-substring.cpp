class Solution {
public:
    string minWindow(string s, string t) 
    {
        int n = t.size(),r=0,l=0;
        int m = s.size(),minlen=INT_MAX;
        int Start_index = -1,count = 0;
        vector<int>Alpha(256,0);

        for(int i=0;i<n;i++)
        {
          Alpha[t[i]]++;
        }

        while(r<m)
        {
           if(Alpha[s[r]]>0) 
           count++;
           Alpha[s[r]]--;
           while(count==n)
           {
             if(r-l+1<minlen){
                minlen=r-l+1;
                Start_index=l;
             }
             Alpha[s[l]]++;
             if(Alpha[s[l]]>0){
               count--;
             }                   
              l++;
           }

           r++;
        }
       if (Start_index == -1) 
            return "";
        
        return s.substr(Start_index, minlen);
    }
};