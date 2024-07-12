class Solution {
public:
   vector<int>Find_NSL(vector<int>& heights,int n)
   {
     vector<int>temp(n);
     stack<int>st;
     for(int i=0;i<n;i++)
     {
        if(st.empty()) temp[i]=-1;
        else
        {
         while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
         temp[i] = st.empty() ? -1 : st.top();
        }
        st.push(i);
     }
     return temp;
   }
   vector<int>Find_NSR(vector<int>& heights,int n)
   {
     vector<int>temp(n);
     stack<int>st;
     for(int i=n-1;i>=0;i--)
     {
        if(st.empty()) temp[i]=n;
        else
        {
         while(!st.empty() && heights[st.top()] > heights[i]) st.pop();
         temp[i] = st.empty() ? n : st.top();
        }
        st.push(i);
     }
     return temp;
   }
    int largestRectangleArea(vector<int>& heights) 
    {
        int n = heights.size();
        int maxi = INT_MIN;
        vector<int>NSL = Find_NSL(heights,n);
        vector<int>NSR = Find_NSR(heights,n);
        for(int i=0;i<heights.size();i++)
        {
           int ans = (NSR[i]-NSL[i]-1)*heights[i];
           maxi = max(maxi,ans);
        }
        return maxi;
    }
};