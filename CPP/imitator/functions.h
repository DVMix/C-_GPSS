#ifndef functions
#define functions

#include<math.h>
#include<stdlib.h>

double dif(double value){
	int sign;	sign=rand()%100; //cout<<"sign="<<sign<<"\t";
	double rez,variable;	variable=rand()%1000;	variable/=10000;
	if(sign>=50){
		rez=value+variable*value;
	}
	else{
		rez=value-variable*value;
	}
	//cout<<rez<<"\t";
	return rez;
}	
double exp1(double a){
	double rez;
	rez=a;
	return rez;
}
double exp2(double a){
	double rez;
	rez=a;
	return rez;
}

#endif
