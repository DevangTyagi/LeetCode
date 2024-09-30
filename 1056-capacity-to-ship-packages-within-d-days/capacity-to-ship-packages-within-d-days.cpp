class Solution {
public:  
    int Calculate_days(vector<int>& weights,int cap)
    {
        int daycount=1;
        int load=0;
        for(int i=0;i<weights.size();i++)
        {
            if(load+weights[i]>cap)
            {
             daycount++;
             load=weights[i];   
            }
            else
            load+=weights[i];
        }
       
        return daycount; 
    }

    int shipWithinDays(vector<int>& weights, int days)
    {
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);
      int ans;
      while(low<=high)
      {
        int mid=(low+high)/2;
        int reqdays=Calculate_days(weights, mid);
        if(reqdays<=days)
        {
         ans=mid;
         high=mid-1;
        }
        else
        low=mid+1;
      }
      return ans;
    }
};