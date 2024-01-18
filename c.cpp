/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define all(x) x.begin(), x.end()


void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
// void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
 

template<typename T> void chmin (T &a, T &b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T &b) {if (a < b) swap(a, b);}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif



void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
    }
    vector<int> closest(n);

    closest[0] = 1;
    closest[n - 1] = n - 2;

    for (int i = 1; i < n - 1; ++i) {
        int l = abs(a[i] - a[i-1]);
        int r = abs(a[i] - a[i+1]);
        if (l < r) closest[i] = i - 1;
        else closest[i] = i + 1;
    }
    vector<int> fcost(n), bcost(n);
    for (int i = 1; i < n; ++i) {
        if (closest[i - 1] == i) {
            fcost[i] = 1 + fcost[i - 1];
        } else {
            fcost[i] = a[i] - a[i - 1] + fcost[i - 1];
        }
    }
    for (int i = n - 2; i >= 0; --i) {
        if (closest[i + 1] == i) {
            bcost[i] = bcost[i + 1] + 1;
        } else {
            bcost[i] = bcost[i + 1] + a[i + 1] - a[i];
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y; --x, --y;
        if (x < y) {
            cout << fcost[y] - fcost[x] << endl;
        } else {
            cout << bcost[y] - bcost[x] << endl;
        }
    }
} 

int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE   
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);  
    #endif  
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
        // cout << (solve() ? "Yes\n" : "No\n");
    } 

    #ifndef ONLINE_JUDGE
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
