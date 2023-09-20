/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:00:14 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/20 19:00:14 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "MutantStack.hpp"

static void	__test0(void)
{
	MutantStack<int>			mut;
	std::list<int>				lst;
	MutantStack<int>::iterator	iter0;
	std::list<int>::iterator	iter1;
	int							i;

	for (i = 0 ; i < 10 ; ++i)
	{
		mut.push(i);
		lst.push_back(i);
	}
	std::cout << "mut: {";
	iter0 = mut.begin();
	while (iter0 != mut.end())
	{
		std::cout << *iter0;
		if (++iter0 != mut.end())
			std::cout << ", ";
	}
	std::cout << "}" << '\n'
	<< "lst: {";
	iter1 = lst.begin();
	while (iter1 != lst.end())
	{
		std::cout << *iter1;
		if (++iter1 != lst.end())
			std::cout << ", ";
	}
	std::cout << "}" << '\n';
}

static void	__test1(void)
{
	MutantStack<int>			mut;
	std::vector<int>			vec;
	MutantStack<int>::iterator	iter0;
	std::vector<int>::iterator	iter1;
	int							i;

	for (i = 0 ; i < 10 ; ++i)
	{
		mut.push(i * i);
		vec.push_back(i * i);
	}
	std::cout << "mut: {";
	iter0 = mut.begin();
	while (iter0 != mut.end())
	{
		std::cout << *iter0;
		if (++iter0 != mut.end())
			std::cout << ", ";
	}
	std::cout << "}" << '\n'
	<< "vec: {";
	iter1 = vec.begin();
	while (iter1 != vec.end())
	{
		std::cout << *iter1;
		if (++iter1 != vec.end())
			std::cout << ", ";
	}
	std::cout << "}" << '\n';
}

static void	__test2(void)
{
	MutantStack<int>			mut;
	std::deque<int>				deq;
	MutantStack<int>::iterator	iter0;
	std::deque<int>::iterator	iter1;
	int							i;

	for (i = 0 ; i < 10 ; ++i)
	{
		mut.push(i * 3 + 1);
		deq.push_back(i * 3 + 1);
	}
	std::cout << "mut: {";
	iter0 = mut.begin();
	while (iter0 != mut.end())
	{
		std::cout << *iter0;
		if (++iter0 != mut.end())
			std::cout << ", ";
	}
	std::cout << "}" << '\n'
	<< "deq: {";
	iter1 = deq.begin();
	while (iter1 != deq.end())
	{
		std::cout << *iter1;
		if (++iter1 != deq.end())
			std::cout << ", ";
	}
	std::cout << "}" << '\n';
}

int main(void)
{
	std::cout << "Test 0 : -----------------------------------------------" << '\n';
	__test0();
	std::cout << "Test 1 : -----------------------------------------------" << '\n';
	__test1();
	std::cout << "Test 2 : -----------------------------------------------" << '\n';
	__test2();
	return (0);
}
