class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        queue<int> q;
        vector<int> order;
        for (auto pre : prerequisites){
            int course = pre[0];
            int prereq = pre[1];
            adj[prereq].push_back(course);
            indegree[course]++;
        }        
        for (int i = 0; i < numCourses; i++){
            if (indegree[i] == 0) {
                q.push(i);
            }
        }       
        while (!q.empty()){
            int course = q.front();
            q.pop();
            order.push_back(course);
            
            for (int nextCourse : adj[course]){
                indegree[nextCourse]--;           //reducing the prerequisite courses
                if (indegree[nextCourse] == 0){
                    q.push(nextCourse);
                }
            }
        }
        
        return (order.size() == numCourses) ? order : vector<int>{};
    }
};
