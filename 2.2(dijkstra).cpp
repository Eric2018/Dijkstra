#include <iostream>
#include <cstdio>
#include <string.h>
#include <cstdio>

#define min(x,y) x<y?x:y
#define MaxN 1000
#define INF 9999999

using namespace std;

int dis[MaxN],g[MaxN][MaxN],vexnum,arcnum,v1,v2,w;  //dis[]:dp动态数组 保存各点距1点的最短路径
bool v[MaxN];

void Dijkstra() {
    for(int i=1; i<=vexnum; ++i) dis[i]=INF;
    dis[1]=0;
    memset(v,0,sizeof(v));
    for(int i=1; i<=vexnum; i++) {
        int mark=-1,mindis=INF;
        for(int j=1; j<=vexnum; j++)
            if(!v[j] && dis[j]<mindis) {
                mindis=dis[j];              //mindis保存最近距离
                mark=j;             //找到从当前点出发最近可到的点
            }
        v[mark]=1;          //找到的这一点可以确定已找到最短路径，标为已走过
        for(int j=1; j<=vexnum; j++)
            if(!v[j])
                dis[j]=min(dis[j],dis[mark]+g[mark][j]);  //从找到的点出发，刷新其他点到该点最近距离，取本身和1点到当前点加上目标点的距离较小值
    }
}

int main() {
    cin>>vexnum>>arcnum;        //vexnum:顶点总个数  arcnum:路径总数
    for(int i=1; i<=vexnum; i++)
        for(int j=1; j<=vexnum; j++)
            g[i][j]=INF;
    for(int i=1; i<=arcnum; i++) {     //用邻接矩阵保存地图!
        cin>>v1>>v2>>w;
        g[v1][v2]=w;
        g[v2][v1]=w;
    }
    Dijkstra();
    for(int i=1; i<=vexnum; i++)
        cout<<i<<" "<<dis[i]<<endl;
    return 0;
}

