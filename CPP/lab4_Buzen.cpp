#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int i,j,M=3,N=50,v,mu[3];
	
	double d[4],p[3],h[3],teta[3][3],g[M+1][N+1],lam[4],UTIL[4],EX[4];

	teta[0][0]=0.9;
	teta[0][1]=(1-teta[0][0])/2;
	teta[0][2]=(1-teta[0][0])/2;

	teta[1][0]=1;
	teta[1][1]=0;
	teta[1][2]=0;

	teta[2][0]=1;
	teta[2][1]=0;
	teta[2][2]=0;

	mu[0]=10;
	mu[1]=1;mu[2]=1;
	
	
	for(i=0;i<M;i++) 
	{
		for(j=0;j<M;j++)
		{
			cout<<teta[i][j]<<"\t";
		}
		cout<<"\n";
	}
	h[0]=teta[0][0];
	h[1]=teta[0][1];	
	h[2]=teta[0][2];
	
	cout<<"\nh=("<<h[0]<<"; "<<h[1]<<"; "<<h[2]<<");";
	for(i=1;i<=M;i++)
	{
		d[i]=h[i-1]/mu[i-1];
	}cout<<"\nd=("<<d[1]<<"; "<<d[2]<<"; "<<d[3]<<");\n\n";
	
	
	for(i=0;i<=M;i++)
	{
		for(j=0;j<=N;j++)
		{
			if(j==0)
			{
				g[i][j]=1;
			}
			else
			{
				g[i][j]=0;
			}
			//cout<<g[i][j]<<"\t";
		}//cout<<"\n";
	}
	for(i=1;i<=M;i++)
	{
		for(j=1;j<=N;j++)
		{
			g[i][j]=g[i-1][j]+d[i]*g[i][j-1];
			//cout<<g[i][j]<<endl;
		}//cout<<endl;
	}cout<<endl;
	
	cout<<"G{M,N}="<<g[M][N]<<endl<<endl;

	for(i=1;i<=M;i++)
	{
		lam[i]=h[i-1]*(g[M][N-1]/g[M][N]);
	}cout<<endl;

	for(i=1;i<=M;i++)
	{
		UTIL[i]=lam[i]/mu[i-1];
		cout<<"UTIL["<<i<<"]="<<UTIL[i]<<endl;
	}cout<<endl;
	for(i=1;i<=M;i++)
	{
		cout<<"TH["<<i<<"]="<<lam[i]<<endl;
	}cout<<endl;
	for(i=1;i<=M;i++)
	{
		double sum=0;
		for(j=1;j<=N;j++)
		{
			sum+=pow(d[i],j)*g[M][N-j];
		}
		EX[i]=sum/g[M][N];
		cout<<"EX["<<i<<"]="<<EX[i]<<endl;
	}
	cout<<"TH=lam2+lam3="<<lam[2]+lam[3]<<endl;;
	
	return 0;
}



