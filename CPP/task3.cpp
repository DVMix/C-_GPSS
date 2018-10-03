#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;
int main()
{
	int a,i;
	double p[4],
		   ro[4],
		   lam[4],
		   mu0,mu1,mu2,mu3;

	lam[0]=0.25;mu0=1.;
	mu1=mu0;mu2=mu0;mu3=1.5*mu0;
	lam[1]=lam[0];lam[2]=0.5*lam[1];lam[3]=(0.5*lam[1])+lam[2];
	cout<<"lambda========================\n";
	cout<<lam[1]<<"\t"<<lam[2]<<"\t"<<lam[3]<<"\n";
	cout<<"mu============================\n";
	cout<<mu1<<"\t"<<mu2<<"\t"<<mu3<<"\n";
	cout<<"ro============================\n";
	ro[1]=lam[1]/mu1; cout<<ro[1]<<"\t";
	ro[2]=lam[2]/mu2; cout<<ro[2]<<"\t";
	ro[3]=lam[3]/mu3; cout<<ro[3]<<"\n";

	cout<<"Pi============================\n";
	p[1]=1-ro[1]; cout<<p[1]<<"\t";
	p[2]=1-ro[2]; cout<<p[2]<<"\t";
	p[3]=1-ro[3]; cout<<p[3]<<"\n";

	double pp[4][4];

	cout<<"PP============================\n";

	for(i=1;i<4;i++)
	{
		for(int j=1;j<4;j++)
		{
			pp[i][j]=pow(ro[i],j)*p[i];
			cout<<pp[i][j]<<"\t";
		}cout<<"\n";
	}

	double N[4], NN,U[4], UU,tmp;
	cout<<"Ni============================\n";
	for(int k=1;k<4;k++)
	{
		tmp=0;
		for(int j=1;j<3;j++)
		{
			tmp+=j*pp[k][j+1];
		}
		N[k]=pp[k][1]+tmp;
		cout<<N[k]<<"\t";
	}
	cout<<endl;
	cout<<"NN============================\n";
	NN=N[1]+N[2]+N[3];
	cout<<NN<<endl;
	cout<<"Ui============================\n";
	for(i=1;i<4;i++)
	{
		U[i]=N[i]/lam[i];
		cout<<U[i]<<"\t";
	}cout<<endl;
	cout<<"UU============================\n";
	UU=((U[1]+U[2]+U[3])+(U[1]+U[3]))/2;
	cout<<UU<<endl;
	return 0;
}
