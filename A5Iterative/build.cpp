
//Samuel Grenon
//CS411
//Assignment5
//build.cpp
//This program generates the permutations of a vector and computes
//the maximum total of each..


#include "build.hpp"
#include <algorithm>
#include <iostream>


DyBridge::DyBridge(const std::vector<Bridge> & Bridges, int West, int East) {
	BridgeVec = Bridges;


	for (int i = 0; i < BridgeVec.size(); ++i) {
		WorkVec.push_back(Bridges[i][2]);
	}

	WestCities = West;
	EastCities = East;

	std::sort(BridgeVec.begin(), BridgeVec.end(), BSortVec);


	Answer = Recurse();

}

bool DyBridge::BridgePlaceable(int attemptBridge, int lastPlacedBridge)
{
	// "-1" becasue "0-1" is passed in, and this means no other bridges are currently used
	if (lastPlacedBridge == -1)
		return true;
	if ((BridgeVec[lastPlacedBridge][0] <= BridgeVec[attemptBridge][0] && BridgeVec[lastPlacedBridge][1] >= BridgeVec[attemptBridge][1]) ||
		(BridgeVec[lastPlacedBridge][0] >= BridgeVec[attemptBridge][0] && BridgeVec[lastPlacedBridge][1] <= BridgeVec[attemptBridge][1]))
	{
		return false;
	}
	return true;
}

int DyBridge::Recurse() {



	for (unsigned int i = 0; i < BridgeVec.size(); ++i) {
		//CurrMax = WorkVec[i];
		for (int j = i; j >= 0; --j) {
			if (BridgePlaceable(i, j)) {
				if (WorkVec[i] < (WorkVec[j] + BridgeVec[i][2]))
					WorkVec[i] = WorkVec[j] + BridgeVec[i][2];
			}
		}
	}

	int max = 0;
	for (auto i : WorkVec) {
		max = i > max ? i : max;
	}

	return max;


}





int DyBridge::GetAnswer() {
	return Answer;
}



int build(int WEST, int EAST, const std::vector<Bridge> & Bridges) {
	if (Bridges.size() == 0) {
		return 0;
	}
	DyBridge DyBridge(Bridges, WEST, EAST);
	return DyBridge.GetAnswer();



}

bool BSortVec(std::vector<int> a, std::vector<int> b) {
	if (a[0] == b[0]) {
		return a[1] < b[1];
	}
	return a[0] < b[0];
}




