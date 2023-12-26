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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
struct node{
    int a, b, i;
    bool operator <(const node &ji)const{
        return a < ji.a;
    }
};
struct node1{
    int a, b, i;
    bool operator <(const node1 &ji)const{
        return b < ji.b;
    }
};
void Solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> a(n + 1);
    rep(i, 1, n) cin >> a[i].first >> a[i].second;
    priority_queue<node> q;
    priority_queue<node1> qq;
    vector<bool> st(n + 1);
    rep(i, 1, n){
        auto [x, y] = a[i];
        q.push((node){x, y, i});
        qq.push((node1){x, y, i});
    }
    int L = 0, R = 0;
    rep(o, 1, n){
        if(o & 1){
            int j, jj;
            while(q.size()){
                auto [x, y, i] = q.top();
                if(st[i]){
                    q.pop();
                    continue;
                }
                j = i;
                // L += x;
                // st[i] = 1;
                break;
            }
            while(qq.size()){
                auto [x, y, i] = qq.top();
                if(st[i]){
                    qq.pop();
                    continue;
                }
                jj = i;
                // R += y;
                // st[i] = 1;
                break;
            }
            if(a[j].first < a[jj].second){
                st[jj] = 1;
                L += a[jj].first;
            }else{
                st[j] = 1;
                L += a[j].first;
            }
        }else{
            int j, jj;
            while(q.size()){
                auto [x, y, i] = q.top();
                if(st[i]){
                    q.pop();
                    continue;
                }
                j = i;
                // L += x;
                // st[i] = 1;
                break;
            }
            while(qq.size()){
                auto [x, y, i] = qq.top(); 
                if(st[i]){
                    qq.pop();
                    continue;
                }
                jj = i;
                // R += y;
                // st[i] = 1;
                break;
            }
            if(a[j].first > a[jj].second){
                st[j] = 1;
                R += a[j].second;
            }else{
                st[jj] = 1;
                R += a[jj].second;
            }
        }
    }
    cout << L - R << endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t; while(t --)
    Solve();
    return 0;
}