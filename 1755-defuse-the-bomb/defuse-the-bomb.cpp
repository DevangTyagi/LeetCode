class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n = code.size();
       vector<int>ans;
     if(k>0){
        for(int i=0;i<n;i++){
            int temp =0;
            int sum = 0;
            for(int j = i+1;j<2*n;j++){
                if(temp==k)
                break;
                temp++;
                sum += code[j%n];
            }
            ans.push_back(sum);
        }
        return ans;
     }
     if(k<0){
        for(int i=2*n-1;i>=n;i--){
            int temp =0;
            int sum = 0;
            for(int j = i-1;j>=0;j--){
                if(temp==abs(k))
                break;
                temp++;
                sum += code[j%n];
            }
            ans.push_back(sum);
        }
        reverse(ans.begin(),ans.end());
        return ans;
     }
     for(int i = 0;i<code.size();i++){
            ans.push_back(0);
       } 
       return ans;
    }
};