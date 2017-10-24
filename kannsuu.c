#include<stdio.h>
#include<math.h>
void setbuf(FILE *fp,char *buff);
int keta(float d){
	int k;
	k=floor( log10(d));
	return k;
}
double kansuu(char c ){
	float si,co,ta,v=0,v2,k;
	float s,c1,t;
	int count;
puts("		4");	
	if(c>=48&&c<=57){
		v=c-48;
		printf("%f\n",v);
puts("		5");
		scanf("%f",&v2);
puts("		5.2");		
		printf("%f\n",v2);
puts("		5.5");		
		k=v*(10*(keta(v2)+1))+v2;
		printf("%f\n",k);
puts("		6");		
		return k;
	}
	else if(c=='s'){
puts("		7");		
		scanf("%f",&si);
		printf("%f\n",si);
		s=sinf(si);
		printf("%f\n",s);
		return s;
		}
	else if(c=='c'){
puts("		8");		
		scanf("%f",&co);
		c1=cos(co);
		return c1;
		}
	else if(c=='t'){
puts("		9");
		scanf("%f",&ta);
		t=tan(ta);
		return t;
		}
	getchar();

		
}

int main(void){
	system("clear");
	FILE *fp;
	char *buff;

	char sw,a=0,c,*keta;
	double ans;
	float i,t,c1;
	scanf ("%f%c%f",&i,&sw,&t);
	getchar();
	switch(sw){	
		case'+': ans=i+t;break;
		case'-': ans=i-t;break;
		case'*': ans=i*t;break;
		case'/':{
			if(i==0){puts("バカ");return 0;}
			ans=i/t;
			break;
		}
	}
		while(1){
			printf("%lf\n",ans);
			scanf("%c",&sw);
			if(sw=='\n'){break;}
puts("		1");			
				scanf("%c",&c);	
puts("		2");				
				t=kansuu(c);
				printf("%f\n",t);
puts("		3");				

			
			switch(sw){
				case'+':{ ans+=t;break;}
				case'-':{ ans-=t;break;}
				case'*':{ ans*=t;break;}
				case'/':{ ans/=t;break;}
			}
			getchar();
		}
		printf("%lf",ans);
		return 0;
}
	
