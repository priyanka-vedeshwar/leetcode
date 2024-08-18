class Solution
{
public:
    vector<vector<int>> &dfs(vector<vector<int>> &results, vector<int> &paths, int curN, int des, vector<vector<int>> &adjList)
    {
        if (curN == des)
        {
            results.push_back(paths);
            return results;
        }
        for (int node : adjList[curN])
        {
            paths.push_back(node);
            dfs(results, paths, node, des, adjList);
            paths.pop_back();
        }
        return results;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        int target = int(graph.size()) - 1;
        vector<vector<int>> res{};
        vector<int> paths{0};
        dfs(res, paths, 0, target, graph);
        return res;
    }
};
