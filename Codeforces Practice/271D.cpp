#include <bits/stdc++.h>
#define ll long long int
using namespace std;

const int mxN = 1500000;
string s;
bool val[26];
int k;
int n;
int ans;

struct node{
	int next[26];
	int flag;
};
node Trie[mxN];

int v = 1;
void add(int f){
	int cur = 0;
	for(int i = f; i < n; i++){
		int to = Trie[cur].next[s[i] - 'a'];
		if(!to) Trie[cur].next[s[i] - 'a'] = v++;
		cur = Trie[cur].next[s[i] - 'a'];
	}
	Trie[cur].flag = true;
}

void dfs(int v, int cur){
	if(cur <= k) ans++;
	for(int i = 0; i < 26; i++){
		int to = Trie[v].next[i];
		if(to) dfs(to, cur + !val[i]);
	}
}

void solve(){
	cin >> s;
	n = s.size();
	string asd;
	cin >> asd;
	for(int i = 0; i < 26; i++){
		val[i] = (asd[i] == '1');
	}
	cin >> k;
	
	for(int i =  0; i < n; i++){
		add(i);
	}
	dfs(0, 0);
	cout << ans - 1 << "\n";
	return ;
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
		
	int t = 1;

	while(t--){
		solve();
	}

	return 0;
}