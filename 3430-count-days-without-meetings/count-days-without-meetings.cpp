#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        if (meetings.empty()) return days;

        // Sort meetings by start time
        sort(meetings.begin(), meetings.end());

        int occupiedDays = 0, prevEnd = 0;

        // Merge intervals and calculate occupied days
        for (const auto& meeting : meetings) {
            int start = meeting[0], end = meeting[1];

            // If the current meeting starts after the last merged meeting
            if (start > prevEnd) {
                occupiedDays += (end - start + 1);  // New occupied days
            }
            // If overlapping, only count the extra days
            else if (end > prevEnd) {
                occupiedDays += (end - prevEnd);
            }

            prevEnd = max(prevEnd, end); // Update the latest occupied day
        }

        // Available days = Total days - Occupied days
        return days - occupiedDays;
    }
};
