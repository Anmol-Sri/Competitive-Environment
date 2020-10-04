
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(B) (B).begin(), (B).end()
#define sz(B) (B).size()
#define pb push_back
#define mp make_pair
#define sc second
#define fr first
 
typedef long long ll;
typedef pair<ll , ll> pll;
typedef pair<int , int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<pll> vll;
 
const int MAX = 2e5 + 10;
const int inf = 2e9 + 10;
const int mod = 1e9 + 7;
const double eps = 1e-15;
 
int n;
ll a[MAX];
ll t[MAX*4], ad[MAX*4];
 
void build(int v, int l, int r){
      if(l == r){
            t[v] = a[l];
            return;
      }
 
      int m = (l + r) >> 1;
 
      build(v+v, l, m);
      build(v+v+1, m+1, r);
 
      t[v] = min(t[v+v], t[v+v+1]);
}
 
ll get(int l, int r, int v = 1, int lp = 1, int rp = n){
      if(r < lp || rp < l){
            return inf;
      }
 
      if(l <= lp && rp <= r){
            return t[v] + ad[v];
      }
 
      int m = (lp + rp) >> 1;
 
      return ad[v] + min(get(l, r, v+v, lp, m), get(l, r, v+v+1, m+1, rp));
}
 
ll vl;
 
void upd(int l, int r, int v = 1, int lp = 1, int rp = n){
      if(r < lp || rp < l){
            return;
      }
 
      if(l <= lp && rp <= r){
            ad[v] += vl;
            return;
      }
 
      int m = (lp + rp) >> 1;
 
      upd(l, r, v+v, lp, m);
      upd(l, r, v+v+1, m+1, rp);
 
      t[v] = min(t[v+v]+ad[v+v], t[v+v+1]+ad[v+v+1]);
}
 
int m;
char ch[3000000];
 
int main(){
	/*
	    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);*/

    #ifndef ONLINE_JUDGE
	    freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

      //gets(ch);
      //sscanf(ch, "%d", &n);
      cin>>n;
      //gets(ch);
      //stringstream ss(ch);
 
      for(int i = 1;i <= n;++i){
            cin >> a[i];
      }
 
      build(1, 1, n);
 
      //gets(ch);
     // sscanf(ch, "%d", &m);
 		cin>>m;
      while(m--){
            //gets(ch);
            stringstream bf(ch);
 
            int l, r;
 
            bf >> l >> r;
 
            ++l, ++r;
 
            if(bf >> vl){
                  if(l > r)upd(l, n), upd(1, r);
                  else upd(l, r);
            }
            else {
                  if(l > r){
                        cout << min(get(l, n), get(1, r));
                  }
                  else{
                        cout << get(l, r);
                  }
                  printf("\n");
            }
      }
}