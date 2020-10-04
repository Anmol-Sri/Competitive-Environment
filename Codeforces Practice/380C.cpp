#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mxN=1e6+5;
struct node{
	int left,right,ans;
};

char s[mxN];
int len;

node st[mxN<<2];

void merge(node &a,node &b,node &c){
    int t;
    t=min(b.left,c.right);
    a.left=b.left+c.left-t;
    a.right=b.right+c.right-t;
    a.ans=b.ans+c.ans+t;
}

void build(int l,int r,int now){
    if (l==r){
        if (s[l-1]=='(')
            st[now].left=1;
        else
            st[now].right=1;
        return;
    }
    int mid=(l+r)>>1;
    if (l<=mid)
        build(l,mid,now<<1);
    if (mid<r)
        build(mid+1,r,now<<1|1);
    merge(st[now],st[now<<1],st[now<<1|1]);
}

node query(int a,int b,int l,int r,int now){
    if (a<=l && r<=b)
        return st[now];
    int mid=(l+r)>>1;
    node tempb,tempc;
    node tempa;
    tempb.left=tempb.right=tempb.ans=0;
    tempc.left=tempc.right=tempc.ans=0;
    if (a<=mid)
        tempb=query(a,b,l,mid,now<<1);
    if (mid<b)
        tempc=query(a,b,mid+1,r,now<<1|1);
    merge(tempa,tempb,tempc);
    return tempa;
}

void solve(){
    int m,a,b;
    node t;
    cin>>s;
    for (len=0;s[len];++len);
    build(1,len,1);
    cin>>m;
    for (;m;--m){
        cin>>a>>b;
        t=query(a,b,1,len,1);
        printf("%d\n",t.ans<<1);
    }
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
	//cin>>t;

	while(t--){
		solve();
	}
    return 0;
}