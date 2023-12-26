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
#define rep(i, l, r) for (ll(i) = (l); (i) <= (r); ++(i))
#define per(i, r, l) for (ll(i) = (r); (i) >= (l); --(i))
#define DBG(n) cout<<"!!! "<<#n<<": "<<n<<'\n'
void Solve(){
    int n, m;
    cin >> n >> m;
    vector<string> s;
    map<string,string> pre;
    rep(i, 1, n){
        string c;
        cin >> c;
        s.push_back(c);
    }
    map<string,bool> st;
    string now, ed;
    cin >> now >> ed;
    if(now == ed){
        cout << 0 << endl;
        cout << now << endl;
        cout << ed << endl;
        return;
    }
    s.push_back(ed);
    string edd=ed;
    queue<string> q;
    q.push(now);
    st[now] = true;
    while(!q.empty()){
        auto t = q.front(); q.pop();
        if(t == ed) break;
        for(auto x:s){
            if(st[x]) continue;
            int js=0;
            for(int i=0;i<m;i++){
                if(x[i]!=t[i]) js++;
            }
            if(js>1) continue;
            pre[x]=t;
            st[x] = true;
            q.push(x);
        }
    }
    if(!st[ed]){
        cout << -1 << endl;
        return;
    }
    vector<string> res;
    while(ed!=now){
        ed = pre[ed];
        // cout<<ed<<' ';
        res.push_back(ed);
    }
    int ji =(int)res.size()-1;
    cout << ji << endl;
    reverse(res.begin(), res.end());
    for(auto x:res) cout << x << endl;
    cout<<edd<<endl;
    return;
}
int main(){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    //int t; cin>>t;
    Solve();
    return 0;
}