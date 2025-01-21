class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long First_row_sum = accumulate(begin(grid[0]),end(grid[0]),0LL);
        long long second_row_sum = 0;
        long long minimized_rb2_sum = LONG_LONG_MAX;
        for(int rb1=0;rb1<grid[0].size();rb1++){  //rb1=>robot1
          First_row_sum -= grid[0][rb1];
          long long best_Of_rb2 = max (First_row_sum , second_row_sum);
          minimized_rb2_sum = min (minimized_rb2_sum , best_Of_rb2);  
          second_row_sum += grid[1][rb1];
        }
        return minimized_rb2_sum;
    }
};