#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	bool check[n];
	std::vector<int> pos_mod_2;
	std::vector<int> pos_mod_4;
	std::vector<int> pos_zero;
	bool flag=false;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(arr[i]==0){
			pos_zero.push_back(i);
		}
		if(arr[i]%4==0){
			pos_mod_4.push_back(i);
		}
		else if(arr[i]%4==2){
			pos_mod_2.push_back(i);
		}
	}

	cout<<"Div by 4:-\n";
	for(auto x:pos_mod_4) cout<<x<<" - ";
	cout<<"\nDiv by 2:-\n";
	for(auto x:pos_mod_2) cout<<x<<" - ";
	cout<<"\n\n";

	ll ans=0;
if(pos_mod_2.size()==0){
		ans=((n+1)*n)/2;
		cout<<ans<<"\n";
		return;
	}
	if(pos_mod_4.size()==0){
		if(pos_mod_2.size()==1){
			ans=((n+1)*n)/2-(n-pos_mod_2[0])-(n-pos_mod_2[0]+1)*pos_mod_2[0];
			cout<<ans<<"\n";
			return;
		}
		else{
			for(int i=0;i<n;i++){
				int p1=-1;
				int p2=-1;
				for(int j=0;j<pos_mod_2.size();j++){
					if(p1==-1 && pos_mod_2[j]>=i){
						p1=pos_mod_2[j];
					}
					else if(p1!=-1 and pos_mod_2[j]>=i){
						p2=pos_mod_2[j];
						break;
					}
				}
				//cout<<p1<<" - "<<p2<<endl;
				if(p2!=-1 && p1!=-1){
					ans=ans+(n-i)-(p2-p1);
				}
				else if(p1!=-1 && p2==-1){
					ans=ans+(p1-i);
				}
				else if(p1==-1 && p2==-1){
					ans=ans+(n-i);
				}
				//cout<<"ans = "<<ans<<endl;
			}
			cout<<ans<<"\n";
			return;
		}
	}
	for(int i=0;i<n;i++){

		int p1=-1;
		int p2=-1;
		int p3=-1;

		for(int j=0;j<pos_mod_2.size();j++){
			if(p1==-1 && pos_mod_2[j]>=i){
				p1=pos_mod_2[j];
			}
			else if(p1!=-1 and pos_mod_2[j]>=i){
				p2=pos_mod_2[j];
				break;
			}
		}

		for(int j=0;j<pos_mod_4.size();j++){
			if(pos_mod_4[j]>=i){
				p3=pos_mod_4[j];
				break;
			}
		}
		//cout<<p1<<" - "<<p2<<" - "<<p3<<endl;
		if(p3!=-1 && p1!=-1 && p3<p1){
			ans=ans+(n-i);
			//cout<<"ans = "<<ans<<endl;
			continue;
		}
		if(p3!=-1 && p2!=-1 && p3<p2){
			p2=p3;
		}
		if(p3!=-1 && p2==-1 && p1!=-1){
			p2=p3;
		}
		//cout<<p1<<" - "<<p2<<" - "<<p3<<endl;
		if(p2!=-1 && p1!=-1){
			ans=ans+(n-i)-(p2-p1);
		}
		else if(p1!=-1 && p2==-1){
			ans=ans+(p1-i);
		}
		else if(p1==-1 && p2==-1){
			ans=ans+(n-i);
		}
		//cout<<"ans = "<<ans<<endl;
	}
	cout<<ans<<"\n";
	return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	while(t--){
		solve();
	}
    return 0;
}