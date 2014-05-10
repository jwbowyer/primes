#include "factorize.h"
#include <math.h>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

void Factorize::SetFactee(long int ToFactorize_){

 ToFactorize=ToFactorize_;

}

long int Factorize::GetFactee(){

 return ToFactorize;

}

int Factorize::GetMethod(){

 switch(TheMethod){
  case Brute:
   return 0;
  case NonBrute:
   return 1;
  default:
   throw("GetMethod error\n");
 }

}

vector<long int> Factorize::GetFactors(long int ToFactorize_,Method TheMethod_){

 //Make ToFactorize_ optionally either set here, or by SetFactee()
 vector<long int> PrimeFactors_;

 switch(TheMethod_){
  case Brute:
   PrimeFactors_ = BruteMethod(ToFactorize_);
   break;
  case NonBrute:
   //PrimeFactors = Factorize.NonBruteMethod(ToFactorize_);
   break;
  default:
   throw("Specify a method!\n");
 }

 return PrimeFactors_;

}

vector<long int> Factorize::BruteMethod(long int ToFactorize_){

 //Brute-force recursive method
 // *Check that we can divide by the lowest prime
 //   *If yes, find the largest power of this number that we can factorize with. Push this into our factors vector. Continue
 //   *If no, then end and return the value as the lowest remaining prime
 // *If continue iterate up to the next prime. Note that we can find the next prime by iterating up the integers and applying the same algo.
 // *At the end of the iteration, return the prime vector

 long int Prime=2;	//At this stage in the code, the number is actually an integer, not a prime.
 double lim=sqrt(ToFactorize_);

 cout<<"Iterating up integers..\n";
 while(Prime<=lim){

  //Speed up by either checking for primality (adding previous primes into an array)

  //Main code

  //We get the largest power of Prime that fits into the factee.
  long int iter=(long int) log2(ToFactorize_)/log2(Prime);	//log_b(x)=log_k(x)/log_k(b)
  long int PrimePow;

  //We iterate down from the largest power, checking each as a factor.
  if( (ToFactorize_%Prime)!=0 ){ Prime++; continue; }

  while(iter>0){

   PrimePow=(long int) pow(Prime,iter);
   if((ToFactorize_%PrimePow)==0){
    //If we have a fit, we push the necessary factors of Prime into our vector
    for(int i=0;i<iter;i++){
     PrimeFactors.push_back(Prime);
    }
    //We then remove the factor product
    ToFactorize_/=PrimePow;
    break;
   }else{
    iter--;
   }
  }
  Prime++;

 }	//end while(Prime)

 //Whatever is left is the remaining factor.. catch if not prime (do)
 PrimeFactors.push_back(ToFactorize_);

 return PrimeFactors;
 //Add a "pre-computed primes" insert vector to speed this up.

}

/*vector<long int> Factorize::NonBruteMethod(){

 //Quadratic sieve, for integer n to be factorized. Finish later!

 //Data collection: compute (a**2)%n and then find an a such that % is square


 //Data processing



}*/

