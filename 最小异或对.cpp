/*
 * @Author: JorD
 * @LastEditTime: 2023-04-03 23:58:02
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
#define ls tr[p].l
#define rs tr[p].r
const int N = 2e5 + 10;
struct Tree{
    int l, r, sum, cnt, val;
            //答案  个数 单个数
}tr[N * 30];
int idx = 1;
int tot;
void pushup(int p){
    if(!tr[ls].cnt && !tr[rs].cnt){
        if(tr[p].cnt >= 2) tr[p].sum = 0;
        else tr[p].sum = tot;
    }else if(tr[ls].cnt && tr[rs].cnt){
        if(tr[tr[p].l].cnt >= 2 && tr[tr[p].r].cnt >= 2){
            tr[p].sum = min(tr[tr[p].l].sum, tr[tr[p].r].sum);
        }else if(tr[ls].cnt >= 2){
            tr[p].sum = tr[ls].sum;
        }else if(tr[rs].cnt >= 2){
            tr[p].sum = tr[rs].sum;
        }else{
            tr[p].sum = tr[ls].sum ^ tr[rs].sum; 
        }
    }else if(tr[ls].cnt){
        if(tr[tr[p].l].cnt >= 2){
            tr[p].sum = tr[tr[p].l].sum;
        }else{
            tr[p].val = tr[ls].val;
            tr[p].sum = tr[p].val;
        }
    }else{
        if(tr[tr[p].r].cnt >= 2){
            tr[p].sum = tr[tr[p].r].sum;
        }else{
            tr[p].val = tr[rs].val;
            tr[p].sum = tr[p].val;
        }
    }
}
void add(int i, int p, int x){
    if(i < 0){
        tr[p].cnt ++;
        tr[p].val = x;
        tot |= x & (1 << (i + 1));
        pushup(p);
        return;
    }
    int c = x >> i & 1;
    if(!c){
        if(!tr[p].l) tr[p].l = ++ idx;
        add(i - 1, tr[p].l, x);
    }else{
        if(!tr[p].r) tr[p].r = ++ idx;
        add(i - 1, tr[p].r, x);
    }
    tr[p].cnt ++;
    tot |= x & (1 << (i + 1));
    pushup(p);
    return;
}
void del(int i, int p, int x){
    if(i < 0){
        tr[p].cnt --;
        if(tr[p].cnt)
        tot |= x & (1 << (i + 1));
        pushup(p);
        return;
    }
    int c = x >> i & 1;
    if(!c){
        if(!tr[p].l) tr[p].l = ++ idx;
        del(i - 1, tr[p].l, x);
    }else{
        if(!tr[p].r) tr[p].r = ++ idx;
        del(i - 1, tr[p].r, x);
    }
    tr[p].cnt --;
    if(tr[p].cnt)
    tot |= x & (1 << (i + 1));
    pushup(p);
    return;    
}
void Solve(){   
    int m; cin >> m;
    while(m --){
        string s;
        cin >> s;
        if(s == "ADD"){
            int x; cin >> x;
            tot = 0;
            add(30, 1, x);
        }else if(s == "DEL"){
            int x; cin >> x;
            tot = 0;
            del(30, 1, x);
        }else{
            cout << tr[1].sum << endl;
        }
    }

    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t; while(t --)
    Solve();
    return 0;
}