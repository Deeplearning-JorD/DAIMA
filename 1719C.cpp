/*
 * @Author: JorD
 * @LastEditTime: 2022-08-17 13:48:33
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
#define rep(i, l, r) for (int(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    int ji;
    deque<pair<int,int>> q;
    rep(i, 1, n){
        int x; cin >> x;
        q.push_back({x,i});
        if(x == n){ ji = i;}
    }   
    pair<int,int> zero = {0,0};
    vector<pair<int,int>> win(n+1,zero);
    int dist = 0;
    while(!q.empty()){
        auto t = q.front(); q.pop_front();
        if(t.first == n) break;
        auto tt = q.front(); q.pop_front();
        dist ++;
        pair<int,int> qq = {dist,dist};
        if(t.first > tt.first){
            if(win[t.second] == zero)
                win[t.second] = qq;
            else win[t.second].second++;
            q.push_front(t);
        }else if(tt.first > t.first){
            if(win[tt.second] == zero)
                win[tt.second] = qq;
            else win[tt.second].second++;
            q.push_front(tt);
        }
    };
    int w = 0;
    if(win[ji]!=zero) w = 1;
    while(m--){
        int id, k; 
        cin >> id >> k;
        if(k >= dist){
            if(id != ji){
                if(win[id].second == 0) cout << 0 << endl;
                else cout << win[id].second - win[id].first + 1 << endl;
            }else cout << k - dist + w << endl;
        }else{
            if(k >= win[id].second){
                if(win[id].second == 0) cout << 0 << endl;
                else cout << win[id].second - win[id].first + 1 << endl;
            }else if(k < win[id].first) cout << 0 << endl;
            else cout << k - win[id].first + 1 << endl;
        }
    }
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int t; cin>>t;
    while(t--)
    Solve();
    return 0;
}