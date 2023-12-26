/*
 * @Author: JorD
 * @LastEditTime: 2022-07-27 15:02:43
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
const int N=5e5+10;
ll a[5][N];
bool st[5][N];
ll dist[5][N];
void bfs(int be,int ne,int ed,int ee){
    deque<pair<int,int>>  q;
    q.push_back({ne,be});
    memset(dist,0x3f,sizeof dist);
    dist[ne][be]=0;
    while(q.size()){
        auto t=q.front(); q.pop_front();
        if(t.second==ed&&a[t.first][t.second]==ee){
            cout<<dist[t.first][t.second];
            return;
        }
        int now=t.second,nex=t.first,p=a[nex][now];
        if(st[nex][now]) continue;
        st[nex][now]=true;
        int oo;
        for(int i=1;i<=4;i++) if(a[i][p]==now) oo=i;
        for(int i=1;i<=4;i++){
            if(!a[i][p]) continue;
            if(dist[i][p]<=dist[nex][now]) continue;
            if((oo%4+1)==i){
                dist[i][p]=dist[nex][now];
                q.push_front({i,p});
            }else{
                dist[i][p]=dist[nex][now]+1;
                q.push_back({i,p});
            }
        }
    }
    cout<<-1;
}
void Solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=4;j++)
            cin>>a[j][i];
    }
    int sx,sy,ex,ey;
    cin>>sx>>sy>>ex>>ey;
    for(int i=1;i<=4;i++){
        if(a[i][sx]==sy){
            bfs(sx,i,ex,ey);
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    Solve();
    return 0;
}