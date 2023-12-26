/*
 * @Author: JorD
 * @LastEditTime: 2022-09-18 10:57:13
 */
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct Node{
    int l, r, ans;
    bool f;
    int L, R;
}tr[N<<2];
int n, q;
int res;
string s;
inline void pushup(Node &fa, Node &sonl, Node &sonr){
    int len = (sonr.R - sonl.L + 1);
    fa.l=sonl.l;
    fa.r=sonr.r;
    fa.ans += sonl.ans+sonr.ans;
    int tag=0;
    if(sonl.f){
        fa.l += sonr.l;
    }else tag++;
    if(sonr.f){
        fa.r += sonl.r;
    }else tag++;
    if(tag == 2)
        fa.ans += sonl.r + sonr.l + 1 >> 1;
    fa.f = fa.l==len;
    fa.L = sonl.L;
    fa.R = sonr.R;
}
inline void pushup(int u){
    pushup(tr[u], tr[u << 1], tr[u << 1|1]);
}
inline void build(int u,int l,int r){
    if(l == r){
        if(s[l] == '1'){
            tr[u]={1,1,0,1,l,r};
        }
        else{
            tr[u]={0,0,0,0,l,r};
        }
        return ;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1|1, mid+1, r);
    pushup(u);
}
inline Node que(int u,int l,int r){
    if(tr[u].L >= l && tr[u].R <= r){
        return tr[u];
    }
    int mid = tr[u].L + tr[u].R >> 1;
    if(r <= mid) return que(u << 1, l, r);
    else if(l > mid) return que(u << 1|1, l, r);
    else{
        Node x = {0, 0, 0, 0, 0, 0};
        auto left = que(u << 1, l, mid);
        auto right = que(u << 1|1, mid + 1, r);
        pushup(x, left, right);
        return x;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> q;
    cin >> s;
    s = " " + s;
    build(1, 1, n);
    while(q -- ){
        int l, r;
        cin >> l >> r;
        Node res = {0, 0, 0, 0, 0, 0};
        res = que(1, l, r);
        cout << max(0, r - l + 1 - (res.ans + (res.l + res.r + 1 >> 1 )) * 3) / 3 << '\n';
    }
}