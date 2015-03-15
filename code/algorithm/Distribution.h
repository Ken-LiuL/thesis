#pragma once
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
		double phi(double x);
		double pdf(double x);
};
