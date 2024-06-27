/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:54:02 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/20 13:42:58 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
#include <cstdlib>

#define USAGE "To use program: ./RPN \"<operand> <operand> <operator> [<operand> <operator>...]\""
#define EXAMPLE "Example       : ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""

int checkValidity(std::string arg);
float calculate(std::stack<float> *s1, std::string args);
void checkCase(float *res, std::string token, std::stack<float> *s1);

#endif