#pragma once
#ifndef GENERATION_H
#define GENERATION_H

#include <vector>
#include <algorithm>
#include "solution.h"

using namespace std;

class Population
{
private:
	int id;
	vector<Solution> solutions;
	map<int, int> uniques;
	double avgDistance;
	double meanDistance;
	double avgFitness;

public:
	Population(int, int, int);
	void sort();//used in World start and seedPopulation
	void age();//used in World start
	bool checkSolved();//used in World start and seedPopulation
	Solution getBest();//used in World start and seedPopulation
	void mutate(int);//used in World start and seedPopulation
	void selection(int, int);//used in World start
	double getMeanDistance() { return meanDistance; }
	double getAvgFitness();
	int getUniqueIndividuals();//used in World start

};

#endif