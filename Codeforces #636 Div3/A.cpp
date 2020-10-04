#include <bits/stdc++.h>
using namespace std;
#define ll long long int

//Geeks for Geeks Code to check power
ll recur(ll x,  ll y) 
{ 
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return recur(x, y / 2) * recur(x, y / 2); 
    else
        return x * recur(x, y / 2) * recur(x, y / 2); 
} 

void solve()
{
       ll n;
       cin>>n;
       ll x=0;
       ll k=0;
       for(ll i=2;i<=32;i++)
       {
           ll temp=recur(2,i);
           temp--;
           if(n%temp==0)
           {
               k=i;
               x=n/temp;
               break;
           }
       }

       cout<<x<<endl;
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
		
	ll t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}