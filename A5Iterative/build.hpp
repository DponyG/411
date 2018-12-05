//CS411
//Assignment2
//build.hpp
//This program generates the permutations of a vector and computes
//the maximum total of each..

#ifndef BUILD_HPP
#define BUILD_HPP

#include<vector>

using Bridge = std::vector<int>;
class DyBridge {
public:
	DyBridge(const std::vector<Bridge> & Bridge, int West, int East);
	bool BridgePlaceable(int, int);
	int Recurse();
	int GetAnswer();
private:
	std::vector<std::vector<int>>BridgeVec;
	std::vector<int> WorkVec;
	int Answer = 0;
	int WestCities;
	int EastCities;
};

int build(int, int, const std::vector<Bridge> &);
bool BSortVec(std::vector<int> a, std::vector<int> b);






#endif









