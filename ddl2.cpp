/*
 * @Author: JorD
 * @LastEditTime: 2022-10-04 20:35:16
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
vector<int> son[N];
bool st[N];
int res[N], siz[N];
int w[N], mi[N];
int n;
void dfs(int now, int fa){
    siz[now] = 1;
    mi[now] = now;
    for(auto x:son[now]){
        if(x == fa) continue;
        dfs(x, now);
        siz[now] += siz[x];
        mi[now] = min(mi[now], mi[x]);
    }
    if(now==mi[now])res[now] = n - siz[now];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    memset(mi, 0x3f, sizeof mi);
    for(int i = 1; i <= n;i ++) cin >> w[i];
    for(int i = 2; i <= n;i ++){
        int x;
        cin >> x;
        son[w[x]].push_back(w[i]);
        son[w[i]].push_back(w[x]);
    }
    dfs(0, -1);
    for(auto x:son[0]){
        res[0]=max(res[0],siz[x]);
    }
    for(int i = 0;i < n;i ++) cout << res[i] << ' ';
    cout << n << endl;
} 