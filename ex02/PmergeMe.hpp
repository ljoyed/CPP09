/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 23:23:49 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/27 15:28:00 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <ctime>

#define USAGE "USAGE  : ./PmergeMe <positive integer arguments only, each separated by a space and no duplicates>\nExample: ./PmergeMe 5 1 3 10 9 14 12 7"

void binaryInsertVector(std::vector<int>& mainChain, int value, int end);
void binaryInsertList(std::list<int>& mainChain, int value, int end);
void mergeInsertionSortVector(std::vector<int>& arr);
void mergeInsertionSortList(std::list<int>& arr);
void printVector(const std::vector<int>& vec);
void printList(const std::list<int>& lst);
int checkArgs(char *str);

#endif