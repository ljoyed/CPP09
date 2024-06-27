/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:31:52 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/19 17:25:27 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
//Container used for this project : MAP

std::map<std::string, float> loadDatabase(const std::string &filename);
void processInputFile(const std::string &filename, const std::map<std::string, float> &db);
void parseDateAmount(std::string &line, const std::map<std::string, float> &db);
void processOutput(std::string &dt, float amt, const std::map<std::string, float> &db);
bool isLeapYear(int year);
bool isDateValid(const std::string &date);

#endif