#include "Distribution.h"
#include <random>
#include <cmath>
#include <iostream>
#include <vector>


/*low level class, deal with specific distribution calculation , provide some primitive function to do distribution sampling and distribution mulplication*/
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
	if(mean1==mean2 && var1==var2)
		return Distribution(0,0);

	double newVar = 1/(1/var1 - 1/var2);
	double newMean = (mean1/var1 - mean2/var2)*newVar;

	return Distribution(newMean,newVar);

}

double Distribution::pdf(double x){
	double a = (x-this->mean)*(x-this->mean);
	double b =  -a /(2*this->var);
	double c =  exp(b);
	double coefficient = pow(M_PI*2*this->var,-0.5);

	return coefficient * c;
}

double Distribution::phi(double x){
	x = (x - this->mean)/this->var;
	double a1 =  0.254829592;
	double a2 = -0.284496736;
    	double a3 =  1.421413741;
    	double a4 = -1.453152027;
    	double a5 =  1.061405429;
    	double p  =  0.3275911;
 
    	// Save the sign of x
    	int sign = 1;
    	if(x < 0)
        	sign = -1;
    	x = fabs(x)/sqrt(2.0);
 
 	// A&S formula 7.1.26
    	double t = 1.0/(1.0 + p*x);
    	double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);
 
    	return 0.5*(1.0 + sign*y);

}

Distribution Distribution::getMax(Distribution &one,Distribution &two,double p){
	double var1 = one.getVar();
	double mean1 = one.getMean();
	double deviation1 = sqrt(var1);
	
	double var2 = two.getVar();
	double mean2 = two.getMean();
	double deviation2 = sqrt(var2);
	
	double a = sqrt(var1+var2-2*p*deviation1*deviation2);
	double k = (mean1-mean2)/a;

	double phiK = Distribution(0,1).phi(k);
	double phiNegativeK = Distribution(0,1).phi(-k);
	
	double pdfK = Distribution(0,1).pdf(k);
	double pdfNegativeK = Distribution(0,1).pdf(k);

        double mean = phiK*(mean1+
                           (deviation1*(deviation1-p*deviation2)*pdfK)/(a*phiK)
                           )
		      + 
                      phiNegativeK*(mean2+
                          (deviation2*(deviation2-p*deviation1)*pdfNegativeK)/(a*phiNegativeK)
                                  );
	
	double var = phiK*((pow(mean1,2)+var1)+
			     ((2*mean1*deviation1*(deviation1-p*deviation2)/a)
                               -(k*var1*pow((deviation1-p*deviation2),2)/pow(a,2)))
                             *(pdfK/phiK)) 
                     + 
                     phiNegativeK*((pow(mean2,2)+var2)+
                              ((2*mean2*deviation2*(deviation2-p*deviation1)/a)
                                +k*var2*pow((deviation2-p*deviation1),2)/pow(a,2))
                                *(pdfNegativeK/phiNegativeK));
 		     -
		     pow(mean,2);

	return Distribution(mean,var);
}
	
Distribution Distribution::getMaxOfIndependentSet(std::vector<Distribution> &variables){
	Distribution intermedia = variables[0];
	for(std::vector<Distribution>::iterator it=variables.begin()+1;it<variables.end();it++){
		intermedia = Distribution::getMax(intermedia,(*it));
	}

	return intermedia;

}

/*has not finished implementation*/
Distribution Distribution::getMaxOfCorrelatedSet(std::vector<Distribution> &variables){
	 	
	return Distribution(0,0);

}

/*has not finished implementaton*/
double Distribution::getP(Distribution &one,Distribution &two){
	return 0.0;
}

double Distribution::getP(int i,int j,int deviation[],int k[],std::vector<Distribution> &variables){
	return 0.0;
}

double Distribution::getSample(){
	std::random_device gen;
    	std::normal_distribution<double> normal(this->mean, sqrt(this->var));
    	return normal(gen);
}
double Distribution::getMean() const{
	return mean;
}

double Distribution::getVar() const{
	return var;
} 

