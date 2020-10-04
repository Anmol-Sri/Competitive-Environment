#include <bits/stdc++.h>
using namespace std;
// typedef unsigned long long ulong long int;
// typedef long long long long int;
// #define long long int long long
#define dd double
#define MOD1 1000000007
#define MOD2 998244353
#define nl cout<<endl
#define rt long long int Q[100005]={0}
#define mp make_pair
#define test() long long int t;cin>>t;while(t--)
#define pb push_back
#define ff first    
#define ss second
#define along long int(v) v.begin(),v.end()
#define s(ar,n) sort(ar,ar+n)
#define rs(ar,n) sort(ar, ar+n, greater<long long int>()) 
#define oa(a,n) for(long long int i=0;i<n;i++)cout<<a[i]<<" ";nl
#define cn(a,n) for(long long int i=0;i<n;i++)cin>>a[i];
#define ov(a,n) for(long long int i=n-1;i>=0;i--)cout<<a[i]<<" ";nl
#define ovp(a,n) for(long long int i=0;i<n;i++)cout<<a[i].ff<<" "<<a[i].ss<<endl;
#define maxa(ar,N) *max_element(ar,ar+N)
#define mina(ar,N) *min_element(ar,ar+N)
#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
typedef pair<long long int,long long int> pii;
long long int powe(long long int n,long long int m){if(m==0)return 1;long long int t=powe(n,m/2);if(m%2==0)return (t*t);return (((t*t))*n);}
long long int mpowe(long long int n,long long int m,long long int MOD){if(m==0)return 1;long long int t=mpowe(n,m/2,MOD);t%=MOD;if(m%2==0)return (t*t)%MOD;return (((t*t)%MOD)*n)%MOD;}
long long int logtwo(long long int n){if(n==1)return 0;if(n==0) return -1;return logtwo(n/2)+1;}

int main()
{
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t;
	cin>>t;

	while(t--){
		long long int n;
		long long int k;
		long long int ans=0;
		map<long long int,long long int> fre;
		cin>>n>>k;
		for(long long int i=0;i<n;i++){
			long long int temp;
			cin>>temp;
			fre[temp%k]++;
		}
		for(auto iter:fre){
			if(iter.first==0){
				continue;
			}
			long long int t1=(iter.ss-1);
			long long int t2=t1*k;
			long long int t3=t2+k;
			long long int t4=t3-iter.ff;
			ans=max(ans,t4);
		}
		if(ans==0){
			cout<<ans<<endl;
		}
		else{
			cout<<ans+1<<endl;
		}
	}

	return 0;
}