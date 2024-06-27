/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 13:03:01 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/27 15:30:28 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

// Function to perform binary search and insert into the main-chain
void binaryInsertVector(std::vector<int>& mainChain, int value, int end)
{
    int left = 0;
    int right = end;
    
    while (left < right)
    {
        int mid = (left + right) / 2;
        if (mainChain[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    mainChain.insert(mainChain.begin() + left, value);
}

void binaryInsertList(std::list<int>& mainChain, int value, int end)
{
    std::list<int>::iterator left = mainChain.begin();
    std::list<int>::iterator right = mainChain.begin();
    std::advance(right, end);

    while (left != right)
    {
        std::list<int>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);

        if (*mid < value)
            left = ++mid;
        else
            right = mid;
    }
    mainChain.insert(left, value);
}

// Recursive function to perform merge insertion sort
void mergeInsertionSortVector(std::vector<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;

    // Group into pairs and sort each pair
    std::vector<std::pair<int, int>> pairs;
    for (int i = 0; i < n; i += 2)
    {
        if (i + 1 < n)
        {
            if (arr[i] > arr[i + 1])
                std::swap(arr[i], arr[i + 1]);
            pairs.push_back(std::make_pair(arr[i], arr[i + 1]));
        }
        else
            pairs.push_back(std::make_pair(arr[i], arr[i]));
    }

    // Recursively sort the pairs based on the left hand side elements because they are the smaller ones in their respective pairs
    std::vector<int> left;
    for (size_t i = 0; i < pairs.size(); ++i)
        left.push_back(pairs[i].first);
    
    mergeInsertionSortVector(left);

    // Insert the right hand side elements from each pair into the main-chain in order
    std::vector<int> mainChain = left; //this is the last single element after all recursive calls
    for (size_t i = 0; i < pairs.size(); ++i)
    {
        if (pairs[i].second != pairs[i].first)
            binaryInsertVector(mainChain, pairs[i].second, mainChain.size());
    }

    // Copy the sorted main-chain back to the original array
    for (size_t i = 0; i < n; ++i)
        arr[i] = mainChain[i];
}

void mergeInsertionSortList(std::list<int>& arr)
{
    int n = arr.size();
    if (n <= 1)
        return;

    std::list<std::pair<int, int>> pairs;
    std::list<int>::iterator it = arr.begin();
    while (it != arr.end())
    {
        int first = *it;
        ++it;
        if (it != arr.end())
        {
            int second = *it;
            if (first > second)
                std::swap(first, second);
            pairs.push_back(std::make_pair(first, second));
            ++it;
        }
        else
            pairs.push_back(std::make_pair(first, first));
    }

    std::list<int> a;
    for (std::list<std::pair<int, int>>::iterator p = pairs.begin(); p != pairs.end(); ++p)
        a.push_back(p->first);

    mergeInsertionSortList(a);

    std::list<int> mainChain = a;
    for (std::list<std::pair<int, int> >::iterator p = pairs.begin(); p != pairs.end(); ++p)
    {
        if (p->second != p->first)
            binaryInsertList(mainChain, p->second, mainChain.size());
    }

    std::list<int>::iterator mainIt = mainChain.begin();
    for (std::list<int>::iterator arrIt = arr.begin(); arrIt != arr.end(); ++arrIt)
    {
        *arrIt = *mainIt;
        ++mainIt;
    }
}

void printVector(const std::vector<int>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
}

void printList(const std::list<int>& lst)
{
    for (std::list<int>::const_iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

int checkArgs(char *str)
{
    int i;
    int arg;

    i = 0;
    if (str[0] == '\0')
        return 1;
    
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return 1;
        i++;
    }

    arg = std::atoi(str);
    if (arg < 0)
        return 1;
    return 0;
}