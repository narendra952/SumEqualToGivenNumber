// SumEqualToGivenNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "OperationsOverVector.h"

int main()
{
	std::vector<int> inputNumbers;
	inputNumbers.push_back(16);
	inputNumbers.push_back(19); 
	inputNumbers.push_back(14); 
	inputNumbers.push_back(6); 
	inputNumbers.push_back(1); 
	inputNumbers.push_back(20); 
	inputNumbers.push_back(11);

	SumEqualToGivenNumber::FindThreeNumbersSumInGivenNumbers(inputNumbers, 21);
	return 0;
}

