/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:44:05 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/27 15:32:12 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
    std::vector<int> vec;
    std::list<int> lst;

    if (argc < 2)
    {
        std::cout << USAGE << std::endl;
        return 1;
    }

    for (int i = 1; i < argc; ++i)
    {
        if (checkArgs(argv[i]))
        {
            std::cout << "Invalid argument : " << argv[i] << std::endl;
            std::cout << USAGE << std::endl;
            return 1;
        }
    }

    for (int i = 1; i < argc; ++i)
    {
        for (int j = i + 1; j < argc; ++j)
        {
            if (std::atoi(argv[i]) == std::atoi(argv[j]))
            {
                std::cout << "Duplicates Found : " << argv[i] << std::endl;
                std::cout << USAGE << std::endl;
                return 1;
            }
        }
        vec.push_back(std::atoi(argv[i]));
        lst.push_back(std::atoi(argv[i]));
    }

    std::cout << "Before      : ";
    printVector(vec);
    
    std::clock_t start_vec = std::clock();
    mergeInsertionSortVector(vec);
    std::clock_t end_vec = std::clock();
    std::cout << "After       : ";
    printVector(vec);

    std::clock_t start_lst = std::clock();
    mergeInsertionSortList(lst);
    std::clock_t end_lst = std::clock();
    
    double duration_vec = 1000.0 * (end_vec - start_vec) / CLOCKS_PER_SEC;
    std::cout << "Vector Took : " << duration_vec << " ms" << std::endl;
    double duration_lst = 1000.0 * (end_lst - start_lst) / CLOCKS_PER_SEC;
    std::cout << "List Took   : " << duration_lst << " ms" << std::endl;
    
    return 0;
}