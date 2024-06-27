/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:43:30 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/17 11:08:39 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char *argv[])
{
    std::map<std::string, float> database;

    if (argc != 2)
    {
        std::cerr << "Usage  : " << argv[0] << " <input_file>\nExample: " << argv[0] << " input.txt" << std::endl;
        return 1;
    }

    database = loadDatabase("data.csv");
    processInputFile(argv[1], database);

    return 0;
}
