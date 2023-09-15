/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:41:06 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/15 15:47:58 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <vector>
#include "easyfind.hpp"

static void	__test0(void)
{
	std::list<int>					lst;
	std::list<int>::const_iterator	iter;
	int								i;

	try
	{
		for (i = 0 ; i < 10 ; ++i)
			lst.push_back(i);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	for (iter = lst.begin() ; iter != lst.end() ; ++iter)
		std::cout << *iter << ": " << &*iter << '\n';
	std::cout << '\n';
	i = 5;
	try
	{
		iter = easyfind(lst, i);
		std::cout << *iter << ": " << &*iter << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << i << ": " << e.what() << '\n';
	}
}

static void	__test1(void)
{
	std::vector<int>					vec;
	std::vector<int>::const_iterator	iter;
	int									i;

	try
	{
		for (i = 0 ; i < 10 ; ++i)
			vec.push_back(i);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	for (iter = vec.begin() ; iter != vec.end() ; ++iter)
		std::cout << *iter << ": " << &*iter << '\n';
	std::cout << '\n';
	i = 9;
	try
	{
		iter = easyfind(vec, i);
		std::cout << *iter << ": " << &*iter << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << i << ": " << e.what() << '\n';
	}
}

static void	__test2(void)
{
	std::deque<int>					deq;
	std::deque<int>::const_iterator	iter;
	int								i;

	try
	{
		for (i = 0 ; i < 10 ; ++i)
			deq.push_back(i);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	for (iter = deq.begin() ; iter != deq.end() ; ++iter)
		std::cout << *iter << ": " << &*iter << '\n';
	std::cout << '\n';
	i = 404;
	try
	{
		iter = easyfind(deq, i);
		std::cout << *iter << ": " << &*iter << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << i << ": " << e.what() << '\n';
	}
}

int	main(void)
{
	__test0();
	std::cout << "-----------------------------------------------" << '\n';
	__test1();
	std::cout << "-----------------------------------------------" << '\n';
	__test2();
	return EXIT_SUCCESS;
}
