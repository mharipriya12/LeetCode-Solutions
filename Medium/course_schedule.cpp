#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool canFinish(int numCourses,
               vector<vector<int>>& prerequisites) {

    vector<vector<int>> graph(numCourses);
    vector<int> indegree(numCourses, 0);

    for (auto prerequisite : prerequisites) {
        int course = prerequisite[0];
        int required = prerequisite[1];

        graph[required].push_back(course);
        indegree[course]++;
    }

    queue<int> q;

    for (int i = 0; i < numCourses; i++) {
        if (indegree[i] == 0)
            q.push(i);
    }

    int completed = 0;

    while (!q.empty()) {
        int course = q.front();
        q.pop();

        completed++;

        for (int next : graph[course]) {
            indegree[next]--;

            if (indegree[next] == 0)
                q.push(next);
        }
    }

    return completed == numCourses;
}

int main() {
    int numCourses = 2;

    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    cout << (canFinish(numCourses, prerequisites)
                 ? "true"
                 : "false");

    return 0;
}
