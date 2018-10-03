#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int main()
{
	int n,i,flag,v=2;
	double j,rho=1.5,k1,k2,p0,pv,pk,sum=0,sum1,lam=3,mu=2,w=0;
	for(i=1;i<=10;i++)
	{
		j=0.0005*i;
		cout<<"J="<<j<<"\n";
		k1=rho;
		k2=0.5*rho*rho;
		sum=0;
		sum=1+k1+k2;
		p0=1/sum;
		pv=k2*p0;
		n=1;
		cout<<sum<<"\t"<<pv<<endl;
		system("PAUSE");
		 do{
		 	sum1=pow(0.5,n+1)*pow(rho,n+2);
			sum+=sum1;
		 	p0=1/sum;
		 	pv=k2*p0;
			pk=p0*sum1;
		 	cout<<n<<"\t"<<sum<<"\t"<<pk<<endl;//system("PAUSE");
		 	if(pk>j)
		 	{
		 		n++;
		 	} 
			//system("PAUSE");
		 }while(pk>=j);
		 cout<<"R="<<n<<endl;
		 //n=2;
		 w=(pv/(1-pk))*((v*mu-(pow(rho/v,n)*((n+1)*v*mu-n*lam)))/(pow(v*mu-lam,2)));
		 cout<<"W="<<w<<"\t"<<j<<endl<<endl;
		 
	}
	return 0;
}
