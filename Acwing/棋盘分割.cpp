/*
 * @Author: JorD
 * @LastEditTime: 2022-07-30 18:01:31
 */
#include <bits/stdc++.h>
using namespace std;
#define SPO(n) fixed << setprecision(n)
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
const int N=20;
const double INF=1e9;
double f[N][N][N][N][N];
int pre[N][N];
double X;
int n;
double query(int x,int y,int sx,int sy){
    double now=pre[sx][sy]-pre[x-1][sy]-pre[sx][y-1]+pre[x-1][y-1];
    return now*now;
}
double dp(int x,int y,int sx,int sy,int k){
    double &now=f[x][y][sx][sy][k];
    if(now>=0) return now;
    if(k==1) return query(x,y,sx,sy);
    now=INF;
    rep(i,x,sx-1){
        now=min(now,dp(x,y,i,sy,k-1)+query(i+1,y,sx,sy));
        now=min(now,dp(i+1,y,sx,sy,k-1)+query(x,y,i,sy));
    }
    rep(i,y,sy-1){
        now=min(now,dp(x,y,sx,i,k-1)+query(x,i+1,sx,sy));
        now=min(now,dp(x,i+1,sx,sy,k-1)+query(x,y,sx,i));
    }
    return now;     
}
void Solve(){
    cin>>n;
    rep(i,1,8)
        rep(j,1,8){
            cin>>pre[i][j];
            pre[i][j]+=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    memset(f,-1,sizeof f);
    cout<<dp(1,1,8,8,n);
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}