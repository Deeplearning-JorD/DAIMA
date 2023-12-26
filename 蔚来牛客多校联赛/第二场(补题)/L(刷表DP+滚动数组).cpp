/*
 * @Author: JorD
 * @LastEditTime: 2022-07-28 15:18:50
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
#define priq priority_queue
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
const int N=2e4,INF=0x3f3f3f3f;
int n,m;
int f[2][N];
void Solve(){
    cin>>n>>m;
    memset(f,0x3f,sizeof f);
    int res=INF;
    //f[i][j]表示这一层打达j的最小世界层数
    //只有两种转移方程
    //第一种是站着不动掉到下一层去f[(i+1)&1][j]=f[i&1][j]+1;
    //第二种是走一步到下一层f[(i+1)&1][v]=f[i&1][u]。存在u->v这条边
    //特别的,对于每一层,我们都可以选择从这一层的1开始,而从1开始又可以更新所有1->v的边为1
    rep(i,1,n){
        int l;
        cin>>l;
        rep(j,1,m)
            f[(i+1)&1][j]=f[i&1][j]+1;
        rep(j,1,l){
            int u,v;
            cin>>u>>v;
            f[(i+1)&1][v]=min(f[(i+1)&1][v],f[i&1][u]+1);
            if(u==1)
                f[(i+1)&1][v]=min(f[(i+1)&1][v],1);
        }
        f[(i+1&1)][1]=1;
        res=min(f[(i+1)&1][m],res);
    }
    if(res==INF) cout<<-1;
    else cout<<res;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;

    
    Solve();
    return 0;
}