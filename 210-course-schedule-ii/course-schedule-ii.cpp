class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> visited(numCourses, 0);
        
        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            visited[course]++;
        }
        
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> order;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            order.push_back(course);
            
            for (int nextCourse : adj[course]) {
                visited[nextCourse]--;
                if (visited[nextCourse] == 0) {
                    q.push(nextCourse);
                }
            }
        }
        
        return (order.size() == numCourses) ? order : vector<int>{};
    }
};
