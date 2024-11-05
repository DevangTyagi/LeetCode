class Solution {
public:
    int minChanges(string s) 
    {
        int n = s.size();
        int i=0,j=1,count = 0;
        if(n==0) return 0;
        while(j < n){
            if(s[i]!=s[j])
            count++;
            i=i+2;
            j=j+2;
        }
        return count;
    }
};