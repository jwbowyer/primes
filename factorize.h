#ifndef FACTORIZE_H
#define FACTORIZE_H

#include <vector>

using namespace std;

class Factorize{

 public:
  void SetFactee(long int);		//use template
  long int GetFactee();
  enum Method {Brute,NonBrute};
  int GetMethod();
  vector<long int> GetFactors(long int,Method);
  vector<long int> BruteMethod(long int);

 private:
  long int ToFactorize;
  Method TheMethod;
  vector<long int> PrimeFactors;


};

#endif
