#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
	int h,c,t;
	cin>>h>>c>>t;
	if(h==t){
		cout<<"1\n";
		return;
	}
	if(h+c==2*t){
		cout<<"2\n";
		return ;
	}

	ll sum=0;
	int ans=0;
	float prev=FLT_MAX;
	float prev2=FLT_MAX;
	float dis=0.0;

	float t1=0.0;
	float r2=0.0;
	for(int i=1;i<100;i++){
		if(i&1) t1+=(float)h;
		else t1+=(float)(c);
		r2=t1/i;
		cout<<"for i = "<<i<<" diff = "<<abs(r2-t)<<" with temp = "<<r2<<"\n";
	}
	
	for(int i=1;true;i++){
		if(i&1){
			sum+=h;
		}
		else{
			sum+=c;
		}
		cout<<"sum = "<<sum<<"\n";
		float avg=((float)sum/(float)i);
		float temp=abs((float)(avg-(float)t));
		cout<<"prev = "<<prev<<" temp = "<<temp<<"\n";
		if(avg<prev and avg<pre2){
			break;
		}
		else{
			prev2=prev;
			
			ans=i;
		}

	}
	cout<<ans<<"\n";
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
		
	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}