class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size();
        if(n == 1) return 1;
        int sum = 1;
        int i=1;
         
        while(i<n)
        {
            if(ratings[i] == ratings[i-1])
            {
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i<n && ratings[i] > ratings[i-1])
            {
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i<n && ratings[i] < ratings[i-1])   // down is used to find peak of downward slope in reverse direction i.e from up to down
            {               
                sum += down;
                down++;
                i++;
            }
            if(down > peak) sum += (down - peak);
        }
        return sum;
    }
};
