class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        if (k > n) return 0;
        if (k <= 1) return n;
        
        int count = 0;
        
        vector<bool> alternates(n);
        for (int i = 0; i < n; i++) {
            alternates[i] = (colors[i] != colors[(i + 1) % n]);
        }
        
        int alternatingPairs = 0;
        for (int i = 0; i < k - 1; i++) {
            if (alternates[i]) alternatingPairs++;
        }
        
        if (alternatingPairs == k - 1) {
            if ((k % 2 == 0 && colors[0] != colors[(k - 1) % n]) || 
                (k % 2 == 1 && colors[0] == colors[(k - 1) % n])) {
                count++;
            }
        }
        
        for (int i = 1; i < n; i++) {
            if (alternates[(i - 1 + n) % n]) alternatingPairs--;
            if (alternates[(i + k - 2) % n]) alternatingPairs++;
            
            if (alternatingPairs == k - 1) {
                int first = i;
                int last = (i + k - 1) % n;
                
                if ((k % 2 == 0 && colors[first] != colors[last]) || 
                    (k % 2 == 1 && colors[first] == colors[last])) {
                    count++;
                }
            }
        }
        
        return count;
    }
};