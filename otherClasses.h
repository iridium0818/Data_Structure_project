#include <vector>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <windows.h>
#include <queue>
#include "BasicStruct.h"

using namespace std;
// KD 树的实现
class KDTree {
private:
    struct Node {
        Point point;
        int id; // 点的编号
        int layer;//点的层数
        Node* left;
        Node* right;
        Node(Point p, int id,int L) : point(p), id(id),layer(L), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* buildTree(vector<pair<Point, int>>& points, int depth) {
        if (points.empty()) return nullptr;

        int axis = depth % 2; // 交替选择 x 轴或 y 轴
        auto cmp = (axis == 0) ? [](pair<Point, int> a, pair<Point, int> b) { return a.first.x < b.first.x; }
                               : [](pair<Point, int> a, pair<Point, int> b) { return a.first.y < b.first.y; };
        sort(points.begin(), points.end(), cmp);

        int mid = points.size() / 2;
        Node* node = new Node(points[mid].first, points[mid].second,depth); //depth从0开始
        vector<pair<Point, int>> leftPoints(points.begin(), points.begin() + mid);
        vector<pair<Point, int>> rightPoints(points.begin() + mid + 1, points.end());
        node->left = buildTree(leftPoints, depth + 1);
        node->right = buildTree(rightPoints, depth + 1);

        return node;
    }

    // k 邻近搜索   kNearestSearchHelp方便递归
    void kNearestSearch(Node* node, const Point& target, int k, int depth, priority_queue<pair<double, int>>& pq) {
        if (!node) return;

        // 计算当前节点到目标点的距离
        double dist = distance(target, node->point);
        pq.push({dist, node->id});

        // 如果优先队列大小超过 k，移除最远的点
        if (pq.size() > k) {
            pq.pop();
        }

        int axis = depth % 2;
        double diff = (axis == 0) ? (target.x - node->point.x) : (target.y - node->point.y);

        // 递归搜索更近的分支
        if (diff <= 0) {
            kNearestSearch(node->left, target, k, depth + 1, pq);
            if (pq.size() < k || abs(diff) < pq.top().first) {
                kNearestSearch(node->right, target, k, depth + 1, pq);
            }
        } else {
            kNearestSearch(node->right, target, k, depth + 1, pq);
            if (pq.size() < k || abs(diff) < pq.top().first) {
                kNearestSearch(node->left, target, k, depth + 1, pq);
            }
        }
    }

    //层数
    void writeLayerHelp(vector<Point>& points,Node* subroot){
        if(subroot==NULL)return;
        points[subroot->id].Layer=subroot->layer;
        writeLayerHelp(points,subroot->left);
        writeLayerHelp(points,subroot->right);
    }

public:
    KDTree(const vector<Point>& points) {
        vector<pair<Point, int>> indexedPoints;
        for (int i = 0; i < points.size(); ++i) {
            indexedPoints.push_back({points[i], i});
        }
        root = buildTree(indexedPoints, 0);
    }

    //将层数写进点池
    void writeLayer(vector<Point>& points){
        if(root==NULL)return;
        points[root->id].Layer=root->layer;
        writeLayerHelp(points,root->left);
        writeLayerHelp(points,root->right);
    }

    // 查找距离目标点最近的 k 个点
    vector<int> kNearestSearch(const Point& target, int k) {
        priority_queue<pair<double, int>> pq; // 最大堆，存储距离和点编号
        kNearestSearch(root, target, k, 0, pq);
        //将pq里的点的编号写入result
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        reverse(result.begin(), result.end()); // 将结果从近到远排序
        return result;
    }
};


// 并查集（DSU）类
class DSU {
private:
    std::vector<int> parent;
    std::vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n + 1); // 点编号从1开始
        rank.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootX] = rootY;
                if (rank[rootX] == rank[rootY]) {
                    rank[rootY]++;
                }
            }
        }
    }

    bool isConnected(int x, int y) {
        return find(x) == find(y);
    }
};


