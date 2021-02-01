#pragma once
#include <map>
#include <deque>
#include "board.h"

#ifndef SOLUTION_H 
#define SOLUTION_H 

using namespace std;

class Solution
{
private:
	double avgDistance;
	double meanDistance;

public:
	multimap<int, int> map;
	deque<int> list;

public:
	Solution(int);
	bool growNoCycle();//used in Solution mutate and Population grow mutate
	void growBestNoCycle();//used in  Population mutate
	void mutate();//used in Solution growBestNoCycle and Population mutate
	int getStatus() const;//used in Solution getFitness and solved and Population getUniqueIndividuals
	bool operator<(const Solution& rhs) const;
	double getFitness() const;//used in Solution operator < and Population getAvgFitness
	bool solved();//used in  Population checkSolved
	void print();//used in World start and seedPopulation
	void crossover(Solution&);//used in Population selection
	void truncate();//used in Population mutate

	void setAvgDistance(double d) { avgDistance = d; }
	double getAvgDistance() { return avgDistance; }
	void setMeanDistance(double d) { meanDistance = d; }
	double getMeanDistance() { return meanDistance; }
	int getSize() { return list.size(); }
};

#endif