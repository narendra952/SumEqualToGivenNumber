#pragma once
#include <vector>
#include <iostream>

class SumEqualToGivenNumber
{
public:
	static void FindThreeNumbersSumInGivenNumbers(std::vector<int>& i_InputNumbers, int i_Sum);
private:
	//heapify subtree with node i_Index as root
	static void Max_HeapifyGivenVector(std::vector<int>& i_InputNumbers, int i_Index);
	
	// sorting elements using heapsort
	static void HeapSort(std::vector<int>& i_InputNumbers);
};

inline void SumEqualToGivenNumber::FindThreeNumbersSumInGivenNumbers(std::vector<int>& i_InputNumbers, int i_Sum)
{
	//sort the given numbers 
	HeapSort(i_InputNumbers);

	//Start with first element, take second and third elements as index next to first element and last index respectively
	//Depending upon the scenario increase the second element index or decrease the last element index
	for (unsigned int firstElementIndex = 0; firstElementIndex != i_InputNumbers.size() - 2; ++firstElementIndex)
	{
		int leftIndex = firstElementIndex + 1;
		int rightIndex = i_InputNumbers.size() - 1;
		while (leftIndex < rightIndex)
		{
			if (i_InputNumbers[firstElementIndex] + i_InputNumbers[leftIndex] + i_InputNumbers[rightIndex] == i_Sum)
			{
				std::cout << "Three Numbers found for given sum: " << i_InputNumbers[firstElementIndex] << " " << i_InputNumbers[leftIndex] << " " << i_InputNumbers[rightIndex] << std::endl;
				return;
			}
			else if (i_InputNumbers[firstElementIndex] + i_InputNumbers[leftIndex] + i_InputNumbers[rightIndex] < i_Sum)
			{
				leftIndex += 1;
			}
			else
			{
				rightIndex -= 1;
			}
		}
	}

	std::cout << "No triplet found for given sum";
}

inline void SumEqualToGivenNumber::Max_HeapifyGivenVector(std::vector<int>& i_InputNumbers, int i_Index)
{
	int currentRootIndex = i_Index;
	int leftSubTreeIndex = 2 * i_Index + 1;
	int rightSubTreeIndex = 2 * i_Index + 2;

	//if left subtree root is greater than root index, i_Index
	if (leftSubTreeIndex < (int)(i_InputNumbers.size()) && i_InputNumbers[leftSubTreeIndex] > i_InputNumbers[currentRootIndex])
	{
		currentRootIndex = leftSubTreeIndex;
	}

	//if right subtree root is greater than root index, i_Index
	if (rightSubTreeIndex < (int)(i_InputNumbers.size()) && i_InputNumbers[rightSubTreeIndex] > i_InputNumbers[currentRootIndex])
	{
		currentRootIndex = rightSubTreeIndex;
	}

	//if currentrootIndex is not root
	if (currentRootIndex != i_Index)
	{
		std::swap(i_InputNumbers[i_Index], i_InputNumbers[currentRootIndex]);

		//max heapify the modified subtree 
		Max_HeapifyGivenVector(i_InputNumbers, currentRootIndex);
	}
}

inline void SumEqualToGivenNumber::HeapSort(std::vector<int>& i_InputNumbers)
{
	//build heap of given vector
	for (unsigned int i = (i_InputNumbers.size() / 2) - 1; i != -1; --i)
		Max_HeapifyGivenVector(i_InputNumbers, i);
	
	std::vector<int> numbersInAscendingOrder;
	for (unsigned int i = i_InputNumbers.size() - 1; i != -1; --i)
	{
		//move maximum element to end of vector
		std::swap(i_InputNumbers[0], i_InputNumbers[i]);
		
		numbersInAscendingOrder.push_back(i_InputNumbers[i_InputNumbers.size() - 1]);
		i_InputNumbers.pop_back();

		//max heapify on the remaining vector elements 
		Max_HeapifyGivenVector(i_InputNumbers, 0);
	}
	//reverse descending order numbers to ascending order
	std::reverse(numbersInAscendingOrder.begin(), numbersInAscendingOrder.end());

	//move the numbersInAscendingOrder vector to inputVector
	i_InputNumbers = std::move(numbersInAscendingOrder);
}
