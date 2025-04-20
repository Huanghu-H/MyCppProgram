#include <bits/stdc++.h>

#define debug(a) cout << "debug : " << (#a)<< " = " << a << endl

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
const int N = 1e4 + 10;
const int P = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n,m,root;//n�����m������ߣ���rootΪ����
int u,v,w;
int g[N][N],inCost[N],pre[N];//inCost[u]�洢u����С��߻��ѡ�pre[u]�洢u��ǰ����㡣
int id[N],vis[N];//id[u]��ʾu���±�ŵĵ㣬���������Ϊ�˴������򻷵ġ�vis[u]��ʾu��ͨ��vis[u]�����ʵġ�
struct node{
    int u,v,w;
}edges[N];
int zhuliu(){
    int res = 0;//resͳ�Ʊ�Ȩ�͡�
    while(true){
        for(int i = 1; i <= n; ++ i)inCost[i] = INF, id[i] = vis[i] = -1;//��ʼ��������ĵȡ�
        for(int i = 0; i < m; ++ i){
            u = edges[i].u, v = edges[i].v, w = edges[i].w;
            if(u != v && w < inCost[v]){
                inCost[v] = w;
                pre[v] = u;
            }
        }
        for(int i = 1; i <= n; ++ i){
            if(i != root && inCost[i] == INF){
                //˵����������ߣ��޷���������ͼ��
                return -1;
            }
        }
        inCost[root] = 0;
        int tn = 0;//�µı�š�
        for(int i = 1; i <= n; ++ i){
            res += inCost[i];//ͳ��������ġ�
            v = i;
            while(vis[v] != i && id[v] == -1 && v != root){
                vis[v] = i;
                v = pre[v];//���ϵ���ǰ����㣬֪�����µ�����㡣���ǻ���������vis[v] = iʱ�����˳������ص���㡣
            }
            if(v != root && id[v] == -1){
                //˵��������rootΪ����㡣������������
                id[v] = ++tn;
                for(u = pre[v]; u != v; u = pre[u])id[u] = tn;//���¸����򻷱�ţ�����֮�����㡣
            }
        }
        if(tn == 0)break;//˵��û�����±�ţ������������򻷡�
        for(int i = 1; i <= n; ++ i){
            if(id[i] == -1){
                id[i] = ++tn;//��δ���±�ŵ�Ҳ���±�ţ����ڴ���
            }
        }
        int i = 0;
        while(i < m){
            int vv = edges[i].v;//������߻�������ԭ���ı�ţ���������ȡ������յ㡣
            //��ȡ���µı�š�
            edges[i].u = id[edges[i].u], edges[i].v = id[edges[i].v];
            if(edges[i].u != edges[i].v){
                //���￴���ǻ���һ���뻷�ڵ�v�㣬����������Ҫ��ȥ�������Ȩ��
                //�������Ա����ظ����㡣
                edges[i ++].w -= inCost[vv];//����Ȩֵ����Ϊ����Ѿ����ۼ��ˡ�
            }
            else{
                //�����򻷻����׳���
                swap(edges[i],edges[-- m]);
            }
        }
        n = tn;//�����µĽ��������
        root = id[root];//���¸�����š�
    }
    return res;
}
void solve(){
    printf("%d\n", zhuliu());
}
int main(){	
	root=1;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++ i)for(int j = 1; j <= n; ++ j)g[i][j] = INF;
    for(int i = 0; i < m; ++ i){
        scanf("%d%d%d", &u, &v, &w);
        //ȥ���Ի���
        if(u == v)continue;
        //ȥ���رߡ�
        g[u][v] = min(g[u][v],w);
    }
    m = 0;
    for(int i = 1; i <= n; ++ i){
        for(int j = 1; j <= n; ++ j){
            //���ߴ洢������
            if(g[i][j] != INF){
                edges[m].u = i,edges[m].v = j,edges[m ++].w = g[i][j];
            }
        }
    }
    solve();
    return 0;
}

