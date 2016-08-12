#include<iostream>
#include<stdio.h>
#include<cstring>
typedef long long ll;
const int maxn=1e6;
int f[maxn+10],add[maxn+10];
int prime[maxn/10],e[maxn],div_num[maxn];
bool flag[maxn];  
void get_prime()  {  
    int k=0;
    div_num[1]=1;
    for(int i=2;i<maxn;i++){
        if(!flag[i]){                         
            prime[k++]=i;
			e[i]=1;
			div_num[i]=2;
        }
		for(int j=0;j<k&&i*prime[j]<maxn;j++){
			flag[i*prime[j]]=true;        
            if(i%prime[j]==0){
            	div_num[i*prime[j]]=div_num[i]/(e[i]+1)*(e[i]+2);
            	e[i*prime[j]]=e[i]+1;
            	break;
            }
        	else{
            	div_num[i*prime[j]]=div_num[i]*div_num[prime[j]];
        		e[i*prime[j]]=1;
            }
        }
    }
} 
int factor[300][2];
int getFactors(int x){
	int fatCnt = 0;
	int tmp = x;
	for (int i = 0;prime[i] <= tmp / prime[i];i++){
		factor[fatCnt][1] = 0;
		if (tmp%prime[i] == 0){
			factor[fatCnt][0] = prime[i];
			while (tmp%prime[i] == 0){
				factor[fatCnt][1]++;
				tmp /= prime[i];
			}
			fatCnt++;
		}
	}
	if (tmp != 1){
		factor[fatCnt][0] = tmp;
		factor[fatCnt++][1] = 1;
	}
	return fatCnt;
}
int read(){
	int ans=0;
	char last=' ',ch=getchar();
	while(ch<'0' || ch>'9')last=ch,ch=getchar();
	while(ch>='0' && ch<='9')ans=ans*10+ch-'0',ch=getchar();
	if(last=='-')ans=-ans;
	return ans;
}
ll ans,tot,limit=10000;
void dfs(int pos,int sum,int x){
	if(sum>limit) return;
	if(pos==tot){
		ans+=div_num[x/sum]*add[sum];
		return;
	}
	dfs(pos+1,sum,x);
	for(int i=0;i<factor[pos][1];i++){
		sum*=factor[pos][0];
		dfs(pos+1,sum,x);
	}
}
int main(){
	get_prime();
	int n,q,cmd,x,y;
	n=read(); q=read();
	while(q--){
		cmd=read();
		if(cmd==1){
			x=read(); y=read();
			if(x<=limit) add[x]+=y;
			else{
				for(int i=1;i*x<=n;i++){
					f[i*x]+=div_num[i]*y;
				}
			}
		}else{
			x=read();
			if(x>limit) ans=f[x];
			else ans=0;
			tot=getFactors(x);
			dfs(0,1,x);
			printf("%lld\n",ans);
		}
	}
	return 0;
}