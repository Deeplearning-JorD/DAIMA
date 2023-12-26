/*
 * @author:  Snow
 * @Description:  Algorithm Contest
 * @LastEditTime: 2022-07-25 19:56:20
 */
#include<bits/stdc++.h>
using namespace std;
#define int long long 
#pragma GCC optimize(3)
typedef pair<int,int>PII;
#define pb emplace_back
#define debug(a) cout<<a<<' ';
#define fer(i,a,b) for(re i=a;i<=b;i++)
#define der(i,a,b) for(re i=a;i>=b;i--)
int n,k;
int ans;
const int N = 1e5+10;
const int M = 4e5+10;
int a[N];
int tr1[N];
int tr2[N];
int h1[N],h2[N],e[M],ne[M],idx;
int deep1[N],dfn1[N],f1[N][25];
int deep2[N],dfn2[N],f2[N][25];
int sjc1[N],sjc2[N];
int timestamp;
int big1,big2,big3,big4;
int sma1,sma2,sma3,sma4;
void add(int h[],int a,int b){
    e[idx]=b;
    ne[idx]=h[a];
    h[a]=idx++;
}
void dfs1(int u,int fa){
    deep1[u]=deep1[fa]+1;
    f1[u][0]=fa;dfn1[u]=++timestamp;
    sjc1[timestamp]=u;
    for(int k=1;k<=20;k++)f1[u][k]=f1[f1[u][k-1]][k-1];
    for(int i=h1[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        dfs1(j,u);
    }
}
void dfs2(int u,int fa){
    deep2[u]=deep2[fa]+1;
    f2[u][0]=fa;dfn2[u]=++timestamp;
    sjc2[timestamp]=u;
    for(int k=1;k<=20;k++)f2[u][k]=f2[f2[u][k-1]][k-1];
    for(int i=h2[u];i!=-1;i=ne[i]){
        int j=e[i];
        if(j==fa)continue;
        dfs2(j,u);
    }
}
int lca1(int u,int v){///求lca
    if(deep1[u]<deep1[v])swap(u,v);
    for(int k=20;k>=0;k--)if(deep1[v]<=deep1[f1[u][k]])u=f1[u][k];
    if(u==v) return u;
    for(int k=20;k>=0;k--){
        if(f1[u][k]!=f1[v][k]){
            u=f1[u][k];
            v=f1[v][k];
        }
    }
    return f1[u][0];
}
int lca2(int u,int v){///求lca
    if(deep2[u]<deep2[v])swap(u,v);
    for(int k=20;k>=0;k--)if(deep2[v]<=deep2[f2[u][k]])u=f2[u][k];
    if(u==v) return u;
    for(int k=20;k>=0;k--){
        if(f2[u][k]!=f2[v][k]){
            u=f2[u][k];
            v=f2[v][k];
        }
    }
    return f2[u][0];
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    memset(h1,-1,sizeof h1);
    memset(h2,-1,sizeof h2);
    cin>>n>>k;
    for(int i=1;i<=k;i++)cin>>a[i];
    for(int i=1;i<=n;i++)cin>>tr1[i];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        add(h1,i,x);
        add(h1,x,i);
    }
    for(int i=1;i<=n;i++)cin>>tr2[i];
    for(int i=2;i<=n;i++){
        int x;
        cin>>x;
        add(h2,i,x);
        add(h2,x,i);
    }
    dfs1(1,1);
    // for(int i=1;i<=n;i++)cout<<dfn1[i]<<' ';
    // cout<<endl;
    timestamp=0;
    dfs2(1,1);
    // for(int i=1;i<=n;i++)cout<<dfn2[i]<<' ';
    // cout<<endl;
    big1=big2=big3=big4=-2e18;
    sma1=sma2=sma3=sma4=2e18;
    for(int i=1;i<=k;i++){
        int id=a[i];
        if(dfn1[id]>big1){
            big2=big1;
            big1=dfn1[id];
        }
        else if(dfn1[id]>big2){
            big2=dfn1[id];
        }
        if(dfn1[id]<sma1){
            sma2=sma1;
            sma1=dfn1[id];
        }
        else if(dfn1[id]<sma2){
            sma2=dfn1[id];
        }
    }
    for(int i=1;i<=k;i++){
        int id=a[i];
        if(dfn2[id]>big3){
            big4=big3;
            big3=dfn2[id];
        }
        else if(dfn2[id]>big4){
            big4=dfn2[id];
        }
        if(dfn2[id]<sma3){
            sma4=sma1;
            sma3=dfn2[id];
        }
        else if(dfn2[id]<sma4){
            sma4=dfn2[id];
        }
    }
    for(int i=1;i<=k;i++){
        int del=a[i];
        int id1,id2,id3,id4;
        if(big1==dfn1[del])id1=big2;
        else id1=big1;
        if(sma1==dfn1[del])id2=sma2;
        else id2=sma1;
        if(big1==dfn2[del])id3=big2;
        else id3=big1;
        if(sma1==dfn2[del])id4=sma2;
        else id4=sma1;
        // cout<<id1<<' '<<id2<<endl;
        int lcao=lca1(sjc1[id1],sjc1[id2]);
        int lcas=lca2(sjc2[id3],sjc2[id4]);
        if(tr1[lcao]>tr2[lcas])ans++;
    }
    cout<<ans<<endl;
    return 0;
}