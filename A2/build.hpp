#ifndef BUILD_HPP
#define BUILD_HPP

#include<vector>

using Bridge = std::vector<int>;


int build(int, int, const std::vector<Bridge> &);


int permutations(std::vector<Bridge> stack, const std::vector<Bridge> & bridges, int offset);

bool isValid(int TestWest, int TestEast, int CurrWest, int CurrEast);

using Bridge = std::vector<int>;







#endif

