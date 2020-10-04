#include <bits/stdc++.h>
using namespace std;
#define ll long int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t;
	cin>>t;

	for(int q=1;q<=t;q++){
		int n;
		cin>>n;
		std::vector<pair<int,int>> v;
		int arr[n][2];
		char ans[n];
		int t1,t2;
		for(int i=0;i<n;i++){
			cin>>t1>>t2;
			arr[i][0]=t1;
			arr[i][1]=t2;
			v.push_back(make_pair(t1,i));
		}
		sort(v.begin(), v.end());
		int cstart=0;
		int jstart=0;
		bool flag=false;
		for(int i=0;i<n;i++){
			if(cstart<=v[i].first){
				ans[v[i].second]='C';
				cstart=arr[v[i].second][1];
			}
			else if(jstart<=v[i].first){
				ans[v[i].second]='J';
				jstart=arr[v[i].second][1];
			}
			else{
				flag=true;
				break;
			}
		}
		cout<<"Case #"<<q<<": ";
		if(flag){
			cout<<"IMPOSSIBLE\n";
		}
		else{
			for(int i=0;i<n;i++){
				cout<<ans[i];
			}
			cout<<"\n";
		}
	}
    return 0;
}