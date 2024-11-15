class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) 
    {
        int i=0,j=arr.size()-1;
         while(j > 0 && arr[j-1] <= arr[j]){ //going back till we are getting sorted from back side
                --j;
            }     
        int ans = j; // we are removing all elements before j(i.e. considering them to be a non decresing sorted array in case it is not a decrecing type array then next steps will trip the useful element and decrease the ans)  
        while(i < j && (i==0 || arr[i] >= arr[i-1]))
        {           
            while(j < arr.size() && arr[i]>arr[j])  //To again point j to a number greater than or equal to the number at i to maintain i&j(i.e what starts with j should be greater tha what present at i) sorting relation
            j++;
            ans = min(ans,j-i-1);
            i++;
        } 
        return ans;
    }
};