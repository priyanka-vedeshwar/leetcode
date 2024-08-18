#ifndef __GRAPH__
#define __GRAPH__

/*
    refer   https://medium.com/@elifsenaa13/graph-data-structure-code-with-c-7865521849c3
        https://takeuforward.org/graph/graph-representation-in-c/
*/

#include <stack>
#include <queue>
#include <vector>
using namespace std;

namespace graph
{
    //(Un)Directed and Unweighted
    class Graph
    {
        int numVertices;
        vector<vector<int>> adjLists;
        vector<bool> visited;
        void dfs(int, vector<int> &);
        void bfs(int, vector<int> &);

    public:
        Graph(int);
        void addEdge(int src, int des, bool directed);
        void DFS(vector<vector<int>> &, int);
        void BFS(vector<int> &, int);
    };
    Graph::Graph(int vertices)
    {
        this->numVertices = vertices;
        this->adjLists = vector<vector<int>>(vertices);
        this->visited = vector<bool>(vertices, false);
    }
    void Graph::addEdge(int src, int des, bool directed)
    {
        this->adjLists[src].push_back(des);
        if (directed)
            this->adjLists[des].push_back(src);
    }
    void Graph::bfs(int vertice, vector<int> &res)
    {
        queue<int> q;
        q.push(vertice);
        this->visited[vertice] = true;
        while (!q.empty())
        {
            int curNode = q.front();
            q.pop();
            res.push_back(curNode);
            for (int vert : this->adjLists[curNode])
            {
                if (!(this->visited[vert]))
                {
                    q.push(vert);
                    this->visited[vert] = true;
                }
            }
        }
    }
    void Graph::BFS(vector<int> &res, int vertice)
    {
        this->visited = vector<bool>(this->numVertices, false);
        bfs(vertice, res);
        return;
    }
    void Graph::dfs(int vertice, vector<int> &res)
    {
        res.push_back(vertice);
        this->visited[vertice];
        for (auto vert : this->adjLists[vertice])
        {
            if (!this->visited[vert])
            {
                dfs(vert, res);
                this->visited[vert] = true;
            }
        }
    }
    void Graph::DFS(vector<vector<int>> &res, int vertice)
    {
        this->visited = vector<bool>(this->numVertices, false);
        vector<int> comp;
        dfs(vertice, comp);
        res.push_back(comp);
        return;
    }
};

#endif
