#pragma once
#include <vector>
class Distribution{
	private:
		double mean;
		double var;
	public:
		Distribution(const double m=0.0,const double v=0.0);
		double getMean() const;
		double getVar() const;
		Distribution operator*(const Distribution &dis);
		Distribution operator/(const Distribution &dis); 
		double getSample();

		static Distribution getMax(Distribution &one,Distribution &Two,double p=0.0);
		static Distribution getMaxOfCorrelatedSet(std::vector<Distribution> &variableSet);
		static Distribution getMaxOfIndependentSet(std::vector<Distribution> &variableSet);
		static double getP(Distribution &one,Distribution &two);
		static double getP(int i,int j,int deviation[],int k[],std::vector<Distribution> &variables);
		double phi(double x);
		double pdf(double x);
};
