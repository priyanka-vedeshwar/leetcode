class Solution
{
public:
    int findCenter(vector<vector<int>> &edges)
    {
        map<int, int> count;
        for (vector<int> e : edges)
        {
            count[e[0]]++;
            count[e[1]]++;
            if (count[e[0]] > 1)
                return e[0];
            if (count[e[1]] > 1)
                return e[1];
        }
        if (edges.size() == 1)
            return edges[0][1];
        return 0;
    }
};
