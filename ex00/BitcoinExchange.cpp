/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:46:37 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/26 17:52:34 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float> loadDatabase(const std::string &filename)
{
    std::map<std::string, float> db;
    std::ifstream in;
    std::string line;
    std::string date;
    float amount;

    in.open(filename);
    if (in.fail())
    {
        std::cout << "Error opening file : " << filename << std::endl;
        return db;
    }
    getline(in, line); //to skip the header in the data.csv
    while (getline(in, line))
    {
        date = line.substr(0, 10);
        amount = std::stof(line.substr(11));
        db[date] = amount;
    }
    in.close();
    return db;
}

void processInputFile(const std::string &filename, const std::map<std::string, float> &db)
{
    std::ifstream in;
    std::string line;

    in.open(filename);
    if (in.fail())
    {
        std::cout << "Error opening file : " << filename << std::endl;
        return;
    }
    getline(in, line); //to skip the header in the input.txt 
    while (getline(in, line))
    {
        parseDateAmount(line, db);
    }
    in.close();
}

void parseDateAmount(std::string &line, const std::map<std::string, float> &db)
{
    std::string cleanLine;
    std::string date;
    std::string amt;
    float amount;
    size_t delimiterPos;

    cleanLine = line.erase(0, line.find_first_not_of(" \t"));
    cleanLine = cleanLine.erase(line.find_last_not_of(" \t") + 1);
    if (cleanLine.find('|') == std::string::npos)
    {
        std::cout << "Error: bad input => " << cleanLine << std::endl;
        return;
    }
    delimiterPos = cleanLine.find('|');
    date = cleanLine.substr(0, delimiterPos - 1);
    if (cleanLine.c_str()[delimiterPos + 1] == 0)
    {
        std::cout << "Error: bad input => " << cleanLine << std::endl;
        return;
    }
    amt = cleanLine.substr(delimiterPos + 2);
    if (amt.empty() || amt.find_first_not_of("0123456789.-") != std::string::npos)
    {
        std::cout << "Error: bad input => " << cleanLine << std::endl;
        return;
    }
    if (amt.find('.') != amt.rfind('.'))
    {
        std::cout << "Error: bad input => " << cleanLine << std::endl;
        return;
    }
    if (amt.find('-') != amt.rfind('-'))
    {
        std::cout << "Error: bad input => " << cleanLine << std::endl;
        return;
    }
    if (amt.find('-') != std::string::npos && amt[0] != '-')
    {
        std::cout << "Error: bad input => " << amt << std::endl;
        return;
    }
    amount = std::stof(amt);
    if (amount < 0)
    {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    else if (amount > 1000)
    {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
    else
        processOutput(date, amount, db);
}

bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isDateValid(const std::string &date)
{
    struct std::tm tm;
    int year;
    int month;
    int day;
    std::istringstream ss(date);
    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail())
        return false;
    year = tm.tm_year + 1900;
    month = tm.tm_mon + 1;
    day = tm.tm_mday;

    if (month < 1 || month > 12)
        return false;
    if (day < 1)
        return false;
    switch (month)
    {
        case 2: // Feb
            if (isLeapYear(year))
            {
                if (day > 29)
                    return false;
            }
            else
            {
                if (day > 28)
                    return false;
            }
            break;
        case 4: case 6: case 9: case 11: // Apr, Jun, Sep, Nov
            if (day > 30)
                return false;
            break;
        default: // Jan, Mar, May, Jul, Aug, Oct, Dec
            if (day > 31)
                return false;
            break;
    }
    return true;
}

void processOutput(std::string &dt, float amt, const std::map<std::string, float> &db)
{
    std::map<std::string, float>::const_iterator it = db.find(dt);
    if (it != db.end())
        std::cout << dt << " => " << amt << " = " << amt * it->second << std::endl;
    
    else if (isDateValid(dt))
    {
        std::map<std::string, float>::const_iterator it = db.lower_bound(dt);
        if (it == db.begin())
            std::cout << "Error: no data available for or before => " << dt << std::endl;
        else
        {
            --it;  
            std::cout << dt << " => " << amt << " = " << amt * it->second << std::endl;
        }
    }
    else
        std::cout << "Error: invalid date." << std::endl;   
}