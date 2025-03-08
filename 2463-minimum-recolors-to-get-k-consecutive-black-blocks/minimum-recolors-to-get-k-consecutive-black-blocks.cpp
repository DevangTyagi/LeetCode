class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans ,n = blocks.size() ,opr=0;
        for(int i=0;i<k;i++) {
            if(blocks[i]=='W'){
                opr++;
            }
        }
        ans = opr;
        int i=0,j=k;
        while(j < n) {
        if(blocks[i] == 'W' && opr > 0) opr--;
        if(blocks[j] == 'W') opr++;
        ans = min(ans,opr);
        i++;
        j++;
        }
        return ans;
    }
};