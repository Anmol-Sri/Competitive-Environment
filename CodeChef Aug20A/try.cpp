#include <bits/stdc++.h>
using namespace std;

//CodeLibrary Code
struct ConveXHulonglongint{
    typedef pair<long long, long long> point;

    long long cross(const point &a, const point &b, const point &c) {
        return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);
    }

    vector<point> convexHulonglongint(vector<point> points) {
        if (points.size() <= 1)
            return points;
        sort(points.begin(), points.end());
        vector<point> h;
        for (auto p: points) {
            while (h.size() >= 2 && cross(h.end()[-2], h.back(), p) >= 0)
                h.pop_back();
            h.push_back(p);
        }
        reverse(points.begin(), points.end());
        int len1 = h.size();
        for (auto p: points) {
            while (h.size() > len1 && cross(h.end()[-2], h.back(), p) >= 0)
                h.pop_back();
            h.push_back(p);
        }
        h.resize(h.size() - 1 - (h[0] == h[1]));
        return h;
    }
};

const int mxN = 5e5 + 6;
const int Nmx = 1e5 + 10;
const long long int modulous = 1e9 + 7;
long long int a[mxN];
long long int calc_ans_last[mxN];
long long int Binary_exponent_value[mxN];
int n;
long long int calc_factor[6*Nmx];
long long int INV_CALC[6*Nmx],INV_CALC_calc_factor[6*Nmx];
vector < long long int > temp_val_check;

void output_val(){
    for(int i=1;i<=n;i++)
    {
        cout << calc_ans_last[i] << " ";
    }
    cout << "\n";
}

//Code Taken From - https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/
long long int powermodulous(long long int n,long long int m,long long int modulous){
    if(m==0) return 1;
    long long int val=powermodulous(n,m/2,modulous);
    val %= modulous;
    if(m%2==0) return (val*val) % modulous; else return (((val*val) % modulous) * n) % modulous;
}

void inp1_func(){
    int i = 0;

    while(i<n){
        cin >> a[i];
        temp_val_check[a[i]]++;
        i++;
    }
}

//CodeLibrary Code
struct Prims{
    typedef pair<int, int> pii;
    typedef vector<vector<pii> > Graph;

    long long prim(Graph &g, vector<int> &pred) {
        int n = g.size();
        pred.assign(n, -1);
        vector<bool> vis(n);
        vector<int> prio(n, INT_MAX);
        prio[0] = 0;
        priority_queue<pii, vector<pii> , greater<pii> > q;
        q.push(make_pair(0, 0));
        long long res = 0;

        while (!q.empty()) {
            int d = q.top().first;
            int u = q.top().second;
            q.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            res += d;
            for (int i = 0; i < (int) g[u].size(); i++) {
                int v = g[u][i].first;
                if (vis[v])
                    continue;
                int nprio = g[u][i].second;
                if (prio[v] > nprio) {
                    prio[v] = nprio;
                    pred[v] = u;
                    q.push(make_pair(nprio, v));
                }
            }
        }
        return res;
    }
};

//Code Taken from - https://www.geeksforgeeks.org/multiplicative-INV_CALCerse-under-modulousulo-m/
long long int modulousInverse(long long int a, long long int m = modulous){
    long long int m0 = m;
    long long int y = 0, x = 1;
    if (m == 1)
      return 0;
    while (a > 1)
    {
        // q is quotient
        long long int q = a / m;
        long long int t = m;
        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;
        // Update y and x
        y = x - q * y;
        x = t;
    }
    // Make x positive
    if (x < 0)
       x += m0;
    return x;
}

void travel(int idx, int p, long long int pass, int month){
    // // sec[idx] -= pass;
    // if(sec[idx] <= 0){
    //     sec[idx] = 0;
    //     if(final_value[idx] == -1) final_value[idx] = month;
    // }
    // for(auto x : g[idx]){
    //     if( p == x ) continue;
    //     travel(x, idx, pass, month);
    // }
}

void mem1(){
    memset(Binary_exponent_value, 0, sizeof Binary_exponent_value);
    memset(calc_ans_last, 0, sizeof calc_ans_last);
}

void solve()
{
    vector<vector<int>> g;
    long long int parent[mxN];
    long long int part1[mxN];
    long long int sec[mxN];
    long long int final_value[mxN];
    int n;
    int i;
    cin >> n;
    g = vector<vector<int>> (n+5);
    i = 0;
    while(i < n - 1){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        i++;
    }
    memset(final_value, -1, sizeof final_value);
    i = 0;
    while(i<n) {cin >> parent[i+1]; i++; }
    i = 1;
    while(i<=n){cin >> part1[i]; i++;}
    i = 1;
    while(i<=n){ cin >> sec[i]; i++; }
    i = 1;
    while(i<=n){
        travel(parent[i],0,part1[parent[i]],i);
        for(auto x : g[parent[i]]){
            for(auto it = g[x].begin();it!=g[x].end();it++){
                if(*it == parent[i]){
                    g[x].erase(it);
                    break;
                }
            }
        }
        g[parent[i]].clear();
        i++;
    }
    i = 1;
    while(i<=n){ cout << final_value[i] << " "; i++; }
    cout << "\n";
}

long long int loop1(vector < pair < long long int,  int > > v){
    long long int qwe = 1;

    for(auto x : v){
        Binary_exponent_value[x.second] = powermodulous(2,x.first, modulous);
        qwe = qwe * Binary_exponent_value[x.second];
        qwe = qwe % modulous;
    }
    return qwe;
}

//Code Takej From - https://www.geeksforgeeks.org/compute-ncr-p-set-3-using-fermat-little-theorem/
// nCr % modulous
void fact_calc()
{
    calc_factor[0] = INV_CALC_calc_factor[0] = calc_factor[1] = INV_CALC_calc_factor[1] = 1;
    INV_CALC[1] = 1;
    for(int i = 2; i <= 5*Nmx + 10; i++){
        calc_factor[i] = (calc_factor[i-1]*i)%modulous;
        INV_CALC[i] = (INV_CALC[modulous%i]*(modulous - modulous/i))%modulous;
        INV_CALC_calc_factor[i] = (INV_CALC_calc_factor[i-1]*INV_CALC[i])%modulous;
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);   
    #endif

    fact_calc();
    int t = 1;
    cin >> t;

    for(int asdqwe = 1; asdqwe <= t; asdqwe++){
        priority_queue< pair<long long int, long long int> > pq;
        cin >> n;
        vector< pair<long long int, int> > v;
        temp_val_check = vector<long long int> (n+5,0);
        int i = 0;

        inp1_func();

        mem1();

        i = 0;
        while(i < n + 5){
            if(temp_val_check[i]){
                pq.push({temp_val_check[i],-i});
                v.emplace_back(temp_val_check[i],i);
            }
            i++;
        }

        long long int sum = loop1(v);    

        for(;pq.size();){
            pair<long long int, long long int> p = pq.top();
            pq.pop();
            long long int c = p.first;
            long long int tot = temp_val_check[-1 * p.second];

            // int pqoweipqowei = 123123;
            // int laksdjlaksdj = 433461322;
            // int zmxcnbmzxcnb = 4567890;
            // int pwkenfpwekfn = 1234566;

            // long long int ponfqkjfbfwesfj = pqoweipqowei + laksdjlaksdj + zmxcnbmzxcnb;
            // ponfqkjfbfwesfj %= modulous;

            long long int modulousINV_CALC = modulousInverse(Binary_exponent_value[-1 * p.second]);
            sum = (sum * modulousINV_CALC) % modulous;
            long long int t = ( ( ( calc_factor[tot] * INV_CALC_calc_factor[c]) % modulous ) * INV_CALC_calc_factor[tot-c]) % modulous;
            
            // ponfqkjfbfwesfj %= modulous;
            // ponfqkjfbfwesfj += pwkenfpwekfn;
            // ponfqkjfbfwesfj %= modulous;

            calc_ans_last[-1 * p.second] = calc_ans_last[-1 * p.second] + ( sum * t ) % modulous;
            calc_ans_last[-1 * p.second] = calc_ans_last[-1 * p.second] % modulous;
            c--;

            // ponfqkjfbfwesfj = pqoweipqowei + laksdjlaksdj + zmxcnbmzxcnb;
            // ponfqkjfbfwesfj %= modulous;

            Binary_exponent_value[-1 * p.second] = (Binary_exponent_value[-1 * p.second] + modulous - t) % modulous;
            if(c){
                pq.push({c,-1 * -1 * p.second});
            
                // ponfqkjfbfwesfj %= modulous;
                // ponfqkjfbfwesfj += pwkenfpwekfn;
                // ponfqkjfbfwesfj %= modulous;

                sum = (sum*Binary_exponent_value[-1 * p.second])%modulous;
            }
        }
        
        output_val();
    }

    return 0;
}