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
vector<int>Find_NLL(vector<int>& arr,int n)
    {
     vector<int>temp(n);
     stack<int>st;
     for(int i=0;i<n;i++)
     {
        if(st.empty()) temp[i]=-1;
        else
        {
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            temp[i] = st.empty() ? -1 : st.top();           
        }
        st.push(i);
     }
     return temp;
    }
vector<int>Find_NLR(vector<int>& arr,int n)
    {
     vector<int>temp(n);
     stack<int>st;
     for(int i=n-1;i>=0;i--)
     {
        if(st.empty()) temp[i]=n;
        else
        {
            while(!st.empty() && arr[st.top()]<arr[i]) st.pop();
            temp[i] = st.empty() ? n : st.top();
        }
        st.push(i);
     }
     return temp;
    }
    long long subArrayRanges(vector<int>& nums) 
    {
        long long n = nums.size(),left_ways=0,right_ways=0;
        long long sum_max = 0;
        long long sum_min = 0;
        vector<int>NSL = Find_NSL(nums,n);
        vector<int>NSR = Find_NSR(nums,n);
        vector<int>NLL = Find_NLL(nums,n);
        vector<int>NLR = Find_NLR(nums,n);
       const int MOD = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            long long sl_count = i - NSL[i];
            long long sr_count = NSR[i] - i;
            left_ways = (left_ways + (sl_count * sr_count) * nums[i]) ;
            long long ll_count = i - NLL[i];
            long long lr_count = NLR[i] - i;
            right_ways = (right_ways + (ll_count * lr_count) * nums[i]) ;
        }
        return (right_ways - left_ways ) ;
    }
};