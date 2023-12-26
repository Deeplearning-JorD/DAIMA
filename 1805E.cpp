/*
 * @Author: JorD
 * @LastEditTime: 2023-04-09 01:44:49
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define PII pair<ll, ll>
#define siz(s) (ll)(s.size())
#define all(a) a.begin(), a.end()
#define all1(a) a.begin() + 1, a.end()
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N = 4e5 + 10;
set<pair<int,int>> son[N];
int siz[N], zson[N], idd[N];
void zdfs(int now, int fa){
    siz[now] = 1;
    for(auto [x, w]:son[now])if(x != fa){
        idd[x] = w;
        zdfs(x, now);
        siz[now] += siz[x];
        if(siz[x] > siz[zson[now]]) zson[now] = x;
    }
}
int n;
int st[N], stt[N];
priority_queue<int> q, qq;
void add(int x){
    stt[x] ++;
    st[x] --;
    if(stt[x] == 2) qq.push(x);
    while(st[q.top()] < 2) q.pop();
}
void del(int x){
    stt[x] --;
    st[x] ++;
    if(st[x] == 2) q.push(x);
    while(stt[qq.top()] < 2) qq.pop();
}
int res[N], id[N], a[N];
// 加入一整棵树
void add(int now, int fa){
    add(id[now]);
    for(auto [x, now]:son[now])if(x != fa){
        add(x, now);
    }
}
// 删一整棵树
void del(int now, int fa){
    del(id[now]);
    for(auto [x, now]:son[now])if(x != fa){
        del(x, now);
    }
}
void dfs(int now, int fa, bool ddl){
    for(auto [x, id]:son[now])if(x != fa && x != zson[now]){
        dfs(x, now, 1);
    }
    if(zson[now]){
        dfs(zson[now], now, 0);
    }
    add(id[now]);
    for(auto [x, w]:son[now])if(x != fa && x != zson[now]){
        add(x, now);
    }
    res[idd[now]] = a[max(q.top(), qq.top())];
    if(ddl){
        del(now, fa);
    }
    return;
}
void Solve(){
    scanf("%d",&n); 
    rep(i, 2, n){
        int x, y;
        scanf("%d%d",&x,&y);
        son[x].insert({y, i - 1});
        son[y].insert({x, i - 1});
    }
    rep(i, 1, n){
        scanf("%d", &id[i]);
        a[i] = i;
    }
    sort(a + 1, a + 1 + n, [&](int x, int y){
        return id[x] < id[y];
    });
    int prev=0,preid=0,len = 0;
    for(int i=1;i<=n;i++) {
        int x;
        if(prev==id[a[i]]) {
            id[a[i]]=preid;
        }else {
            prev=x=id[a[i]];
            id[a[i]]=++preid;
            a[preid]=x;
        }
    }   
    len = preid;
    st[0] = stt[0] = 2;
    q.push(0);
    qq.push(0);
    for(int i = 1;i <= n;i ++){
        if((++st[id[i]]) == 2) q.push(id[i]);
    }
    zdfs(1, 0);
    dfs(1, 0, 0);
    rep(i, 1, n - 1) printf("%d\n",res[i]);
    return;
}
int main(){
    Solve();
    return 0;
}