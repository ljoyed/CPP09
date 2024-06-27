/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:40:30 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/20 13:48:34 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int checkValidity(std::string args)
{
    std::istringstream iss(args);
    std::string token;

    while(std::getline(iss, token, ' '))
    if (token.find_first_not_of("0123456789+-/*") != std::string::npos)
    {
        std::cout << "Error" << std::endl;
        return 1;
    }
    return 0;
}

float calculate(std::stack<float> *s1, std::string args)
{
    float result = 0;
    std::istringstream iss(args);
    std::string token;

    while(std::getline(iss, token, ' '))
    {
        if (token.find_first_of("0123456789") != std::string::npos)
            s1->push(std::atof(token.c_str()));
        else if (token.find_first_of("+-/*") != std::string::npos)
        {
            if (s1->size() < 2)
            {
                std::cout << "Not enough operands to calculate the result." << std::endl;
                exit(1);
            }
            checkCase(&result, token, s1);
        }
    }
    if (s1->size() == 1)
        return result;
    else
    {
        std::cout << "Invalid RPN expression." << std::endl;
        exit(1);
    }
}

void checkCase(float *res, std::string token, std::stack<float> *s1)
{
    float second;
    float first;
    size_t i;
    std::string ops[4] = {"+", "-", "/", "*"};
    
    second = s1->top();
    s1->pop();
    first = s1->top();
    s1->pop();

    for (i = 0; i < 4; ++i)
        if (token == ops[i])
            break;
    switch (i)
    {
        case 0:
            *res = first + second;
            s1->push(*res);
            break;
        case 1:
            *res = first - second;
            s1->push(*res);
            break;
        case 2:
            if (second == 0)
            {
                std::cout << "Denominator cannot be 0." << std::endl;
                exit(1);
            }    
            *res = first / second;
            s1->push(*res);
            break;
        case 3:
            *res = first * second;
            s1->push(*res);
            break;
        default:
            break;
    }
}