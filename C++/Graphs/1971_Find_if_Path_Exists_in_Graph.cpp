class Solution
{
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination)
    {
        if (n == 1 && source == destination)
            return true;
        vector<vector<int>> adjList(n);
        vector<bool> visited(n, false);
        for (vector<int> e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        queue<int> q;
        q.push(source);
        visited[source] = true;
        while (!q.empty())
        {
            int curNode = q.front();
            q.pop();
            if (curNode == destination)
                return true;
            for (int node : adjList[curNode])
            {
                if (!visited[node])
                {
                    visited[node] = true;
                    q.push(node);
                }
            }
        }
        return false;
    }
};
