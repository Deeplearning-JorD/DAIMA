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
void Solve(){
    int n, k;
    cin >> n >> k;
    int mx = 0;
    deque<pair<int,int>> q;
    rep(i, 1, n){
        int x; cin >> x;
        mx = max(x, mx);
        q.push_back({x, i});
    }
    vector<int> win(n + 1);
    while(q.size()){
        auto [a1, id1] = q.front();
        q.pop_front();
        auto [a2, id2] = q.front();
        q.pop_front();
        if(a1 >= a2){
            win[id1] ++;
            win[id2] = 0;
            q.push_back({a2, id2});
            q.push_front({a1, id1});
            if(win[id1] == k){
                cout << id1 << endl;
                break;
            }
        }else{
            win[id2] ++;
            win[id1] = 0;
            q.push_back({a1, id1});
            q.push_front({a2, id2});
            if(win[id2] == k){
                cout << id2 << endl;
                break;
            }
        }
        if(a1 == mx){
            cout << id1 << endl;
            break;
        }
        if(a2 == mx){
            cout << id2 << endl;
            break;
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