#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const ll INF=1e18;
const int mxN=2e5+1;
ll pref1[mxN];
ll pref2[mxN];
ll pref[mxN];
void solve()
{
    ll n;
    ll k;
    cin>>n>>k;
    array<ll,3> arr[n];
    ll alice =0;
    ll bob=0;
    for(int i=0;i<n;i++){
        ll t,a,b;
        cin>>t>>a>>b;
        alice+=a;
        bob+=b;
        a^=1;
        b^=1;
        arr[i]={t,a,b};
    }
	if(alice>=k && bob>=k){
        sort(arr,arr+n);
		for(int i=1;i<mxN;i++){
			pref[i]=INF;
			pref1[i]=INF;
			pref2[i]=INF;
		}
        ll fir=0;
        ll sec=0;
        ll thir=0;
        ll mn = 1e18; 
        for(int i=0;i<n;i++)
        {
            array<ll,3> qwe=arr[i];
            ll val = qwe[0];
            bool al = (qwe[1]==1);
            bool bo = (qwe[2]==1);
            if(!al && bo){
                pref1[fir+1] = min(pref1[fir]+val,pref1[fir+1]);
                fir++;
            }
            if(!bo && al){
                pref2[sec+1] = min(pref2[sec]+val,pref2[sec+1]);
                sec++;
            }
            if(!al & !bo){
                pref[thir+1] = min(pref[thir]+val,pref[thir+1]);
                thir++;
            }
            if(fir+thir>=k && sec+thir>=k){
                mn = min(pref[thir]+pref1[k-thir]+pref2[k-thir],mn);
            }
        }
        cout << mn<<"\n";
        return;
    }
    else{
    	cout<<"-1\n";
    }
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);

	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		
	int t=1;

	while(t--){
		solve();
	}

	return 0;
}