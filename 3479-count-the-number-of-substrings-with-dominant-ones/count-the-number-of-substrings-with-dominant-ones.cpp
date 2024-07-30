class Solution {
public:
    int numberOfSubstrings(string s)
    {
      int l=0,r=0;
      int n = s.size();
      vector<int>prefix_sum(n);
      int sum_one=0,ans=0;
      for(int i=0;i<n;i++)
      {
        if(s[i]=='1'){
            sum_one++;         
        }
          prefix_sum[i]=sum_one;
      }
      while(l<s.size())
      {
        r=l;
        int ones=0,zeroes=0;
       while(r<n)
       {
        if(l==0) 
        ones = prefix_sum[r];
        else
        ones = prefix_sum[r]-prefix_sum[l-1];
        zeroes = r-l+1 - ones;
        if(zeroes*zeroes<=ones)
        {
            ans++;
            if(zeroes*zeroes<ones)
            {
                int valid = sqrt(ones)-zeroes;
                int nextr = r+valid;
                if(nextr>=n) ans+=n-r-1;
                else ans+=valid;
                r = nextr;
            }
        }
        else
        {
            r += zeroes*zeroes-ones-1;
        }
        r++;
       }
       l++;
      }  
      return ans;
    }
};