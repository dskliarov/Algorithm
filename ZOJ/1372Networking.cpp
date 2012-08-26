/**
 * ZOJ 1372 Networking
 */

#include <iostream>
#include <cstdio>
using namespace std;

//无向图最小生成树,prim算法,邻接阵形式,复杂度O(n^2)
//返回最小生成树的长度,传入图的大小n和邻接阵mat,不相邻点边权inf
//可更改边权的类型,pre[]返回树的构造,用父结点表示,根节点(第一个)pre值为-1
//必须保证图的连通的!
#define MAXN 50
#define inf 1000000
typedef int elem_t;

elem_t prim(int n,elem_t mat[][MAXN],int* pre)
{
	elem_t min[MAXN],ret=0;
	int v[MAXN],i,j,k;
	for (i=0;i<n;i++)
		min[i]=inf,v[i]=0,pre[i]=-1;
	for (min[j=0]=0;j<n;j++){
		for (k=-1,i=0;i<n;i++)
			if (!v[i]&&(k==-1||min[i]<min[k]))
				k=i;
		for (v[k]=1,ret+=min[k],i=0;i<n;i++)
			if (!v[i]&&mat[k][i]<min[i])
				min[i]=mat[pre[i]=k][i];
	}
	return ret;
}

int p, r, ret;
int dis[MAXN][MAXN];
int pre[MAXN];

int Run() {
	cin >> r;
	for (int i = 0; i < p; ++i) {
		for (int j = 0; j < p; ++j) {
			dis[i][j] = inf;
		}
	}
	while (r--) {
		int a, b, len;
		cin >> a >> b >> len;
		--a, --b;
		if (len < dis[a][b]) {
			dis[a][b] = dis[b][a] = len;
		}
	}
	ret = prim(p, dis, pre);
	cout << ret << endl;
	return 0;
}

int main() {
	while (cin >> p && p) {
		Run();
	}
	return 0;
}
