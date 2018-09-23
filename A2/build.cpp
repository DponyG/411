/*
Samuel Grenon
CS411
A2
*/

#include "build.hpp"
#include <algorithm>
#include <iostream>
#include <math.h>


int build(int WEST, int EAST, const std::vector<Bridge> & bridges) {

	std::vector<Bridge> stack;
	return permutations(stack, bridges, 0);

}



bool checkStack(const std::vector<Bridge> &stack, const Bridge &bridge) {
	for (auto n : stack) {
		if (!isValid(n[0], n[1], bridge[0], bridge[1])) {
			return false;
		}
	}

	return true;
}


int permutations(std::vector<Bridge> stack, const std::vector<Bridge> & bridges, int offset) {
	int max = 0;

	for (auto i = offset; i < bridges.size(); ++i) {
		if (checkStack(stack, bridges[i])) {
			stack.push_back(bridges[i]);
			int total = permutations(stack, bridges, i+1);

			if (total + bridges[i][2] > max) {
				max = total + bridges[i][2];
			}
			stack.pop_back();

		}

	}

	return max;
	
}



bool isValid(int testWest, int testEast, int currWest, int currEast) {
	return(!(testWest <= currWest && testEast >= currEast) ||
		(testWest >= currWest && testEast <= currEast));
		
}

