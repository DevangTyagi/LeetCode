class Solution {
public:
 vector<int>Find_NSL(vector<int>& heights,int n)
   {
     vector<int>temps(n);
     stack<int>st;
     for(int i=0;i<n;i++)
     {
        if(st.empty()) temps[i]=-1;
        else
        {
         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
         temps[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
     }
     return temps;
   }
   vector<int>Find_NSR(vector<int>& heights,int n)
   {
     vector<int>temps(n);
     stack<int>st;
     for(int i=n-1;i>=0;i--)
     {
        if(st.empty()) temps[i]=n;
        else
        {
         while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
         temps[i] = st.empty() ? n : st.top();
        }
        st.push(i);
     }
     return temps;
   }

    int maximalRectangle(vector<vector<char>>& matrix) 
    {
     int rows = matrix.size();
     if (rows == 0) return 0;
     int cols = matrix[0].size();
     int maxi = INT_MIN;
     vector<int> heights(cols, 0);
       for(int i=0;i<rows;i++)
       {
        for(int j=0;j<cols;j++)
          heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;

          int n = heights.size();
          vector<int>NSL = Find_NSL(heights,n);
          vector<int>NSR = Find_NSR(heights,n);
          
        for(int i=0;i<cols;i++)
        {
          int ans = heights[i]*(NSR[i]-NSL[i]-1);
          maxi = max(maxi,ans);
        }
       }
       
     return maxi;
    }
};