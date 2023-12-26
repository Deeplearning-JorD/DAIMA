    /*
    * @Author: JorD
 * @LastEditTime: 2023-03-20 20:57:01
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
    const double eps = 1e-15;
    void Solve(){
        ll n, m, k;
        cin >> n >> m >> k;
        vector<pair<double,double>> a(n + 1);
        vector<pair<double,double>> b(m + 1);
        rep(i, 1, n) cin >> a[i].first >> a[i].second;
        rep(i, 1, m) cin >> b[i].first >> b[i].second;
        auto check = [&](double mid){
            vector<double> now(m + 1);
            for(int i = 1;i <= m;i ++) now[i] = b[i].first - b[i].first * mid - b[i].second * mid;
            sort(now.begin() + 1, now.end());
            ll res = 0;
            rep(i, 1, n){
                double x = a[i].first * mid + a[i].second * mid - a[i].first;
                res += lower_bound(now.begin() + 1, now.end(), x) - now.begin() - 1;
            }
            return res > n * m - k;
        };  
        double l = 0, r = 1;
        while(fabs(r - l) > eps){
            double mid = (l + r) / 2;
            if(check(mid)) r = mid;
            else l = mid;
        }
        cout << SPO(15) << l * 100 << endl;
        return;
    }
    int main(){
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr); cout.tie(nullptr);
        //int t; cin>>t; while(t --)
        Solve();
        return 0;
    }