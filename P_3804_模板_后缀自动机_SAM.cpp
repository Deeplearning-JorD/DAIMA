/*
 * @Author: JorD
 * @Date: 2023-12-09 00:47:36
 * @LastEditTime: 2023-12-09 10:26:20
 * how to Get
 */
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int tot=1,las=1;
struct NODE
{
    int ch[26];
    int len,fa;
    NODE(){memset(ch,0,sizeof(ch));len=fa=0;}
}dian[20010];
struct Edge
{
    int t,nexty;
}edge[20010];
int head[20010],cnt=0;
char s[20010];
void jia(int a,int b)
{
    // cout << a << ' ' << b << endl;
    cnt++;
    edge[cnt].t=b;
    edge[cnt].nexty=head[a];
    head[a]=cnt;
}
long long zhi[2000010];
vector<int> ls;
inline void add(int c)
{
     int p=las,np=las=++tot;zhi[tot]=1;
     ls.push_back(tot);
    dian[np].len=dian[p].len+1;
    for(;p&&!dian[p].ch[c];p=dian[p].fa)dian[p].ch[c]=np;
    if(!p)dian[np].fa=1;
    else
    {
         int q=dian[p].ch[c];
        if(dian[q].len==dian[p].len+1)dian[np].fa=q;
        else
        {
             int nq=++tot;
            dian[nq]=dian[q];dian[nq].len=dian[p].len+1;
            dian[q].fa=dian[np].fa=nq;
            for(;p&&dian[p].ch[c]==q;p=dian[p].fa)dian[p].ch[c]=nq;
        }
    }
    // cout << tot << ' ' << dian[np].fa << ' ';
    // for(int i = 0;i < 26;i ++)if(dian[tot-1].ch[i])cout << tot - 1 << ' ' << dian[tot-1].ch[i] << ' ';
    cout << endl;
}
int cd;
long long ans=0;
vector<char> sf;
void dfs(int now){
    for(auto x:sf)cout<<x;
    cout << endl;
    for(int i = 0;i < 26;i ++)if(dian[now].ch[i]){
        sf.push_back((char)(i + 'a'));
        dfs(dian[now].ch[i]);
        sf.pop_back();
    }

}
// void dfs(int node)
// {
//     bool yezi = true;
//     sf.push_back(s[head[node]-1]);
//     for( int i=head[node];i;i=edge[i].nexty)
//     {
//         // cout << i << ' ' << edge[i].t << endl;
//         yezi=false;
//         // sf.push_back(s[i-1]);
//         // cout << s[i-1] << ' ' << s[edge[i].t-1] << endl;
//         dfs(edge[i].t);
//         // sf.pop_back();
//         zhi[node]+=zhi[edge[i].t];
//     }
//     // if(yezi){
//     //     for(auto x:sf)cout<<x;
//     //     cout<<endl;
//     // }
//     sf.pop_back();
//     if(zhi[node]!=1)ans=max(ans,zhi[node]*dian[node].len);
// }
int main()
{
    scanf("%s",s);cd=strlen(s);
    for( int i=0;i<cd;i++)add(s[i]-'a');
    for( int i=2;i<=tot;i++)jia(dian[i].fa,i);
    for(auto x:ls){cout<<x<<":"<<endl; for(int i = 0;i < 26;i ++)if(dian[x].ch[i])cout << x << ' ' << dian[x].ch[i] << ' ';cout<<endl;}
    dfs(1);
    printf("%lld\n",ans);
    return 0;
}