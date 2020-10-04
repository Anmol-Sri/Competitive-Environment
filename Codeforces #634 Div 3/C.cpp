#include <bits/stdc++.h>
using namespace std;
#define ll long int

void solve(){
	int n;
	cin>>n;
	int arr[n];
	unordered_map<int,int> fre;

	int highest =1;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		if(fre.find(arr[i])!=fre.end()){
			fre[arr[i]]++;
			highest=max(highest,fre[arr[i]]);
		}
		else{
			fre[arr[i]]=1;
		}
	}

	if(fre.size()==highest){
		cout<<highest-1<<"\n";
		return;
	}
	else if(highest<fre.size()){
		cout<<highest<<"\n";
		return;
	}
	else{
		cout<<fre.size()<<"\n";
		return;
	}
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