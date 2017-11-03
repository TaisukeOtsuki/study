#include<stdio.h>
#include<math.h>
#include<string.h> 
#define PI 3.1415926

char ope[40];
double c[80];
double c2[80];

void keta(char a[80]){
	int i=0,t=0,p,adre,lo;
	int si=0,co=0,ta=0,ka=0,waru,nt,period=0,arc=0;
	float dammy;
	double syo;
	for(;;){
		if(a[t+1]>=48&&a[t+1]<=57){nt=1;}
		else{nt=0;}
		if(a[t+1]=='.'){nt=1;}
		if(a[t]=='.'){nt=1;}
		if(period>0){period++;}
		if(a[t]=='.'){period++;t++;}
		if(a[t]>=48&&a[t]<=57){	
			if(period==0){c[i]=c[i]*10+a[t]-48;}
			else{
				syo=0;
				syo=a[t]-48;
				syo/=(10*period);
				c[i]=c[i]+syo;}
		}		
		else if(a[t]=='.'){}
		else if(a[t]=='\0'){period=0;}
		else{
			i++;
		}
		if(arc==0&&si==1&&nt==0&&period==0){
			c[i]=sin(c[i]/180*PI);
			si=0;
		}
		if(arc==0&&co==1&&nt==0&&period==0){
			c[i]=cos(c[i]/180*PI);
			co=0;
		}
		if(arc==0&&ta==1&&nt==0&&period==0){
			c[i]=tan(c[i]/180*PI);
			ta=0;
		}
		
		if(arc==1&&si==1&&nt==0&&period==0){
			c[i]=asin(c[i]);
			c[i]*=180;
			c[i]/=PI;
			dammy=c[i];
			c[i]=dammy;
			si=0;
			arc=0;
		}
		if(arc==1&&co==1&&nt==0&&period==0){
			c[i]=acos(c[i]);
			c[i]*=180;
			c[i]/=PI;
			dammy=c[i];
			c[i]=dammy;
			co=0;
			arc=0;
		}
		if(arc&&ta&&!nt&&!period){
			c[i]=atan(c[i]);
			c[i]*=180;
			c[i]/=PI;
			dammy=c[i];
			c[i]=dammy;
			ta=0;
			arc=0;
		}
		if(ka==1&&nt==0){
			c[i-1]=c[i-1]*c[i];
			ka=0;
			c[i]=0;
			i--;
		}
		if(waru==1&&nt==0){
			c[i-1]=c[i-1]/c[i];
			waru=0;
			c[i]=0;
			i--;
		}
		switch(a[t]){
			case'a':arc=1;period=0;i--;break;
			case's':si=1; period=0;i--;break;
			case'c':co=1; period=0;i--;break;
			case't':ta=1; period=0;i--;break;
			case'*':ka=1; period=0;break;
			case'/':waru=1; period=0;break;
		}
	if(a[t]=='\0'){break;}
		t++;
		
	}
	i++;
	c[i]='\0';
	return ;
}
void moji(char a[80]){

	int i=0,t=0,p=0,m=0;
	if(a[0]=='-'){t++;}

	while(a[t]!='\0'){

	if(!(a[t]>=48&&a[t]<=57)){
		if(a[t]=='+'){
			ope[p]=a[t];
			p++;
		}
		if(a[t]=='-'){
			ope[p]=a[t];
			p++;
		}
	}
	t++;
	}
	switch(ope[m]){
		case'+':{
			c[i]+=c[m+1];
			c[m+1]=0;
			m++;
			}
		case'-':{
			if(c[0]<0){puts("unko");}
			c[i]-=c[m+1];
			c[m+1]=0;
			m++;
			}
	}
	t++;
	return ;
}
int main(void){
	char a[80],ope[40],x;
	int i=0,t=0;
	double ans;
puts("：＋、：ー、：/　、：＊、end：a");
puts(":　ｓ〜、ｃ〜、ｔ〜");
puts(":　as~,ac~,at~");
	while(1){

	scanf("%c",&x);
	while(x!='\n'){
		a[t]=x;
		scanf("%c",&x);
		t++;
		
	}
	a[t]='\0';
	if(a[t-1]=='a'){break;}
	i=t;
	t=0;
	keta(a);
	moji(a);
	ans=c[0];
puts("end");	
	printf("answer=%lf\n",ans);
	}
	return 0;
}
