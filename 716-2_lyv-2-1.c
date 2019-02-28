#include <stdio.h>
int main(){
	int n,y=1,a,b,prov=1;
	scanf("%d",&n);
	scanf("%d",&a);
	while(y<=n-1){
		scanf("%d",&b);
		if(a<=b)prov++;
		a=b;
		y++;
		};
	if(prov==n) printf("\n%d\n",1);
	else printf("\n%d\n",0);
	return 0;
}
