// 411A2.cpp : Defines the entry point for the console application.
//

#include "build.hpp"
#include <algorithm>
#include <iostream>

int build(int WEST, int EAST, const std::vector<Bridge> & Bridges) {

	int Total = 0;
	std::vector<int> Toll{};

	if (Bridges.size() == 0) {
		return 0;
	}

	else {
		for (int I = 0; I < Bridges.size(); ++I) {
			for (int J = I + 1; J < Bridges.size(); ++J) {
				if (!IsNotValid(Bridges[J][0], Bridges[J][1],
					Bridges[I][0], Bridges[I][1])) {
					Total += Bridges[J][2];
				}
			}
			Toll.push_back(Total + Bridges[I][2]);
			Total = 0;
		}
	}

	auto it = *std::max_element(std::begin(Toll), std::end(Toll));
	std::cout << *std::max_element(std::begin(Toll), std::end(Toll)) << std::endl;

	return it;

}

bool IsNotValid(int TestWest, int TestEast, int CurrWest, int CurrEast) {
	return((TestWest <= CurrWest && TestEast >= CurrEast) ||
		(TestWest >= CurrWest && TestEast <= CurrEast));
		
}

