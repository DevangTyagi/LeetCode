class Solution {
public:
    vector<int>Find_NSL(vector<int>& arr,int n)
    {
     vector<int>temp(n);
     stack<int>st;
     for(int i=0;i<n;i++)
     {
        if(st.empty()) temp[i]=-1;
        else
        {
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            temp[i] = st.empty() ? -1 : st.top();           
        }
        st.push(i);
     }
     return temp;
    }
    // Most important fact is that we don't need to count the duplicates in examples
    // like 2,6,2,4,2   for handleling this situation we just use >= in one case while use > in other case
    vector<int>Find_NSR(vector<int>& arr,int n)
    {
     vector<int>temp(n);
     stack<int>st;
     for(int i=n-1;i>=0;i--)
     {
        if(st.empty()) temp[i]=n;
        else
        {
            while(!st.empty() && arr[st.top()]>arr[i]) st.pop();
            temp[i] = st.empty() ? n : st.top();
        }
        st.push(i);
     }
     return temp;
    }
    int sumSubarrayMins(vector<int>& arr) 
    {
       long long ans=0;
       long long mod = 1e9+7;
       int n = arr.size();
       vector<int>NSL = Find_NSL(arr,n); // Array of Next smaller element in left 
       vector<int>NSR = Find_NSR(arr,n); //Array of Next smaller element in right 
       for(int i=0;i<n;i++)
       {
        long long left_count = i-NSL[i];
        long long right_count = NSR[i]-i;
        long long ways = left_count * right_count;
        long long Total_ways = (ways*arr[i]);
        ans = (ans + Total_ways)%mod;
       }
       return int(ans);
    }
};