/*
Samuel Grenon
CS411
Assignment1
build.cpp
This program generates the permutations of a vector and computes
the maximum total of each..
*/


#include "build.hpp"
#include <algorithm>




bool BIsValid(const int TestWest, const int TestEast, const int CurrWest, const int CurrEast) {
	return !((TestWest <= CurrWest && TestEast >= CurrEast) ||
		(TestWest >= CurrWest && TestEast <= CurrEast));
	
}


bool BCheckStack(const std::vector<Bridge> & Stack, const Bridge B) {
	for (auto I : Stack) {
		if (!BIsValid(I[0], I[1], B[0], B[1]))
			return false;
	}

	return true;
}

int Rescurse(std::vector<Bridge> & Stack, int Offset, const std::vector<Bridge> & Bridges) {
	int Max = 0;
	for (auto I = Offset; I < Bridges.size(); ++I) {
		if (BCheckStack(Stack, Bridges[I])) {
			Stack.push_back(Bridges[I]);
			int Total = Rescurse(Stack, I + 1, Bridges);
			if (Total+Bridges[I][2] > Max) {
				Max = Total+Bridges[I][2];
			}
			Stack.pop_back();

		}
	}
	return Max;
}

int build(int WEST, int EAST, const std::vector<Bridge> & Bridges) {
	std::vector<Bridge> Stack;
	return Rescurse(Stack, 0, Bridges);
}



					
		








