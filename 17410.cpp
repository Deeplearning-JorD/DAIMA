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
    string a, b;
    cin >> a >> b;
    if(a.back() == b.back()){
        if(a.size() == b.size()){
            cout << "=\n";
        }else if(a.size() > b.size()){
            if(a.back() == 'S'){
                cout << "<\n";
            }else cout << ">\n";
        }else{
            if(a.back() == 'S'){
                cout << ">\n";
            }else cout << "<\n";
        }
        return;
    }
    if(a.back() == 'S'){
        cout << "<\n";
        return;
    }
    if(a.back() == 'L'){
        cout << ">\n";
        return;
    }
    if(a.back() == 'M'){
        if(b.back() == 'L') cout << "<\n";
        else if(b.back() == 'S') cout << ">\n";
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