#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;
 
unsigned int key[4]={0xFDA5,0xD54E,0xFC00,0xB55A}; 
 
void encrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0, i;           
    uint32_t delta=0x9e3779b9;                     
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];   
    for (i=0; i < 32; i++) {                       
        sum += delta;
        v0 += ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        v1 += ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
    }                                              
    v[0]=v0; v[1]=v1;
}
 
void decrypt (uint32_t* v, uint32_t* k) {
    uint32_t v0=v[0], v1=v[1], sum=0xC6EF3720, i;       
    uint32_t delta=0x9e3779b9;                          
    uint32_t k0=k[0], k1=k[1], k2=k[2], k3=k[3];        
    for (i=0; i<32; i++) {                              
        v1 -= ((v0<<4) + k2) ^ (v0 + sum) ^ ((v0>>5) + k3);
        v0 -= ((v1<<4) + k0) ^ (v1 + sum) ^ ((v1>>5) + k1);
        sum -= delta;                                   
    }                                                   
    v[0]=v0; v[1]=v1;
}


 int main()
{
  char str[16]={"12345678"}; // 16 mod 8 =0
  int len=sizeof(str);
 
  encrypt((uint32_t*)str,key);
  
  cout <<"Encrypted string: ";
  for(int i=0;i<len;i++)
      {cout <<str[i];}
  cout <<endl;    
  decrypt((uint32_t*)str,key);
  cout <<"Decrypted string: ";
  cout <<str<<endl;
 }
