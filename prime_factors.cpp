#include <iostream>
#include <sstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <factorize.h>

using namespace std;

int main(){

 //gcc -c Prime_factors.cpp -I/usr/include -I/.../primes
 //gcc -c factorize.cpp -I/usr/include -I/.../primes
 //g++ -o prime_factors prime_factors.o factorize.o -L/usr/lib
 //./prime_factors

 //change to a command-line input
 long int valueRequired=600851475143;
 long int valueOriginal=valueRequired;
 int valueGiven=13195;
 bool FactorizesByGiven=0;
 int valueGivenPrimes[4] = {5,7,13,29};
 vector<long int> PrimeFactors;
 int vGP_size=sizeof(valueGivenPrimes)/sizeof(int);

 //I want to factorize 600851475143. I've been given the result for 13195: 5, 7, 13, 29
 //Before I go any further, I want to check whether I can simplify the task by using the previous result.

 stringstream ss;
 if((valueRequired%valueGiven)==0){
  FactorizesByGiven=1;
  PrimeFactors.push_back( valueRequired/valueGiven );
  valueRequired /= valueGiven;
  ss.str(""); ss << valueRequired;
  cout<<"Problem simplifies to factorizing "<< ss.str() << endl;
 }

 //Now factorize
 Factorize primeFct;
 //primeFct.SetFactee(valueRequired);
 PrimeFactors=primeFct.GetFactors(valueRequired,Factorize::Brute);

 //If factoring a smaller number, push in these values
 int i=0;
 if(FactorizesByGiven==1){
  while(i<vGP_size){
   PrimeFactors.push_back(valueGivenPrimes[i]);
   i++;
  }
 }

 i=0;
 cout<<"Factors of "<<valueOriginal<<" are: ";
 while(i<PrimeFactors.size()){
  cout<<PrimeFactors[i]<<" ";
  i++;
 }
 cout<<"\n";


 cout<<"The largest factor is "<<*max_element(PrimeFactors.begin(),PrimeFactors.end())<<"\n";

 cout.flush();


}
