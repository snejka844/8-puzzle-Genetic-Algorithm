//The data structure for holding the solutions. Allows the wholesale calling of growth and mutation on solutions.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "population.h"
#include <map>

Population::Population(int _id, int size, int _boardStart)
{
	id = _id;
	solutions.reserve(size);

	vector<Solution>::iterator it = solutions.begin();

	for (int i = 0; i < size; i++)
		it = solutions.insert(it, Solution(_boardStart));
}


Solution Population::getBest()
{
	return solutions[0];
}

bool Population::checkSolved()
{
	return solutions[0].solved();
}

void Population::sort()
{
	std::sort(solutions.begin(), solutions.end());//vector
}



void Population::selection(int elites, int cm)
{
	for (int i = elites; i < solutions.size(); i++)
	{
		// only crossover with certain probability
		int r = rand() % cm;
		if (r == 0)
			solutions[i].crossover(solutions[i%elites]);
	}
}

void Population::age()
{
	id++;
}



void Population::mutate(int mrate)
{
	for (int i = 0; i < solutions.size(); i++)
	{
		int r = rand() % mrate;
		if (r == 0)
		{
			r = rand() % 4;
			if (r == 0) solutions[i].growBestNoCycle();
			if (r == 1) solutions[i].growNoCycle();
			if (r == 2) solutions[i].mutate();
			if (r == 3) solutions[i].truncate();
		}
	}
}

double Population::getAvgFitness()
{
	avgFitness = 0;

	for (int i = 0; i < solutions.size(); i++)
		avgFitness += solutions[i].getFitness();

	avgFitness /= solutions.size();
	return avgFitness;
}

int Population::getUniqueIndividuals()
{
	// clear hash
	uniques.clear();
	for (int i = 0; i < solutions.size(); i++)
	{
		// not in hash yet
		if (uniques.count(solutions[i].getStatus()) == 0)
		{
			uniques.insert(make_pair(solutions[i].getStatus(), 1));
		}

		// already in hash so update count
		else
		{
			uniques[solutions[i].getStatus()]++;
		}

	}
	return uniques.size();
}

