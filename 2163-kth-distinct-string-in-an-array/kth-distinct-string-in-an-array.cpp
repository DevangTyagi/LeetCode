class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        string ans = "";
        unordered_map<string,int>mpp;
        for(int i=0;i<arr.size();i++)
        {
            mpp[arr[i]]++;
        }
        int j=0;
        while(j<arr.size())
        {
            if(mpp[arr[j]]==1)
            {
            ans=arr[j];
            k--;
            } 
            if(k==0)
            return ans;  
            j++;       
        }
        return "";
    }
};