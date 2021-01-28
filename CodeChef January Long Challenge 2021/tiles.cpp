#include<bits/stdc++.h>
using namespace std;
#define fin  cin.ignore(numeric_limits<streamsize>::max(),'\n')
#define fout cout.flush()
#define fill(w,t) memset(w,t,sizeof(w))
#define google cout<<"Case #"<<countu<<": "
#define S(t) (ll)t.size()
#define bl '\n'
#define nl cout<<bl
#define cout1(a) cout<<a<<bl
#define cout2(a,b) cout<<a<<" "<<b<<bl
#define cout3(a,b,c) cout<<a<<" "<<b<<" "<<c<<bl
#define cout4(a,b,c,d) cout<<a<<" "<<b<<" "<<c<<" "<<d<<bl
#define print(azz,szz,ezz) for(ll i=szz;i<=ezz;i++){ cout<<azz[i]<<" "; }
#define rprint(azz,szz,ezz) for(ll i=szz;i>=ezz;i--){ cout<<azz[i]<<" "; }
#define input(azz,szz,ezz) sfor(pzz,szz,ezz) cin>>azz[pzz]
#define all(v) v.begin(),v.end()
#define ll long long
#define ldb long double
#define db double
#define ull unsigned long long
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define mk make_pair
#define pll pair<ll,ll>
#define pldb pair<ldb,ldb>
#define fi first
#define se second
#define vull vector<ull>
#define vll vector<ll>
#define vb vector<bool>
#define vldb vector<ldb>
#define vpll vector< pll >
#define vpldb vector< pldb >
#define pqmin priority_queue<ll,vector<ll>,greater<ll> >     //minheap
#define pq priority_queue<ll>                                //maxheap ll
#define pqpll priority_queue<pll>                            //maxheap pll
#define pqpllmin priority_queue<pll, vector<pll>, greater<pll> >   //minheap pll
#define mll map<ll,ll>
#define mldb map<ldb,ldb>
#define umll unordered_map<ll,ll>
#define sll set<ll>
#define usll unordered_set<ll>
#define sfor(i,azz,bzz) for (ll i = (azz); i <= (bzz); ++i)
#define rfor(i,bzz,azz) for (ll i = (bzz); i >= (azz); --i)
const ll mod = 1e9+7;
// const ll mod=998244353 ;
const ll maxn = 1e6+1;
const ll llmax = (1ll<<60);
const int intmax = (1<<30);
const ldb PI = 3.14159265358979323846264338327950288419716939937510582097494459230781640628620899863;
vll fact , ifact;
vll primes;
vll spf;

int arr[20][20];

void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cin >> arr[i][j];
    }
}

int n;

int get(int x,int y)
{
    arr[x][y] ^= 1;
    int ret = 0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;j++)
        {
            if(i == n || j == n)
                continue;
            if(arr[i][j] == 0 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 0)
                ret++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(arr[i][j])
                cout << "\\";
            else
                cout << "/";
        }
        cout << '\n';
    }
    cout << ret << '\n';
    return ret;
}

bool solve(ll countu){
  ll q,k;
  cin>>n>>q;
  init(n);
  k = get(1,1);
  ll ans[n][n];
  ll r;
  fill(ans,-1);
  cout<<1<<" "<<1<<" "<<1<<endl;
  fout;
  //cin>>r;
  r = get(1,1);
  if(r==-1) return false;
  if(r<k)
  {
    ans[0][0]=1;
    ans[0][1]=1;
    ans[1][0]=1;
    ans[1][1]=0;
  }
  else if(r>k)
  {
    ans[0][0]=0;
    ans[0][1]=1;
    ans[1][0]=1;
    ans[1][1]=0;
  }
  else
  {
    bool flag=false;
    ll ri=0,ci=1;
    sfor(i,0,3)
    {
      ll rj=0,cj=2;
      sfor(j,0,2)
      {
        k=r;
        cout<<1<<" "<<(rj%2)+1<<" "<<cj<<endl;
        fout;
        //cin>>r;
        r = get((rj%2 + 1),cj);
        if(r==-1) return false;
        if(r>k)
        {
          if(n==2)
          {
            flag=true;
            ans[0][0]=0;
            ans[0][1]=1;
            ans[1][0]=1;
            ans[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<endl;
          fout;
          //cin>>r;
          r = get(1,1);
          if(r==-1) return false;
          if(r<k)
          {
            flag=true;
            ans[0][0]=1;
            ans[0][1]=1;
            ans[1][0]=1;
            ans[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<endl;
          fout;
          //cin>>r;
          r = get(1,1);
          if(r==-1) return false;
        }
        rj++;
      }
        if(flag) break;
        ri++;
        k=r;
        cout<<1<<" "<<(ri%2)+1<<" "<<ci<<endl;
        fout;
        //cin>>r;
        r = get((ri%2) + 1,ci);
        if(r==-1) return false;
        if(r>k)
        {
          if(n==2)
          {
            flag=true;
            ans[0][0]=0;
            ans[0][1]=1;
            ans[1][0]=1;
            ans[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<endl;
          fout;
          //cin>>r;
          r = get(1,1);
          if(r==-1) return false;
          if(r<k)
          {
            flag=true;
            ans[0][0]=1;
            ans[0][1]=1;
            ans[1][0]=1;
            ans[1][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<1<<endl;
          fout;
          //cin>>r;
          r = get(1,1);
          if(r==-1) return false;
        }
    }
  }
  sfor(i,2,n-1)
  {
      if(ans[i-1][0]!=0)
       {
      k=r;
      cout<<1<<" "<<i<<" "<<1<<endl;
      fout;
      //cin>>r;
      r = get(i,1);
      if(r==-1) return false;
      ans[i-1][0]^=1;
      if(r>k)
      {
        ans[i][0]=1;
        ans[i][1]=0;
      }
       }
       if(ans[i-1][1]!=1)
       {
           k=r;
      cout<<1<<" "<<i<<" "<<2<<endl;
      fout;
      //cin>>r;
      r = get(i,2);
      if(r==-1) return false;
      ans[i-1][1]^=1;
      if(r>k)
      {
        ans[i][0]=1;
        ans[i][1]=0;
      }
       }
       if(ans[i][0]!=-1) continue;
      ll cj=0;
      sfor(j,0,3)
      {
        k=r;
        cout<<1<<" "<<i+1<<" "<<(cj%2)+1<<endl;
        fout;
        //cin>>r;
        r = get(i+1,(cj%2) + 1);
        if(r==-1) return false;
        if(r>k)
        {
          k=r;
          cout<<1<<" "<<i<<" "<<1<<endl;
          fout;
          //cin>>r;
          r = get(i,1);
          ans[i-1][0]^=1;
          if(r==-1) return false;
          if(r<k)
          {
            ans[i][0]=1;
            ans[i][1]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<i<<" "<<1<<endl;
          fout;
          //cin>>r;
          r = get(i,1);
          ans[i-1][0]^=1;
          if(r==-1) return false;
        }
        cj++;
      }
  }
  sfor(i,2,n-1)
  {
        if(ans[0][i-1]!=0)
        {
      k=r;
      cout<<1<<" "<<1<<" "<<i<<endl;
      fout;
      //cin>>r;
      r = get(1,i);
      if(r==-1) return false;
      ans[0][i-1]^=1;
      if(r>k)
      {
        ans[0][i]=1;
        ans[1][i]=0;
      }
        }
        if(ans[1][i-1]!=1)
        {
            k=r;
      cout<<1<<" "<<2<<" "<<i<<endl;
      fout;
      //cin>>r;
      r = get(2,i);
      if(r==-1) return false;
      ans[1][i-1]^=1;
      if(r>k)
      {
        ans[0][i]=1;
        ans[1][i]=0;
      }
        }
        if(ans[0][i]!=-1) continue;
      ll rj=0;
      sfor(j,0,3)
      {
        k=r;
        cout<<1<<" "<<(rj%2)+1<<" "<<i+1<<endl;
        fout;
        //cin>>r;
        r = get((rj%2) + 1,i+1);
        if(r==-1) return false;
        if(r>k)
        {
            k=r;
          cout<<1<<" "<<1<<" "<<i<<endl;
          fout;
          //cin>>r;
          r = get(1,i);
          ans[0][i-1]^=1;
          if(r==-1) return false;
          if(r<k)
          {
            ans[0][i]=1;
            ans[1][i]=0;
            break;
          }
          k=r;
          cout<<1<<" "<<1<<" "<<i<<endl;
          fout;
          //cin>>r;
          r = get(1,i);
          if(r==-1) return false;
          ans[0][i-1]^=1;
        }
        rj++;
      }
  }
  sfor(i,2,n-1)
  {
    sfor(j,2,n-1)
    {
      if(ans[i-1][j-1]!=0)
      {
        k=r;
          cout<<1<<" "<<i<<" "<<j<<endl;
          fout;
          //cin>>r;
          r = get(i,j);
          if(r==-1) return false;
          ans[i-1][j-1]^=1;
      }
      if(ans[i-1][j]!=1)
      {
        k=r;
        cout<<1<<" "<<i<<" "<<j+1<<endl;
          fout;
          //cin>>r;
          r = get(i,j+1);
          if(r==-1) return false;
          ans[i-1][j]^=1;
      }
      if(ans[i][j-1]!=1)
      {
        k=r;
        cout<<1<<" "<<i+1<<" "<<j<<endl;
          fout;
          //cin>>r;
          r = get(i+1,j);
          if(r==-1) return false;
          ans[i][j-1]^=1;
      }

      k=r;
      cout<<1<<" "<<i+1<<" "<<j+1<<endl;
      fout;
      //cin>>r;
      r = get(i+1,j+1);
      if(r==-1) return false;
      if(r>k)
      {
        ans[i][j]=0;
      }
      else
      {
        ans[i][j]=1;
      }
    }
  }
  cout<<2<<endl;
  sfor(i,0,n-1)
  {
    sfor(j,0,n-1)
    {
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }
  for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(ans[i-1][j-1])
                cout << "\\";
            else
                cout << "/";
        }
        cout << '\n';
    }
  fout;
  cin>>r;
  if(r==-1) return false;
  return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    srand(time(0));
     freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t=1;
    cin>>t;
    sfor(i,1,t)
        if(!solve(i)) break;


    return 0;
}