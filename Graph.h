//随机函数,kd树主体,最短路函数等
// #include<bits/stdc++.h>
// #include<bits/extc++.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <map>
#include <windows.h>
#include <queue>
#include <random>
#include "otherClasses.h"

// 也许并不需要
// 生成随机数
unsigned long long myrand(unsigned range = 0)
{
    static std::mt19937 rd(time(0)); // 静态随机生成器，每次调用 myrand 时都会继续使用同一个随机数生成器，从而保证随机数序列的连续性，随机种子time(0)
    if (!range) return rd(); // 如果range==0 返回的是生成的随机数
    return rd() % range; // 返回[0,rang-1]的随机数
}


class Graph
{
    bool Randflg;
    unsigned int PointNums;
    HANDLE RandFlowThread;
public:
    std::vector<std::vector<std::pair<int, int>>> G; // 这里记录两个数: first记录其目的点标号, second记录该边标号
    std::vector<Point> P; // 点池, 用来存放点的信息, 标号从1开始
    std::vector<Edge> E;  // 边池, 用来存放边的信息, 标号从0开始
    // 感觉不太需要这个构造函数. 可以设定为构造的时候一定要制定点数.
    // Graph() {}
private:
    // 辅助函数, 增加边
    void AddEdge(int u, int v)
    {
        double _dis = distance(P[u], P[v]);
        int _cap = (int)(myrand(RAND_MAX) * 1.0 / RAND_MAX + 1) * (int)(_dis) / 20 + myrand(37) + 79;
        E.push_back(Edge(u, v, _dis, _cap, _cap * 2 / 5));
        G[u].push_back({v, (int)E.size() - 1});
        E.push_back(Edge(v, u, _dis, _cap, _cap * 2 / 5));
        G[v].push_back({u, (int)E.size() - 1});
    }

    // 测试最短路
    // n是当前结点, f是n的父节点.
    std::vector<bool> dfsvis;
    void dfshp(int n, int f)
    {
        dfsvis[n] = 1;
        std::cout << n << ' ' << f << '\n';
        for (auto [to, e] : G[n])
        {
            if (dfsvis[to])
                continue;
            printf("%d ---> %d : %d/%d (%lf)\n", n, to, E[e].flow, E[e].capacity, 1.0 * E[e].flow / E[e].capacity);
            dfshp(to, n);
        }
    }

public:
    // 构造一个点数为n的图, 要求尽量合理
    Graph(int __n)
    {
        int row = sqrt(__n), col = __n / row;
        __n = row * col; // int数据可能会导致失真，所以分块后要重置__n大小
        PointNums = __n;
        srand(time(0));    // 设置随机种子
        G.resize(__n + 1); // 给图分配邻接链表空间
        P.resize(__n + 1); // 给点分配空间

        // 按照行列分块, 初始化各个点的整型值
        // 横纵坐标的最大值分别为：rlimit*row, climit*col 均为32700
        int rlimit = RAND_MAX / row, climit = RAND_MAX / col; // RAND_MAX随机生成数的最大值，单位化
        // 一列一列初始化
        for (int i = 1; i <= row; ++i)
        {
            for (int j = 1; j <= col; ++j)
            {
                int now = j + (i - 1) * col; // now是点的标号
                // 生成的整数点坐标保证在x:[(i - 1) * rlimit, i * rlimit], y:[(j - 1) * climit, j * climit]方块内
                // 保证随机生成的点能均匀分布
                P[now].x = myrand(rlimit) + (i - 1) * rlimit;
                P[now].y = myrand(climit) + (j - 1) * climit;
            }
        }

        // 初始化各个点的浮点值
        for (int i = 1; i <= __n; ++i)
        {
            P[i].x += 1.0 * myrand(RAND_MAX) / ((int)RAND_MAX), P[i].y += 1.0 * myrand(RAND_MAX) / ((int)RAND_MAX); // *1.0使结果变成double而不是int
        }

        //生成连通图+随机生成边
        Kruskal();
    }
    ~Graph() {}

    bool segmentsIntersect(const Point& A, const Point& B, const Point& C, const Point& D) {
        // 快速排斥实验
        if (max(A.x, B.x) < min(C.x, D.x) || max(C.x, D.x) < min(A.x, B.x) ||
            max(A.y, B.y) < min(C.y, D.y) || max(C.y, D.y) < min(A.y, B.y)) {
            return false;
        }
        // 跨立实验
        Vector AB = B - A;
        Vector AC = C - A;
        Vector AD = D - A;
        Vector CD = D - C;
        Vector CA = A - C;
        Vector CB = B - C;
        double cross1 = AB * AC;
        double cross2 = AB * AD;
        double cross3 = CD * CA;
        double cross4 = CD * CB;
        return (cross1 * cross2 < 0) && (cross3 * cross4 < 0);
    }

    //生成边
    void Kruskal()
    {
        DSU dsu(PointNums);
        int cnt=PointNums;
        vector<Edge> candidateEdges;

        //生成kd树
        KDTree kdTree(P);
        //把层数写进点池
        kdTree.writeLayer(P);

        // 生成候选边（每个点连接最近的10个邻近点）
        for (int i = 1; i <= PointNums; ++i) {
            vector<int> neighbors = kdTree.kNearestSearch(P[i], 10);
            for (int j : neighbors) {
                if (i != j) {
                    double dist = distance(P[i], P[j]);
                    candidateEdges.push_back(Edge(i, j, dist, 0, 0)); // 容量和流量暂时设为0
                }
            }
        }

        //按边权从小到大排序
        sort(candidateEdges.begin(), candidateEdges.end(), [](const Edge& a, const Edge& b) {
            return a.length < b.length;
        });

        //Kruskal算法构建MST
        for (const Edge& e : candidateEdges) {
            if (!dsu.isConnected(e.P1, e.P2)) {
                AddEdge(e.P1,e.P2);
                dsu.unite(e.P1, e.P2);
                cnt--;
            }
            if(cnt==1)break;
        }
        for (int i = 1; i < PointNums; ++i) {
            int add=0;
            vector<int> neighbors = kdTree.kNearestSearch(P[i], 20); // 查找 20个邻近节点
            for (int j : neighbors) {
                if (i != j && rand() % 100 < 20 ) { // 30% 概率加边
                    //检查新边是否与现有边交叉
                    bool isCrossing = false;
                    for (const Edge& e : E) {
                        Point C = P[e.P1], D = P[e.P2];
                        if (segmentsIntersect(P[i], P[j], C,D)) {
                            isCrossing = true;
                            break;
                        }
                    }
                    if (!isCrossing) {
                        AddEdge(i,j);
                        dsu.unite(i, j);
                        add++;
                    }
                    if(add==2)break;
                }
            }
        }
    }

    // 返回输入点附近的100个点的标号
    // 遍历全部点，用大顶堆找出附近一百个点
    // 疑问：点的距离是值直线距离还是可行路径的距离？
    std::vector<int> GetClosestPoints(Point Now_p)
    {
        std::vector<int> ret;
        // 存放100个点的堆，first是距离，second是点的标号
        // 默认比较函数：std::less 按照字典序进行比较，即先比较 double，如果相等再比较 int
        std::priority_queue<std::pair<double, int> > pq;

        // 如果加上比较，满了之后只有<pq.top()才能push进去会不会更快？ 应该优化空间不大
        for (int i = 1; i <= (int)PointNums; ++i) {
            pq.push({distance(P[i], Now_p), i}); // priority_queue默认大顶堆
            if (pq.size() > 100) pq.pop();
        }

        // 把最近的至多100个点放入ret返回.
        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            ret.push_back(x.second);
        }
        return ret;
    }

    // 返回邻接链表的头指针
    std::vector<std::vector<std::pair<int, int>>>::iterator GraphHead()
    {
        return G.begin();
    }
    // 返回点池的首指针
    std::vector<Point>::iterator PointHead()
    {
        return P.begin();
    }
    // 返回边池的首指针
    std::vector<Edge>::iterator EdgeHead()
    {
        return E.begin();
    }
    // 返回图中点的数目
    unsigned GetPointNums()
    {
        return PointNums;
    }
    // 返回图中边的数目
    unsigned GetEdgeNums()
    {
        return (unsigned)E.size();
    }

    // 随机函数进行随机的流的分配
    DWORD WINAPI static RandFlow(LPVOID lpParameter)
    {
        // 将无类型指针 lpParameter 转换为所需要的 Graph 指针. 然后在图上进行随机修改
        Graph *This = (Graph *)lpParameter;
        while (This->Randflg)
        {
            // 遍历所有的边进行随机修改.
            for (int i = 0; i < (int)This->E.size(); i += 2)
            {
                // 先进行一个至多 0.76 次方的随机上下浮动
                This->E[i].flow += ((int)myrand() - (int)myrand()) % ((int)pow(This->E[i].flow, 0.76) + 1);

                // 处理向下溢出的情况(flow 是 unsigned 的)
                if (This->E[i].flow > 100000000)
                    This->E[i].flow = std::max(0u, This->E[i].flow + std::min(0u, (unsigned int)sqrt(This->E[i].capacity)));
                // 处理 flow 超出2倍的 capacity 的情况.
                if (This->E[i].flow > This->E[i].capacity * 2)
                    This->E[i].flow = std::min(This->E[i].capacity * 2, This->E[i].flow - (int)sqrt(This->E[i].capacity * 2));
                // 处理无向图的另一条对应的边.
                This->E[i + 1].flow = This->E[i].flow;
            }
            Sleep(1000);
        }
    }
    // 创建一个进程来改变flow
    void StartRandFlow()
    {
        Randflg = 1;
        // 把线程id放在类里, 到时候看一下怎么搞这个线程.
        RandFlowThread = CreateThread(NULL, 0, RandFlow, this, 0, NULL);
    }

    void StopRandFlow()
    {
        Randflg = 0;
    }

    // 启发式函数，使用欧几里得距离
    double heuristic(int current, int end, Graph* Gp) {
        return distance(Gp->P[current], Gp->P[end]);
    }

    // 计算边的实际长度
    void Time(std::vector<Edge>& E, Graph* Gp) {
        for (int i = 0; i < (int)Gp->E.size(); i += 1) {
            if (E[i].flow <= E[i].capacity)
                E[i].reallength = E[i].length / 50;
            else {
                double x = (double)E[i].flow / E[i].capacity;
                E[i].reallength = E[i].length / 50 * (1 + std::exp(x));
            }
        }
    }

    // A* 算法
    std::vector<int> dij(int start, int end, Graph* Gp, bool time, double& distance, double& tim) {
        tim = 0;
        distance = 0;
        auto E = Gp->E;
        std::vector<int> path;
        auto G = Gp->G;
        int n = Gp->P.size() - 1;
        Time(E, Gp);
        std::vector<double> g(n + 1, 1000000000);
        std::vector<double> f(n + 1, 1000000000);
        std::priority_queue<std::pair<double, std::pair<int, int>>, std::vector<std::pair<double, std::pair<int, int>>>, std::greater<std::pair<double, std::pair<int, int>>>> hp;
        g[start] = 0;
        f[start] = heuristic(start, end, Gp);
        hp.push({ f[start], {start, 0} });
        std::vector<int> fa(n + 1);
        std::vector<bool> vis(n + 1);

        while (!hp.empty()) {
            auto [f_val, nowe] = hp.top();
            auto [now, fae] = nowe;
            hp.pop();
            if (vis[now])
                continue;
            if (now == end) {
                while (now != start) {
                    path.push_back(fa[now]);
                    now = E[fa[now]].P1;
                }
                for (int i = 0; i < (int)path.size(); i++) {
                    tim += E[path[i]].reallength;
                    distance += E[path[i]].length;
                }
                return path;
            }
            vis[now] = 1;
            for (auto [to, e] : G[now]) {
                if (vis[to])
                    continue;
                double tentative_g = g[now];
                if (time)
                    tentative_g += E[e].reallength;
                else
                    tentative_g += E[e].length;
                if (tentative_g < g[to]) {
                    fa[to] = e;
                    g[to] = tentative_g;
                    f[to] = tentative_g + heuristic(to, end, Gp);
                    hp.push({ f[to], {to, e} });
                }
            }
        }
        return path;
    }


    void dfsshow()
    {
        dfsvis.resize(PointNums + 1, 0);
        dfshp(1, 0);
    }
};
