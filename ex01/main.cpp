/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loandrad <loandrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:53:58 by loandrad          #+#    #+#             */
/*   Updated: 2024/06/20 13:49:03 by loandrad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[])
{
    std::string temp;
    float result = 0;
    std::stack<float> s1;
    if (argc < 2)
    {
        std::cout << USAGE << std::endl;
        std::cout << EXAMPLE << std::endl;
        return (1);
    }
    if (checkValidity(argv[1]))
        return (1);
    std::cout << calculate(&s1, argv[1]) << std::endl;
    return 0;
}