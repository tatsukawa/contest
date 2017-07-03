#include <bits/stdc++.h>

using namespace std;

const int MAX_V = 256;
const int INF = 1e8;
typedef pair<int, int> P; 

struct edge
{
    int to, cap, cost, rev;
    edge(int t, int ca, int co, int re) : to(t), cap(ca), cost(co), rev(re) { }
};

int V;                          
vector<edge> G[MAX_V];          
int h[MAX_V];                   
int dist[MAX_V];                
int prevv[MAX_V], preve[MAX_V]; 

void add_edge(int from, int to, int cap, int cost)
{
    G[from].emplace_back(edge(to, cap, cost, G[to].size()));
    G[to].emplace_back(edge(from, 0, -cost, G[from].size() - 1));
}

int min_cost_flow(int s, int t, int f)
{
    int res = 0;
    fill(h, h + V, 0); 
    fill(prevv, prevv + V, -1);
    fill(preve, preve + V, -1);

    while (f > 0)
    {
        priority_queue<P, vector<P>, greater<P>> que;
        fill(dist, dist + V, INF);
        dist[s] = 0;
        que.push(P(0, s));
        while (!que.empty())
        {
            P p = que.top();
            que.pop();
            int v = p.second;
            if (dist[v] < p.first) continue;
            for (int i = 0; i < G[v].size(); i++)
            {
                edge &e = G[v][i];
                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])
                {
                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    que.push(P(dist[e.to], e.to));
                }
            }
        }
        if (dist[t] == INF)
        {
            return -1;
        }
        for (int v = 0; v < V; v++) h[v] += dist[v];

        int d = f;
        for (int v = t; v != s; v = prevv[v])
        {
            d = min(d, G[prevv[v]][preve[v]].cap);
        }
        f -= d;
        res += d * h[t];
        for (int v = t; v != s; v = prevv[v])
        {
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }

    return res;
}

// 1 > 2
bool is_connected(
    int x1, int y1, int z1,
    int x2, int y2, int z2)
{
    return (x1 > x2 and y1 > y2 and z1 > z2);
}

int main()
{
    while (cin >> V)
    {
        if (V == 0)
            break;

        for(int i = 0; i < MAX_V; i++) {
            G[i].clear();
        }

        vector<vector<int>> vec(V, vector<int>(3));

        int all_cost = 0;

        for (int i = 0; i < V; i++)
        {
            int tmp = 1;
            for(int j = 0; j < 3; j++) {
                cin >> vec[i][j];
                tmp *= vec[i][j];
            }
            sort(vec[i].begin(), vec[i].end());
            all_cost += tmp;
        }

       int s = 2*V;
       int t = 2*V+1;

       int cnt = 0;

        for (int i = 0; i < V; i++)
        {
            int x1 = vec[i][0];
            int y1 = vec[i][1];
            int z1 = vec[i][2];

            for (int j = 0; j < V; j++)
            {
                int x2 = vec[j][0];
                int y2 = vec[j][1];
                int z2 = vec[j][2];

                if (is_connected(x2, y2, z2, x1, y1, z1))
                {
                    // 2 > 1
                    add_edge(i, j+V, 1, 0);
                }

            }
        }
        
        for(int i = 0; i < V; i++) {
            add_edge(s, i, 1, 0);
            add_edge(i, t, 1, vec[i][0]*vec[i][1]*vec[i][2]);
            add_edge(i+V, t, 1, 0);
        }


        int x = V;
        V = 2*V+2;

        cout << min_cost_flow(s, t, x) << endl;
    }
}

