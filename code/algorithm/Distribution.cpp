#include "Distribution.h"
#include <random>
#include <cmath>
#include <iostream>

Distribution::Distribution(const double m,const double v){
	mean = m;
	var = v;
}

Distribution Distribution::operator*(const Distribution &dis){
	double var1 = dis.getVar();
	double var2 = this->var;
	double mean1 = dis.getMean();
	double mean2 = this->mean;

	if(var1==0)
		return Distribution(mean2,var2);
	else if(var2==0)
		return Distribution(mean1,var1);

	double newVar = 1/(1/var1 + 1/var2);
	double newMean = (mean1/var1 + mean2/var2)*newVar;

	return Distribution(newMean,newVar);

}

Distribution Distribution::operator/(const Distribution &dis){
	double var1 = this->var;
	double mean1 = this->mean;

	double var2 = dis.getVar();
	double mean2  =  dis.getMean();	

	if(var2==0)
		return Distribution(mean1,var1);
	/*when 1/var1 - 1/var2 =0 , how to deal with this situation ?*/
	double newVar = 1/(1/var1 - 1/var2);
	double newMean = (mean1/var1 - mean2/var2)*newVar;

	return Distribution(newMean,newVar);

}

double Distribution::getSample(){
	std::random_device gen;
    	std::normal_distribution<double> normal(mean, sqrt(var));
    	return normal(gen);
}
double Distribution::getMean() const{
	return mean;
}

double Distribution::getVar() const{
	return var;
} 
