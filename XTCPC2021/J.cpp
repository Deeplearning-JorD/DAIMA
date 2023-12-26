/*
 * @Author: JorD
 * @LastEditTime: 2023-04-12 20:29:20
 */
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;
#define int long long 
const int N = 1e5+10;
int top[N];
int down[N];
int stk[N];
int sz[N];
int n,m;
int num[N];
vector<int>v[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(cin>>n>>m){
        for(int i=1;i<=n;i++){
            sz[i]=1;
            stk[i]=i;
            top[i]=i;
            down[i]=i;
            num[i]=i;
            v[i].clear();
        }
        while(m--){
            int a,b;
            cin>>a>>b;
            if(sz[a]==1&&sz[b]==1){
                sz[a]=0;
                sz[b]=2;
                top[b]=num[a];
                down[b]=num[b];
                v[num[a]].push_back(num[b]);
                v[num[b]].push_back(num[a]);
            }
            else if(sz[a]==0)continue;
            else if(sz[b]==0){
                if(sz[a]==1){
                    sz[b]=sz[a];
                    sz[a]=0;
                    top[b]=down[a];
                    down[b]=top[a];
                    num[b]=num[a];
                    continue;
                }
                sz[b]=sz[a];
                sz[a]=0;
                top[b]=down[a];
                down[b]=top[a];
            }else{
                sz[b]+=sz[a];
                sz[a]=0;
                v[top[a]].push_back(top[b]);
                v[top[b]].push_back(top[a]);
                top[b]=down[a];
            }
        }
        for(int i=1;i<=n;i++){
            if(sz[i]==0){
                cout<<0<<'\n';
                continue;
            }else{
                int x=top[i];
                int ti=sz[i];
                cout<<sz[i]<<' ';
                int last=-1;
                while(ti--){
                    if(ti==0)
                        cout<<x;
                    else cout<<x<<' ';
                    int y;
                    for(int u:v[x]){
                        if(u!=last){
                            y=u;
                            break;
                        }
                    }
                    last=x;
                    x=y;
                }
                cout<<'\n';
            }
        }
    }
    return 0;
}