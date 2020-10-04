#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll add[3];
ll mul[3];
ll in[3];
ll out[3];
ll pro[3];

bool check_two(){
	if (in[1]!=0 && in[2]!=0 && out[2]%in[2]==0 && out[1]*in[2]-in[1]*out[2]!=0 && (out[1]*in[2]-in[1]*out[2])%in[2]==0 && out[0]==in[0])
        return true;
    else if (add[1]!=0 && in[0]-in[2]!=0 && out[0]-out[2]!=0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[2]*in[0]-in[2]*out[0])%(out[0]-out[2])==0 && (out[2]*in[0]-in[2]*out[0])/(out[0]-out[2])==add[1] && (out[0]-out[2])%(in[0]-in[2])==0)
        return true;
    else if (out[0]-out[1]!=0 && out[1]*in[0]-out[0]*in[1]!=0 && (out[1]*in[0]-out[0]*in[1])%(out[0]-out[1])==0 && out[2]==in[2])
        return true;
    else if (in[1]!=0 && out[1]%in[1]==0 && add[0]!=0 && add[2]!=0 && add[0]==add[2] && add[0]!=add[1])
        return true;
    /*
	int ans=3;
	if(in[1]==out[1] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[1]==out[1]){
		ans=1;
	}
	if(ans==1){
		cout<<ans<<"\n";
		return ;
	}
	if(out[0]==in[0]){
		if(add[1]=add[2] ||(mul[1]==mul[2] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
	else if(in[1]==out[1]){
		if(add[0]=add[2] ||(mul[0]==mul[2] && mul[0]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;	
		}
	}
	else if(in[2]==out[2]){
		if(add[1]=add[0] ||(mul[1]==mul[0] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
*/
    else if (in[0]!=0 && out[0]%in[0]==0 && add[1]!=0 && add[2]!=0 && add[1]==add[2] && add[0]!=add[1])
        return true;
     else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[1]*in[0]-in[1]*out[0]!=0 && out[2]*in[0]-in[2]*out[0]!=0 && out[0]%in[0]==0 && (out[1]*in[0]-in[1]*out[0])%in[0]==0 && (out[2]*in[0]-in[2]*out[0])%in[0]==0 && (out[1]*in[0]-in[1]*out[0])/in[0]==(out[2]*in[0]-in[2]*out[0])/in[0])
        return true;
    else if (add[2]!=0 && in[1]+add[2]!=0 && out[1]%(in[1]+add[2])==0 && out[0]==in[0])
        return true;
    else if (add[1]!=0 && in[2]+add[1]!=0 && out[2]%(in[2]+add[1])==0 && out[0]==in[0])
        return true;
    else if (out[0]!=0 && add[1]!=0 && in[2]!=0 && out[2]!=0 && out[2]%in[2]==0 && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%out[2]==0 && (out[0]*in[2]-in[0]*out[2])/out[2]==add[1] && in[0]+add[1]!=0 && out[0]%(in[0]+add[1])==0 && out[0]/(in[0]+add[1])==out[2]/in[2])
        return true;
    else if (out[0]-out[2]!=0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[2]*in[0]-in[2]*out[0])%(out[0]-out[2])==0 && out[1]==in[1])
        return true;
    else if (out[1]-out[2]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%(out[1]-out[2])==0 && out[0]==in[0])
        return true;
    else if (in[0]!=0 && in[1]!=0 && add[2]!=0 && in[1]-in[0]!=0 && (out[0]-out[2]+in[2])%in[0]==0 && (out[1]-out[2]+in[2])%in[1]==0 && (out[0]-out[2]+in[2])/in[0]==(out[1]-out[2]+in[2])/in[1] && out[0]*in[1]-in[0]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%(in[1]-in[0])==0 && (out[0]*in[1]-in[0]*out[1])/(in[1]-in[0])==add[2])
        return true;
    else if (in[0]!=0 && in[2]!=0 && add[1]!=0 && in[2]-in[0]!=0 && (out[0]-out[1]+in[1])%in[0]==0 && (out[2]-out[1]+in[1])%in[2]==0 && (out[0]-out[1]+in[1])/in[0]==(out[2]-out[1]+in[1])/in[2] && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%(in[2]-in[0])==0 && (out[0]*in[2]-in[0]*out[2])/(in[2]-in[0])==add[1])
        return true;
    else if (add[1]!=0 && in[0]+add[1]!=0 && out[0]%(in[0]+add[1])==0 && out[2]==in[2])
        return true;
    else if (add[0]!=0 && in[1]+add[0]!=0 && out[1]%(in[1]+add[0])==0 && out[2]==in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && in[2]-in[0]!=0 && in[1]-in[0]!=0 && out[0]*in[1]-in[0]*out[1]!=0 && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[1]-in[0]*out[1])%(in[1]-in[0])==0 && (out[0]*in[2]-in[0]*out[2])%(in[2]-in[0])==0 && (out[0]*in[1]-in[0]*out[1])/(in[1]-in[0])==(out[0]*in[2]-in[0]*out[2])/(in[2]-in[0]) && (out[1]-out[0])%(in[1]-in[0])==0 && (out[2]-out[0])%(in[2]-in[0])==0 && (out[1]-out[0])/(in[1]-in[0])==(out[2]-out[0])/(in[2]-in[0]))
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]*in[2]-in[0]*out[2]!=0 && out[1]*in[2]-in[1]*out[2]!=0 && out[2]%in[2]==0 && (out[0]*in[2]-in[0]*out[2])%in[2]==0 && (out[1]*in[2]-in[1]*out[2])%in[2]==0 && (out[0]*in[2]-in[0]*out[2])/in[2]==(out[1]*in[2]-in[1]*out[2])/in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && out[0]%in[0]==0 && out[1]*in[0]-in[1]*out[0]!=0 && (out[1]*in[0]-in[1]*out[0])%in[0]==0 && out[2]==in[2])
        return true;
    
    /*
	int ans=3;
	if(in[1]==out[1] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[1]==out[1]){
		ans=1;
	}
	if(ans==1){
		cout<<ans<<"\n";
		return ;
	}
	if(out[0]==in[0]){
		if(add[1]=add[2] ||(mul[1]==mul[2] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
	else if(in[1]==out[1]){
		if(add[0]=add[2] ||(mul[0]==mul[2] && mul[0]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;	
		}
	}
	else if(in[2]==out[2]){
		if(add[1]=add[0] ||(mul[1]==mul[0] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
*/
    else if (add[2]!=0 && in[0]+add[2]!=0 && out[0]%(in[0]+add[2])==0 && out[1]==in[1])
        return true;
    else if (add[0]!=0 && in[2]+add[0]!=0 && out[2]%(in[2]+add[0])==0 && out[1]==in[1])
        return true;
    else if (in[1]!=0 && in[2]!=0 && out[1]!=0 && out[2]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]==out[2]/in[2] && out[0]*in[1]-in[0]*out[1]!=0 && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[1]-in[0]*out[1])%out[1]==0 && (out[0]*in[2]-in[0]*out[2])%out[2]==0 && (out[0]*in[1]-in[0]*out[1])/out[1]==(out[0]*in[2]-in[0]*out[2])/out[2])
        return true;
    else if (in[0]!=0 && in[2]!=0 && out[0]!=0 && out[2]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[2]/in[2] && out[1]*in[0]-in[1]*out[0]!=0 && out[1]*in[2]-in[1]*out[2]!=0 && (out[1]*in[0]-in[1]*out[0])%out[0]==0 && (out[1]*in[2]-in[1]*out[2])%out[2]==0 && (out[1]*in[0]-in[1]*out[0])/out[0]==(out[1]*in[2]-in[1]*out[2])/out[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && out[0]!=0 && out[1]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]==out[1]/in[1] && out[2]*in[0]-in[2]*out[0]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[0]-in[2]*out[0])%out[0]==0 && (out[2]*in[1]-in[2]*out[1])%out[1]==0 && (out[2]*in[0]-in[2]*out[0])/out[0]==(out[2]*in[1]-in[2]*out[1])/out[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && add[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]==out[1]/in[1])
        return true;
    else if (in[1]!=0 && out[1]%in[1]==0 && add[0]!=0 && add[2]!=0 && add[0]==add[2])
        return true;
    else if (in[2]!=0 && out[2]%in[2]==0 && add[0]!=0 && add[1]!=0 && add[0]==add[1])
        return true;
    
   
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[0]!=add[1] && add[1]==add[2]-out[0]+in[0])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]*in[1]-in[0]*out[1]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && out[1]%in[1]==0 && (out[0]*in[1]-in[0]*out[1])%in[1]==0 && (out[2]*in[1]-in[2]*out[1])%in[1]==0 && (out[0]*in[1]-in[0]*out[1])/in[1]==(out[2]*in[1]-in[2]*out[1])/in[1])
        return true;

    else if (in[1]!=0 && in[2]!=0 && add[0]!=0 && in[1]-in[2]!=0 && (out[1]-out[0]+in[0])%in[1]==0 && (out[2]-out[0]+in[0])%in[2]==0 && (out[1]-out[0]+in[0])/in[1]==(out[2]-out[0]+in[0])/in[2] && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%(in[1]-in[2])==0 && (out[2]*in[1]-in[2]*out[1])/(in[1]-in[2])==add[0])
        return true;
    else if (in[0]!=0 && add[1]!=0 && (out[0]-out[1]+in[1])%in[0]==0 && out[2]==in[2])
        return true;
    else if (in[0]!=0 && add[2]!=0 && (out[0]-out[2]+in[2])%in[0]==0 && out[1]==in[1])
        return true;
    else if (in[1]!=0 && add[0]!=0 && (out[1]-out[0]+in[0])%in[1]==0 && out[2]==in[2])
        return true;
    else if (in[1]!=0 && add[2]!=0 && (out[1]-out[2]+in[2])%in[1]==0 && out[0]==in[0])
        return true;
    else if (in[2]!=0 && add[0]!=0 && (out[2]-out[0]+in[0])%in[2]==0 && out[1]==in[1])
        return true;
    else if (in[2]!=0 && add[1]!=0 && (out[2]-out[1]+in[1])%in[2]==0 && out[0]==in[0])
        return true;
    else if (in[0]!=0 && add[1]!=0 && out[0]%in[0]==0 && out[2]==in[2] && add[0]!=add[1])
        return true;
    else if (in[0]!=0 && add[2]!=0 && out[0]%in[0]==0 && out[1]==in[1] && add[0]!=add[2])
        return true;
    /*
	int ans=3;
	if(in[1]==out[1] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[1]==out[1]){
		ans=1;
	}
	if(ans==1){
		cout<<ans<<"\n";
		return ;
	}
	if(out[0]==in[0]){
		if(add[1]=add[2] ||(mul[1]==mul[2] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
	else if(in[1]==out[1]){
		if(add[0]=add[2] ||(mul[0]==mul[2] && mul[0]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;	
		}
	}
	else if(in[2]==out[2]){
		if(add[1]=add[0] ||(mul[1]==mul[0] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
*/
    else if (out[1]!=0 && add[0]!=0 && in[2]!=0 && out[2]!=0 && out[2]%in[2]==0 && out[1]*in[2]-in[1]*out[2]!=0 && (out[1]*in[2]-in[1]*out[2])%out[2]==0 && (out[1]*in[2]-in[1]*out[2])/out[2]==add[0] && in[1]+add[0]!=0 && out[1]%(in[1]+add[0])==0 && out[1]/(in[1]+add[0])==out[2]/in[2])
        return true;
     else if (in[0]!=0 && in[2]!=0 && add[1]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[2]/in[2])
        return true;
    else if (in[1]!=0 && in[2]!=0 && add[0]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]==out[2]/in[2])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[0]!=add[2] && add[2]==add[1]-out[0]+in[0])
        return true;
    else if (out[0]!=0 && add[2]!=0 && in[1]!=0 && out[1]!=0 && out[1]%in[1]==0 && out[0]*in[1]-in[0]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%out[1]==0 && (out[0]*in[1]-in[0]*out[1])/out[1]==add[2] && in[0]+add[2]!=0 && out[0]%(in[0]+add[2])==0 && out[0]/(in[0]+add[2])==out[1]/in[1])
        return true;
    else if (out[2]!=0 && add[0]!=0 && in[1]!=0 && out[1]!=0 && out[1]%in[1]==0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%out[1]==0 && (out[2]*in[1]-in[2]*out[1])/out[1]==add[0] && in[2]+add[0]!=0 && out[2]%(in[2]+add[0])==0 && out[2]/(in[2]+add[0])==out[1]/in[1])
        return true;
    else if (in[1]!=0 && in[2]!=0 && out[1]%in[1]==0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%in[1]==0 && out[0]==in[0])
        return true;
    else if (in[0]!=0 && in[2]!=0 && out[2]%in[2]==0 && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%in[2]==0 && out[1]==in[1])
        return true;
    else if (in[0]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[2]*in[0]-in[2]*out[0])%in[0]==0 && out[1]==in[1])
        return true;
    else if (in[0]!=0 && add[1]!=0 && add[2]!=0 && add[1]==add[2] && (out[0]-out[2]+in[2])%in[0]==0 && (out[0]-out[1]+in[1])%in[0]==0 && (out[0]-out[2]+in[2])/in[0]==(out[0]-out[1]+in[1])/in[0])
        return true;
    else if (in[1]!=0 && add[0]!=0 && add[2]!=0 && add[0]==add[2] && (out[1]-out[2]+in[2])%in[1]==0 && (out[1]-out[0]+in[0])%in[1]==0 && (out[1]-out[2]+in[2])/in[1]==(out[1]-out[0]+in[0])/in[1])
        return true;
    else if (in[2]!=0 && add[0]!=0 && add[1]!=0 && in[0]-out[0]==in[1]-out[1] && (out[2]-out[1]+in[1])%in[2]==0 && (out[2]-out[0]+in[0])%in[2]==0 && (out[2]-out[1]+in[1])/in[2]==(out[2]-out[0]+in[0])/in[2])
        return true;
    else if (in[0]!=0 && out[0]%in[0]==0 && add[1]!=0 && add[2]!=0 && add[1]==add[2])
        return true;
    
    else if (add[1]!=0 && add[2]!=0 && add[1]!=add[2] && out[0]==in[0])
        return true;
    else if (out[0]-out[1]!=0 && out[0]-out[2]!=0 && in[0]-in[1]!=0 && in[0]-in[2]!=0 && out[1]*in[0]-out[0]*in[1]!=0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[1]*in[0]-out[0]*in[1])%(out[0]-out[1])==0 && (out[2]*in[0]-in[2]*out[0])%(out[0]-out[2])==0 && (out[1]*in[0]-out[0]*in[1])/(out[0]-out[1])==(out[2]*in[0]-in[2]*out[0])/(out[0]-out[2]) && (out[0]-out[1])%(in[0]-in[1])==0 && (out[0]-out[2])%(in[0]-in[2])==0 && (out[0]-out[1])/(in[0]-in[1])==(out[0]-out[2])/(in[0]-in[2]))
        return true;
    else if (add[2]!=0 && out[0]-out[1]!=0 && in[0]-in[1]!=0 && out[1]*in[0]-out[0]*in[1]!=0 && (out[1]*in[0]-out[0]*in[1])%(out[0]-out[1])==0 && (out[1]*in[0]-out[0]*in[1])/(out[0]-out[1])==add[2] && (out[0]-out[1])%(in[0]-in[1])==0)
        return true;
    
    else if (out[1]!=0 && add[2]!=0 && in[0]!=0 && out[0]!=0 && out[0]%in[0]==0 && out[1]*in[0]-in[1]*out[0]!=0 && (out[1]*in[0]-in[1]*out[0])%out[0]==0 && (out[1]*in[0]-in[1]*out[0])/out[0]==add[2] && in[1]+add[2]!=0 && out[1]%(in[1]+add[2])==0 && out[1]/(in[1]+add[2])==out[0]/in[0])
        return true;
    else if (out[2]!=0 && add[1]!=0 && in[0]!=0 && out[0]!=0 && out[0]%in[0]==0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[2]*in[0]-in[2]*out[0])%out[0]==0 && (out[2]*in[0]-in[2]*out[0])/out[0]==add[1] && in[2]+add[1]!=0 && out[2]%(in[2]+add[1])==0 && out[2]/(in[2]+add[1])==out[0]/in[0])
        return true;
    else if (in[2]!=0 && out[2]%in[2]==0 && add[0]!=0 && add[1]!=0 && add[0]==add[1] && add[0]!=add[2])
        return true;
   
    
    else if (in[1]!=0 && add[0]!=0 && out[1]%in[1]==0 && out[2]==in[2] && add[1]!=add[0])
        return true;
    else if (out[1]!=0 && add[0]!=0 && add[2]!=0 && add[0]==add[2] && in[1]+add[0]!=0 && in[1]+add[2]!=0 && out[1]%(in[1]+add[0])==0 && out[1]%(in[1]+add[2])==0 && out[1]/(in[1]+add[0])==out[1]/(in[1]+add[2]))
        return true;
    else if (out[2]!=0 && add[0]!=0 && add[1]!=0 && add[0]==add[1] && in[2]+add[0]!=0 && in[2]+add[1]!=0 && out[2]%(in[2]+add[0])==0 && out[2]%(in[2]+add[1])==0 && out[2]/(in[2]+add[0])==out[2]/(in[2]+add[1]))
        return true;
    else if (in[2]!=0 && out[2]!=0 && out[0]*in[2]-in[0]*out[2]!=0 && out[1]*in[2]-in[1]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%out[2]==0 && (out[1]*in[2]-in[1]*out[2])%out[2]==0 && (out[0]*in[2]-in[0]*out[2])/out[2]==(out[1]*in[2]-in[1]*out[2])/out[2] && out[2]%in[2]==0 && out[0]-out[1]!=0 && in[0]-in[1]!=0 && (out[0]-out[1])%(in[0]-in[1])==0 && (out[0]-out[1])/(in[0]-in[1])==out[2]/in[2])
        return true;
    else if (in[1]!=0 && out[1]!=0 && out[0]*in[1]-in[0]*out[1]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%out[1]==0 && (out[2]*in[1]-in[2]*out[1])%out[1]==0 && (out[0]*in[1]-in[0]*out[1])/out[1]==(out[2]*in[1]-in[2]*out[1])/out[1] && out[1]%in[1]==0 && out[0]-out[2]!=0 && in[0]-in[2]!=0 && (out[0]-out[2])%(in[0]-in[2])==0 && (out[0]-out[2])/(in[0]-in[2])==out[1]/in[1])
        return true;
    else if (in[1]!=0 && add[2]!=0 && out[1]%in[1]==0 && out[0]==in[0] && add[1]!=add[2])
        return true;
    else if (in[2]!=0 && add[0]!=0 && out[2]%in[2]==0 && out[1]==in[1] && add[0]!=add[2])
        return true;
     else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]*in[1]-in[0]*out[1]!=0 && out[0]*in[2]-in[0]*out[2]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]==out[2]/in[2] && (out[0]*in[1]-in[0]*out[1])%in[1]==0 && (out[0]*in[2]-in[0]*out[2])%in[2]==0 && (out[0]*in[1]-in[0]*out[1])/in[1]==(out[0]*in[2]-in[0]*out[2])/in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[1]*in[0]-in[1]*out[0]!=0 && out[1]*in[2]-in[1]*out[2]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[2]/in[2] && (out[1]*in[0]-in[1]*out[0])%in[0]==0 && (out[1]*in[2]-in[1]*out[2])%in[2]==0 && (out[1]*in[0]-in[1]*out[0])/in[0]==(out[1]*in[2]-in[1]*out[2])/in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[2]*in[0]-in[2]*out[0]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]==out[1]/in[1] && (out[2]*in[0]-in[2]*out[0])%in[0]==0 && (out[2]*in[1]-in[2]*out[1])%in[1]==0 && (out[2]*in[0]-in[2]*out[0])/in[0]==(out[2]*in[1]-in[2]*out[1])/in[1])
        return true;
    else if (in[2]!=0 && add[1]!=0 && out[2]%in[2]==0 && out[0]==in[0] && add[1]!=add[2])
        return true;
    else if (add[0]!=0 && in[1]-in[2]!=0 && out[1]-out[2]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%(out[1]-out[2])==0 && (out[2]*in[1]-in[2]*out[1])/(out[1]-out[2])==add[0] && (out[1]-out[2])%(in[1]-in[2])==0)
        return true;
    else if (out[0]!=0 && add[1]!=0 && add[2]!=0 && add[1]==add[2] && in[0]+add[1]!=0 && in[0]+add[2]!=0 && out[0]%(in[0]+add[1])==0 && out[0]%(in[0]+add[2])==0 && out[0]/(in[0]+add[1])==out[0]/(in[0]+add[2]))
        return true;
    
    else if (in[0]!=0 && out[0]!=0 && out[1]*in[0]-in[1]*out[0]!=0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[1]*in[0]-in[1]*out[0])%out[0]==0 && (out[2]*in[0]-in[2]*out[0])%out[0]==0 && (out[1]*in[0]-in[1]*out[0])/out[0]==(out[2]*in[0]-in[2]*out[0])/out[0] && out[0]%in[0]==0 && out[1]-out[2]!=0 && in[1]-in[2]!=0 && (out[1]-out[2])%(in[1]-in[2])==0 && (out[1]-out[2])/(in[1]-in[2])==out[0]/in[0])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[0]==add[1] && add[0]!=add[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && add[2]!=0 && out[0]%in[0]==0 && (out[1]-out[2]+in[2])%in[1]==0 && out[0]/in[0]==(out[1]-out[2]+in[2])/in[1] && out[1]*in[0]-in[1]*out[0]!=0 && (out[1]*in[0]-in[1]*out[0])%in[0]==0 && add[2]==(out[1]*in[0]-in[1]*out[0])/in[0])
        return true;
    else if (in[0]!=0 && in[2]!=0 && add[1]!=0 && out[2]%in[2]==0 && (out[0]-out[1]+in[1])%in[0]==0 && out[2]/in[2]==(out[0]-out[1]+in[1])/in[0] && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%in[2]==0 && add[1]==(out[0]*in[2]-in[0]*out[2])/in[2])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[0]==add[2] && add[0]!=add[1])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[1]==add[2] && add[1]!=add[0])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[0]!=add[1] && out[2]==in[2])
        return true;
    else if (add[0]!=0 && add[2]!=0 && add[0]!=add[2] && out[1]==in[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[1]-in[0]!=0 && out[0]*in[1]-in[0]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%(in[1]-in[0])==0 && (out[1]-out[0])%(in[1]-in[0])==0 && out[2]==in[2])
        return true;
    else if (in[0]!=0 && in[2]!=0 && in[2]-in[0]!=0 && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%(in[2]-in[0])==0 && (out[2]-out[0])%(in[2]-in[0])==0 && out[1]==in[1])
        return true;
    else if (in[1]!=0 && in[2]!=0 && in[2]-in[1]!=0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%(in[2]-in[1])==0 && (out[2]-out[1])%(in[2]-in[1])==0 && out[0]==in[0])
        return true;
    
    else if (in[0]!=0 && in[2]!=0 && add[1]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[2]/in[2])
        return true;
    else if (in[1]!=0 && in[2]!=0 && add[0]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]==out[2]/in[2])
        return true;
    
    else if (in[1]!=0 && out[1]!=0 && out[1]%in[1]==0 && out[0]*in[1]-in[0]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%out[1]==0 && out[2]==in[2])
        return true;
    else if (in[2]!=0 && out[2]!=0 && out[2]%in[2]==0 && out[0]*in[2]-in[0]*out[2]!=0 && (out[0]*in[2]-in[0]*out[2])%out[2]==0 && out[1]==in[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && add[2]!=0 && out[1]%in[1]==0 && (out[0]-out[2]+in[2])%in[0]==0 && out[1]/in[1]==(out[0]-out[2]+in[2])/in[0] && out[0]*in[1]-in[0]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%in[1]==0 && add[2]==(out[0]*in[1]-in[0]*out[1])/in[1])
        return true;
    
    
    else if (in[0]!=0 && out[0]!=0 && out[0]%in[0]==0 && out[2]*in[0]-in[2]*out[0]!=0 && (out[2]*in[0]-in[2]*out[0])%out[0]==0 && out[1]==in[1])
        return true;
    else if (in[1]!=0 && out[1]!=0 && out[1]%in[1]==0 && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%out[1]==0 && out[0]==in[0])
        return true;
    /*
	int ans=3;
	if(in[1]==out[1] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[1]==out[1]){
		ans=1;
	}
	if(ans==1){
		cout<<ans<<"\n";
		return ;
	}
	if(out[0]==in[0]){
		if(add[1]=add[2] ||(mul[1]==mul[2] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
	else if(in[1]==out[1]){
		if(add[0]=add[2] ||(mul[0]==mul[2] && mul[0]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;	
		}
	}
	else if(in[2]==out[2]){
		if(add[1]=add[0] ||(mul[1]==mul[0] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
*/
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]!=out[1]/in[1] && out[1]*in[2]!=0 && (out[2]*in[1])%(out[1]*in[2])==0 && out[0]/in[0]==(out[2]*in[1])/(out[1]*in[2]))
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[1]/in[1] && out[0]/in[0]!=out[2]/in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[0]/in[0]!=out[1]/in[1] && out[0]/in[0]==out[2]/in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]==out[2]/in[2] && out[0]/in[0]!=out[2]/in[2])
        return true;
    else if (in[0]!=0 && in[1]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]!=out[1]/in[1] && out[2]==in[2])
        return true;
    else if (in[0]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]!=out[2]/in[2] && out[1]==in[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[2]%in[2]==0 && out[1]%in[1]==0 && out[2]/in[2]!=out[1]/in[1] && out[1]*in[0]!=0 && (out[0]*in[1])%(out[1]*in[0])==0 && out[2]/in[2]==(out[0]*in[1])/(out[1]*in[0]))
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[2]%in[2]==0 && out[0]%in[0]==0 && out[2]/in[2]!=out[0]/in[0] && in[1]*out[0]!=0 && (out[1]*in[0])%(in[1]*out[0])==0 && out[2]/in[2]==(out[1]*in[0])/(in[1]*out[0]))
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[1]%in[1]==0 && out[0]%in[0]==0 && out[1]/in[1]!=out[0]/in[0] && in[2]*out[0]!=0 && (out[2]*in[0])%(in[2]*out[0])==0 && out[1]/in[1]==(out[2]*in[0])/(in[2]*out[0]))
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[0]!=add[2] && add[0]==add[1]-out[2]+in[2])
        return true;
    
    else if (in[1]!=0 && in[2]!=0 && add[0]!=0 && out[2]%in[2]==0 && (out[1]-out[0]+in[0])%in[1]==0 && out[2]/in[2]==(out[1]-out[0]+in[0])/in[1] && out[1]*in[2]-in[1]*out[2]!=0 && (out[1]*in[2]-in[1]*out[2])%in[2]==0 && add[0]==(out[1]*in[2]-in[1]*out[2])/in[2])
        return true;
    else if (in[1]!=0 && in[2]!=0 && add[0]!=0 && out[1]%in[1]==0 && (out[2]-out[0]+in[0])%in[2]==0 && out[1]/in[1]==(out[2]-out[0]+in[0])/in[2] && out[2]*in[1]-in[2]*out[1]!=0 && (out[2]*in[1]-in[2]*out[1])%in[1]==0 && add[0]==(out[2]*in[1]-in[2]*out[1])/in[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && add[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]==out[1]/in[1])
        return true;
    else if (in[0]!=0 && out[0]!=0 && out[0]%in[0]==0 && out[1]*in[0]-in[1]*out[0]!=0 && (out[1]*in[0]-in[1]*out[0])%out[0]==0 && out[2]==in[2])
        return true;
    else if (in[2]!=0 && out[2]!=0 && out[2]%in[2]==0 && out[1]*in[2]-in[1]*out[2]!=0 && (out[1]*in[2]-in[1]*out[2])%out[2]==0 && out[0]==in[0])
        return true;
    else if (in[0]!=0 && add[1]!=0 && out[0]%in[0]==0 && out[2]==in[2] && add[0]!=add[1])
        return true;
    
    else if (in[1]!=0 && in[2]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]!=out[2]/in[2] && out[0]==in[0])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]!=out[2]/in[2] && out[2]*in[1]!=0 && (out[1]*in[2])%(out[2]*in[1])==0 && out[0]/in[0]==(out[1]*in[2])/(out[2]*in[1]))
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[1]!=add[2] && add[1]==add[0]-out[2]+in[2])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[1]!=add[2] && add[2]==add[0]-out[1]+in[1])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[1]!=add[0] && add[0]==add[2]-out[1]+in[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && out[1]%in[1]==0 && out[0]*in[1]-in[0]*out[1]!=0 && (out[0]*in[1]-in[0]*out[1])%in[1]==0 && out[2]==in[2])
        return true;
    
    else if (in[1]!=0 && add[0]!=0 && out[1]%in[1]==0 && out[2]==in[2] && add[0]!=add[1])
        return true;
    else if (in[2]!=0 && add[0]!=0 && out[2]%in[2]==0 && out[1]==in[1] && add[0]!=add[2])
        return true;
    else if (in[0]!=0 && in[2]!=0 && add[1]!=0 && out[0]%in[0]==0 && (out[2]-out[1]+in[1])%in[2]==0 && out[0]/in[0]==(out[2]-out[1]+in[1])/in[2] && out[2]*in[0]-in[2]*out[0]!=0 && (out[2]*in[0]-in[2]*out[0])%in[0]==0 && add[1]==(out[2]*in[0]-in[2]*out[0])/in[0])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]!=out[2]/in[2] && out[2]*in[0]!=0 && (out[0]*in[2])%(out[2]*in[0])==0 && out[1]/in[1]==(out[0]*in[2])/(out[2]*in[0]))
        return true;
    else if (in[2]!=0 && add[1]!=0 && out[2]%in[2]==0 && out[0]==in[0] && add[1]!=add[2])
        return true;
    else if (in[0]!=0 && add[2]!=0 && out[0]%in[0]==0 && out[1]==in[1] && add[0]!=add[2])
        return true;
    else if (in[1]!=0 && add[2]!=0 && out[1]%in[1]==0 && out[0]==in[0] && add[1]!=add[2])
        return true;

    return false;
}

bool check_one(){
	if (add[0]!=0 && add[1]!=0 && add[2]!=0 && add[0]==add[1] && add[1]==add[2])
        return true;
    else if (in[0]!=0 && out[0]%in[0]==0 && out[1]==in[1] && out[2]==in[2])
        return true;
    else if (in[1]!=0 && out[1]%in[1]==0 && out[0]==in[0] && out[2]==in[2])
        return true;
    else if (add[0]!=0 && add[1]!=0 && add[0]==add[1] && out[2]==in[2])
        return true;
    else if (in[0]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[2]/in[2] && out[1]==in[1])
        return true;
    /*
	int ans=3;
	if(in[1]==out[1] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[1]==out[1]){
		ans=1;
	}
	if(ans==1){
		cout<<ans<<"\n";
		return ;
	}
	if(out[0]==in[0]){
		if(add[1]=add[2] ||(mul[1]==mul[2] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
	else if(in[1]==out[1]){
		if(add[0]=add[2] ||(mul[0]==mul[2] && mul[0]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;	
		}
	}
	else if(in[2]==out[2]){
		if(add[1]=add[0] ||(mul[1]==mul[0] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
*/
 
    else if (in[1]!=0 && in[2]!=0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[1]/in[1]==out[2]/in[2] && out[0]==in[0])
        return true;
    
    else if (add[0]!=0 && add[2]!=0 && add[0]==add[2] && out[1]==in[1])
        return true;
    else if (in[0]!=0 && in[1]!=0 && in[2]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[2]%in[2]==0 && out[0]/in[0]==out[1]/in[1] && out[1]/in[1]==out[2]/in[2])
        return true;
    
    else if (out[0]==in[0] && out[1]==in[1] && add[2]!=0)
        return true;
    else if (in[2]!=0 && out[2]%in[2]==0 && out[0]==in[0] && out[1]==in[1])
        return true;
    else if (add[1]!=0 && add[2]!=0 && add[1]==add[2] && out[0]==in[0])
        return true;
    else if (out[1]==in[1] && out[2]==in[2] && add[0]!=0)
        return true;
    else if (in[0]!=0 && in[1]!=0 && out[0]%in[0]==0 && out[1]%in[1]==0 && out[0]/in[0]==out[1]/in[1] && out[2]==in[2])
        return true;
    

    else if (out[0]==in[0] && out[2]==in[2] && add[1]!=0)
        return true;

    return false;
}

void solve(){

	int p,q,r,a,b,c;
	cin>>p>>q>>r;
	cin>>a>>b>>c;

	in[0]=p;
	in[1]=q;
	in[2]=r;
	out[0]=a;
	out[1]=b;
	out[2]=c;

	if(a==p && b==q && r==c){
		cout<<"0\n";
		return ;
	}
	if(a==b && b==c){
		cout<<"1\n";
		return;
	}

	int d1=a-p;
	int d2=b-q;
	int d3=c-r;

	//int qwe[3]={d1,d2,d3};
	add[0]=d1;
	add[1]=d2;
	add[2]=d3;

	pro[0]=1LL*a*p;
	pro[1]=1LL*b*q;
	pro[2]=1LL*c*r;

	if(d1==d2 && d2==d3){
		cout<<"1\n";
		return;
	}

	int c1=(p!=0 && a%p==0)?a/p:INT_MIN;
	int c2=(q!=0 && b%q==0)?b/q:INT_MIN;
	int c3=(r!=0 && c%r==0)?c/r:INT_MIN;
	
	//mul={c1,c2,c3};
	mul[0]=c1;
	mul[1]=c2;
	mul[2]=c3;

	if(c1==c2 && c2==c3 && c1 !=INT_MIN){
		cout<<"1\n";
		return ;
	}

	/* Subsets are : - (7) for one operation.
	001
	010
	100
	110
	101
	011
	111
	*/
	/*
	int ans=3;
	if(in[1]==out[1] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[2]==out[2]){
		ans=1;
	}
	else if(in[0]==out[0] && in[1]==out[1]){
		ans=1;
	}
	if(ans==1){
		cout<<ans<<"\n";
		return ;
	}
	if(out[0]==in[0]){
		if(add[1]=add[2] ||(mul[1]==mul[2] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
	else if(in[1]==out[1]){
		if(add[0]=add[2] ||(mul[0]==mul[2] && mul[0]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;	
		}
	}
	else if(in[2]==out[2]){
		if(add[1]=add[0] ||(mul[1]==mul[0] && mul[1]!=INT_MIN)){
			ans=1;
			cout<<ans<<"\n";
			return;
		}
	}
*/
	if(check_one()){
		cout<<"1\n";
		return;
	}
	if(check_two()){
		cout<<"2\n";
		return ;
	}
	cout<<"3\n";
	return ;
}

int main()
{	
	int t;
	cin>>t;

	for(int i=0;i<t;i++){
		solve();
	}
    return 0;
}