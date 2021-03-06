/*************************************************************************
	> File Name: topo_vector.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月09日 星期二 10时40分24秒
 ************************************************************************/
/*************************************************************************
	> File Name: topo.cpp
	> Author: gpx
	> Mail: 1457495424@qq.com
	> Created Time: 2019年04月09日 星期二 10时19分56秒
 ************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 10000
#define MAX_M 100000

struct Edge {
    int to, next;
} g[MAX_M + 5];
int head[MAX_N + 5], cnt = 0;
int n, m;
int degree[MAX_N + 5];

inline void add(int a, int b) {
    g[++cnt].to = b;
    g[cnt].next = head[a];
    head[a] = cnt;
}

void topo() {
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        if (degree[i]) continue;
        v.push_back(i);
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        int ind = v[i];
        i == 0 || cout << " ";
        cout << ind;
        for (int j = head[ind]; j; j = g[j].next) {
            int to = g[j].to;
            degree[to]--;
            if (degree[to] == 0) {
                v.push_back(to);
            }
        }
        sort(v.begin() + i + 1, v.end());
    }
    cout << endl;
    return ;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        degree[y]++;
    }
    topo();
    return 0;
}
