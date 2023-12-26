/*
 * @Author: JorD
 * @LastEditTime: 2022-08-14 13:25:02
 */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using db = double;
#define endl '\n'
#define str string
#define PII pair<ll, ll>
#define fir first
#define sec second
#define siz(s) (ll)(s.size())
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N=1e5+10;
vector<int> son[N];
int depth[N];
int dist[N];
int f[N][30];
void dfs(int now,int fa){
    depth[now]=depth[fa]+1;
    f[now][0]=fa;
    for(int i=1;i<=20;i++){
        f[now][i]=f[f[now][i-1]][i-1];
    }
    for(auto x:son[now]){
        if(x==fa) continue;
        dfs(x,now);
    }
}
int lca(int a,int b){
    if(depth[a]<depth[b]) swap(a,b);
    for(int i=20;i>=0;i--){
        if(depth[f[a][i]]>=depth[b])
            a=f[a][i];
    }
    if(a==b) return a;
    for(int i=20;i>=0;i--){
        if(f[a][i]==f[b][i]) continue;
        a=f[a][i];
        b=f[b][i];
    }
    return f[a][0];
}
void add(int a,int b){
    dist[a]++;
    dist[b]++;
    int p=lca(a,b);
    dist[p]--;
    dist[f[p][0]]--;
}
void find(int now,int fa){
    for(auto x:son[now]){
        if(x==fa) continue;
        find(x,now);
        dist[now]+=dist[x];
    }
}
void Solve(){
    int n,q;
    cin>>n>>q;
    rep(i,2,n){
        int fa; cin>>fa;
        son[fa].push_back(i);
    }
    dfs(1,0);
    while(q--){
        int A,B;
        cin>>A>>B;
        int last;
        cin>>last;
        vector<int> a(A+1);
        a[1]=last;
        rep(i,2,A){
            int now;
            cin>>now;
            last=lca(last,now);
            a[i]=now;
        }
        bool ff=false;
        rep(i,1,A) if(a[i]==last) ff=true;
        bool st=false;
        rep(i,1,B){
            int now;
            cin>>now;
            if(ff){
                if(depth[now]>=depth[last]||st) continue;
                if(lca(last,now)==now) st=true;
            }else{
                if(depth[now]>depth[last]||st) continue;
                if(lca(last,now)==now) st=true;
            }
        }
        if(st) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}