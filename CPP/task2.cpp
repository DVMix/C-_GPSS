#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int K=3,i,j,k;
	double E,D,p1=0,p2=0,p3=0,lam,mu[4],pp1,pp2,pp3;

	for (i=1;i<K+1;i++)
	{
		mu[i]=10;
	}
	
	for(lam=1;lam<=7;lam++)
	{
		p1=0;p2=0;p3=0;
		pp1=0;pp2=0;pp3=0;
		
		for (i=1;i<K+1;i++)
		{
			p1+=1/(mu[i]-lam);
		}//cout<<p1<<endl;
		
		
		for(i=1;i<K+1;i++)
		{
			for(j=1;j<K+1;j++)
			{
				if(j!=i)
				{
					//cout<<"i="<<i<<"  j="<<j<<endl;
					p2+=1/(mu[i]+mu[j]-2*lam);
					//cout<<p2<<endl;
				}
			}
			//cout<<p2<<endl;
		}
		for(i=1;i<K+1;i++)
		{
			for(j=1;j<K+1;j++)
			{
				if(j!=i)
				{
					for(k=1;k<K+1;k++)
					{
						if(k!=i)
						{
							if(k!=j)
							{
								//cout<<"i="<<i<<"  j="<<j<<"   k="<<k<<endl;
								p3+=1/(mu[i]+mu[j]+mu[k]-3*lam);
								//cout<<p3<<endl;
							}
						}
						
					}
				}
				
			}
		}
		
		E=p1-p2+p3;cout<<"E="<<E<<endl;
		for (i=1;i<K+1;i++)
		{
			pp1+=2/pow(mu[i]-lam,2);
		}//cout<<p1<<endl;
		
		
		for(i=1;i<K+1;i++)
		{
			for(j=1;j<K+1;j++)
			{
				if(j!=i)
				{
					//cout<<"i="<<i<<"  j="<<j<<endl;
					pp2+=2/pow(mu[i]+mu[j]-2*lam,2);
					//cout<<p2<<endl;
				}
			}
			//cout<<p2<<endl;
		}
		for(i=1;i<K+1;i++)
		{
			for(j=1;j<K+1;j++)
			{
				if(j!=i)
				{
					for(k=1;k<K+1;k++)
					{
						if(k!=i)
						{
							if(k!=j)
							{
								//cout<<"i="<<i<<"  j="<<j<<"   k="<<k<<endl;
								pp3+=2/pow(mu[i]+mu[j]+mu[k]-3*lam,2);
								//cout<<p3<<endl;
							}
						}
						
					}
				}
				
			}
		}
		
		D=pp1-pp2+pp3-pow(E,2);cout<<"D="<<D<<endl<<endl;;
	}
	return 0;
}
