#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"
using namespace std;
struct structura
{
		int num;
		int copy;
		int rdy;
		int order;
		double c_time;
		double s_time;
		double w_time;	
		double l_time;
		
};
		
#define N 10

int main()
{
	srand(time(NULL));
	int i,K=3,c[K],r[K];
	double lam=2,mu[K],tim=0,variable1;
	structura app[N];	
	for(i=0;i<N;i++){
		variable1=dif(exp1(lam)); 	tim+=variable1;
		app[i].num=i+1;				app[i].copy=0;				app[i].rdy=0;				app[i].order=0;
		app[i].c_time=tim;			app[i].s_time=0;			app[i].w_time=0;			app[i].l_time=0;
		//cout<<"num="<<app[i].num<<"\t"<<variable1<<"\tc_time="<<app[i].c_time<<endl;
	}
	int totalC=0,totalR=0,complete=0,insys=0,flag=0,bc[K],br[K];
	for(i=0;i<K;i++){
		c[i]=1;		bc[i]=0;		totalC+=c[i];			
		r[i]=30;	br[i]=0;		totalR+=r[i];	
		mu[i]=2;	//cout<<"c["<<i+1<<"]="<<c[i]<<"\t";//cout<<"r["<<i+1<<"]="<<r[i]<<endl;
	}//cout<<"total_C="<<totalC<<"\ttotal_R="<<totalR<<endl;
	
		
	structura inCap[totalC],inRes[totalR],variable_P,tmp;	
	int indicator, bisy_c,bisy_r,tester;
	double progress,nextOne,lastAction;

	
	do{
		//cout<<lastAction<<endl;
		bisy_c=0,bisy_r=0;
		for(i=0;i<K;i++)
		{
			bisy_c+=bc[i];
			bisy_r+=br[i];
		}
		if(insys<N)
		{
			cout<<"insys<N -> ";
			if(bisy_c!=0)
			{//система не пустая : возможно поступление и завершение обслуживания
				cout<<"N_E_S -> ";
				
				progress = inCap[0].c_time + inCap[0].w_time + inCap[0].s_time;
				cout<<"progress="<<progress<<"\tc_time="<<app[insys].c_time<<"\t";		   
				if(progress>app[insys].c_time)//поступление
				{
					//срез временных харакеристик==========================================
					cout<<"in\n";
					double difference=app[insys].c_time-lastAction;
					for(i=0;i<bisy_c;i++)
					{
						inCap[i].s_time=inCap[i].s_time-difference;
						inCap[i].w_time=inCap[i].w_time+difference;
					}
					for(i=0;i<bisy_r;i++)
					{
						inRes[i].w_time=inRes[i].w_time+difference;
					}
					//=====================================================================
					//проверка возможности приема новой заявки=============================
					tester=1;
					for(i=0;i<K;i++){
						if(bc[i]<c[i]){
							tester*=1;
						}
						else{
							if(br[i]<r[i]){
								tester*=1;
							}
							else{
								tester*=0;
							}
						}
					}
					bisy_c=0,bisy_r=0;
					for(i=0;i<K;i++)
					{
						bisy_c+=bc[i];
						bisy_r+=br[i];
					}
					
					if(tester==1)
					{
						for(i=0;i<K;i++)
						{
							if(bc[i]<c[i])
							{
								inCap[bisy_c+i]=app[insys];
								inCap[bisy_c+i].copy=i;
								inCap[bisy_c+i].s_time=dif(exp2(mu[inCap[bisy_c+i].copy]));
								bc[i]++;
							}
							else//  br ++
							{
								inRes[bisy_r+i]=app[insys];
								inRes[bisy_r+i].copy=i;
								//inRes[bisy_r+i].order=bisy_r+1;
								inRes[bisy_r+i].s_time=dif(exp2(mu[inRes[bisy_r+i].copy]));
								br[i]++;
							}
						}// сортировка  не нужна
					}
					else
					{
						cout<<"BLOCK"<<endl;
					}
					//сортировка массивов==================================================
					bisy_c=0,bisy_r=0;
					for(i=0;i<K;i++)
					{
						bisy_c+=bc[i];
						bisy_r+=br[i];
					}
					//system("PAUSE");
					for (int i = bisy_c - 1; i >= 0; i--){
						for (int j = 0; j < i; j++){
							if (inCap[j].s_time > inCap[j + 1].s_time){
								tmp = inCap[j];
								inCap[j] = inCap[j + 1];
								inCap[j + 1] = tmp;	
							}	
				    	}
				  	}
					for (int i = bisy_r - 1; i >= 0; i--){
						for (int j = 0; j < i; j++){
							if (inRes[j].w_time < inCap[j + 1].w_time){
								tmp = inRes[j];
								inRes[j] = inRes[j + 1];
								inRes[j + 1] = tmp;	
							}	
				    	}
				    	//cout<<inRes[i].s_time<<" ";
				  	}
					    				  	
					lastAction=app[insys].c_time;	
					insys++;
				}
				else//обслуживание/////////////////////////////////////////////////////////////////////////--------->>>>
				{
					cout<<"out\n";
					double difference=progress-lastAction;
					cout<<"dif="<<difference<<endl;
					for(i=0;i<bisy_c;i++)
					{
						inCap[i].s_time=inCap[i].s_time-difference;
						inCap[i].w_time=inCap[i].w_time+difference;
						//cout<<inCap[i].s_time<<"\t"<<inCap[i].w_time<<endl;
						
					}
					for(i=0;i<bisy_r;i++)
					{
						inRes[i].w_time=inRes[i].w_time+difference;
					}
					
					bc[inCap[0].copy]--;
					int Copy = inCap[0].copy;
					bisy_c=0,bisy_r=0;
					for(i=0;i<K;i++)
					{
						bisy_c+=bc[i];
						bisy_r+=br[i];
					}
					cout<<"bisy_c="<<bisy_c<<endl;
					for(i=0;i<bisy_c;i++)
					{
						inCap[i]=inCap[i+1];
						//cout<<inCap[i].s_time<<"\t"<<inCap[i].w_time<<endl;
						//cout<<i+1<<"\tc_t="<<inCap[i].c_time<<"\tw_t="<<inCap[i].w_time<<"\ts_t="<<inCap[i].s_time<<endl;
						//system("PAUSE");
					}
					lastAction=progress;
				}
				
			}
			else
			{//система пустая - только поступление заявок
				//cout<<app[insys].c_time<<endl;
				cout<<"  E_S -> in\n";
				for(i=0;i<K;i++)
				{
					inCap[i]=app[insys];
					inCap[i].copy=i;
					inCap[i].s_time=dif(exp2(mu[inCap[i].copy]));
					
					bc[i]++;
				}
				bisy_c=0,bisy_r=0;
				for(i=0;i<K;i++)
				{
					bisy_c+=bc[i];
					bisy_r+=br[i];
				}
				//system("PAUSE");
				for (int i = bisy_c - 1; i >= 0; i--){
					for (int j = 0; j < i; j++){
						if (inCap[j].s_time > inCap[j + 1].s_time){
							tmp = inCap[j];
							inCap[j] = inCap[j + 1];
							inCap[j + 1] = tmp;	
						}	
			    	}
			    }

			  	lastAction=app[insys].c_time;
				insys++;	
			}
		}
		else
		{//только обслуживание
			cout<<"insys=N -> out";
			
			double difference=progress-lastAction;
			for(i=0;i<bisy_c;i++)
			{
				inCap[i].s_time=inCap[i].s_time-difference;
				inCap[i].w_time=inCap[i].w_time+difference;
			}
			for(i=0;i<bisy_r;i++)
			{
				inRes[i].w_time=inRes[i].w_time+difference;
			}
			
			complete++;
		}
		
		for(i=0;i<bisy_c;i++)
		{
			cout<<i+1<<"\tc_t="<<inCap[i].c_time<<"\tw_t="<<inCap[i].w_time<<"\ts_t="<<inCap[i].s_time<<endl;
		}
		cout<<"insys="<<insys<<"\tcomplete="<<complete<<endl;
		getch();//system("PAUSE");
	}while((complete!=N)||(insys!=N));
	cout<<"SUCCESS!"<<endl;
	
	return EXIT_SUCCESS;
}
