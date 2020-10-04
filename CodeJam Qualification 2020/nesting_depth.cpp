#include <bits/stdc++.h>
using namespace std;
#define ll long int

int closepair(string s,int i){
	char ch=s[i];
	for(;i<s.length();i++){
		if(s[i]!=ch){
			return i-1;
		}
	}
	return s.length()-1;
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

	for(int q=1;q<=t;q++){
		string s;
		cin>>s;
		string snew="";
		int len=s.length();
		for(int i=0;i<len;i++){
			if(i==0 && s[i]=='0'){
				int r=closepair(s,i);
				for(;i<=r;i++){
					snew=snew+s[i];
				}
				i=r;
				continue;
			}
			else if(i==0){
				int n=s[i]-'0';
				int r=closepair(s,i);
				for(int j=1;j<=n;j++){
					snew=snew+"(";
				}
				for(;i<=r;i++){
					snew=snew+s[i];
				}
				i=r;
				continue;
			}
			else if(s[i-1]>s[i]){
				int n=s[i]-'0';
				int prev=s[i-1]-'0';
				for(int j=1;j<=(prev-n);j++){
					snew=snew+")";
				}
				int r=closepair(s,i);
				for(;i<=r;i++){
					snew=snew+s[i];
				}
				i=r;
				continue;
			}
			else if(s[i-1]<s[i]){
				int n=s[i]-'0';
				int prev=s[i-1]-'0';
				for(int j=1;j<=(n-prev);j++){
					snew=snew+"(";
				}
				int r=closepair(s,i);
				for(;i<=r;i++){
					snew=snew+s[i];
				}
				i=r;
				continue;
			}
		}
		int last=s[len-1]-'0';
		for(int i=1;i<=last;i++){
			snew=snew+")";
		}
		cout<<"Case #"<<q<<": "<<snew<<"\n";
	}
    return 0;
}