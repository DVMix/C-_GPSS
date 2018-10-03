#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<math.h>
using namespace std;

int sochet(int n , int m)
{
	long long int i,n_fact=1,m_fact=1,nm_fact=1;
	double factorial;
	for(i=1;i<n+1;i++)
	{
		n_fact=n_fact*i;
	}//cout<<"fact="<<n_fact<<endl;
	for(i=1;i<m+1;i++)
	{
		m_fact=m_fact*i;
	}//cout<<"fact="<<m_fact<<endl;
	for(i=1;i<n-m+1;i++)
	{
		nm_fact=nm_fact*i;
	}//cout<<"fact="<<nm_fact<<endl;
	factorial=n_fact/(m_fact*nm_fact);
	//cout<<"fact="<<factorial<<endl;
}

int main()
{
	int n,i,j,flag;
	double rho,e,b;
	//cout<<sochet(600,20)<<endl;
	ofstream t1("task1.txt");
	for(j=1;j<=1;j++)
	{
	
		rho=100;
		flag=0;
		e=1;
		i=1;
		//cout<<j<<endl;
		b=0.01*j;
		
		do{
			e=(rho*e)/(i+rho*e);
			if(e<=b)
			{
				n=i;
				flag=1;
			}
			else
			{
				i++;
			}
		}while(flag!=1);
		cout<<"B="<<b<<"\nNumber of V1="<<n<<endl;
		t1<<b<<"\t"<<n<<"\t";
	
		//system("PAUSE");
		//*e=1;
		for(int k=0;k<2;k++)
		{
			rho=15;
			t1<<rho<<"\t";
			e=1;
			for(i=1;i<=20;i++)
			{
				e=(rho*e)/(i+rho*e);
			}
			cout<<e<<"\t";
		}t1<<endl;
		
			rho=15;
			t1<<rho<<"\t";
			e=1;
			for(i=1;i<=20;i++)
			{
				e=(rho*e)/(i+rho*e);
			}
			cout<<e<<"\t";
		
		
	}

	t1.close();
//==============================================================================	
	return 0;
}
