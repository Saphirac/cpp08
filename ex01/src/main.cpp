/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:40:30 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/18 23:40:30 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <ctime>

static void	__test0(void)
{
	Span	sp(5);
	int		i;

	for (i = 0 ; i < 5 ; ++i)
		try
		{
			sp.addNumber(i);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << '\n';
		}
	std::cout << sp << '\n';
}

static void	__test1(void)
{
	Span	sp(2);
	int		i;

	for (i = 0 ; i < 5 ; ++i)
		try
		{
			sp.addNumber(i);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << '\n';
		}
	std::cout << sp << '\n';
}

static void	__test2(void)
{
	Span	sp(10);
	uint	range;
	int		i;

	for (i = 0 ; i < 10 ; ++i)
		try
		{
			sp.addNumber(i * 42);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << '\n';
		}
	std::cout << sp << '\n';
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
}

static void	__test3(void)
{
	Span	sp;
	uint	range;

	std::cout << sp << '\n';
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
}

static void	__test4(void)
{
	Span	sp(1);
	uint	range;

	try
	{
		sp.addNumber(42);
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	std::cout << sp << '\n';
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
}

static void	__test5(void)
{
	Span	sp(100);
	uint	range;

	for (int i = 0 ; i < 100; ++i)
		try
		{
			sp.addNumber(rand() % 10000);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << '\n';
		}
	std::cout << sp;
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
}

static void	__test6(void)
{
	Span	sp(10);
	Span	insert(5);
	uint	range;

	for (int i = 0 ; i < 5 ; ++i)
		try
		{
			sp.addNumber(i);
			insert.addNumber(i + 5);
		}
		catch (std::exception const &e)
		{
			std::cout << e.what() << '\n';
		}
	std::list<int>::const_iterator	itBegin = insert.getList().begin();
	std::list<int>::const_iterator	itEnd = insert.getList().end();
	std::cout << sp << '\n';
	std::cout << insert << '\n';
	try
	{
		sp.addRange(itBegin, itEnd);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << sp << '\n';
	try
	{
		sp.addRange(itBegin, itEnd);
	}
	catch(std::exception const &e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		range = sp.longestSpan();
		std::cout << "Longest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
	try
	{
		range = sp.shortestSpan();
		std::cout << "Shortest: " << range << '\n';
	}
	catch (std::exception const &e)
	{
		std::cout << e.what() << '\n';
	}
}

int	main(void)
{
	srand(std::time(NULL));
	std::cout << "Test 0 : -----------------------------------------------\n";
	__test0();
	std::cout << "\nTest 1 : -----------------------------------------------\n";
	__test1();
	std::cout << "\nTest 2 : -----------------------------------------------\n";
	__test2();
	std::cout << "\nTest 3 : -----------------------------------------------\n";
	__test3();
	std::cout << "\nTest 4 : -----------------------------------------------\n";
	__test4();
	std::cout << "\nTest 5 : -----------------------------------------------\n";
	__test5();
	std::cout << "\nTest 6 : -----------------------------------------------\n";
	__test6();
	return EXIT_SUCCESS;
}
