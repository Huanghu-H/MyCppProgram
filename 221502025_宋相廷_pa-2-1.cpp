#include<bits/stdc++.h>
using namespace std;
#define MAX 1000000 
vector<int> mp[MAX]; 
int dp1[MAX];
int dp2[MAX];
int w[MAX];
void dfs(int idx, int father)
{

	dp1[idx] = w[idx];
    dp2[idx] = 0; 
    for (int i = 0; i < mp[idx].size(); i++)  
    {
        int next_idx = mp[idx][i];
        if (next_idx == father)
            continue;  
        dfs(next_idx, idx); 
        dp1[idx] += dp2[next_idx]; 
        dp2[idx] += max(dp1[next_idx], dp2[next_idx]);
        //cout<<dp1[idx]<<" "<<dp2[idx]<<endl; 
    }
}

int main()
{
    int n;
    cin >> n ;

    for (int i = 1; i <= n; i++)
    {
        int p1, weight;
        cin >> p1 >> weight;
        mp[p1].push_back(i);
        mp[i].push_back(p1);
        w[i]=weight;
    }

    dfs(1, -1);
    cout << max(dp1[1],dp2[1]) << endl; 
	
}
/*
11
0 15
1 8
1 16
1 18
2 3
2 5
2 5
3 7
4 2
4 9
6 4
*/
