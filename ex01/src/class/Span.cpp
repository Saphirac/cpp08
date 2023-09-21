/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:59:25 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/18 22:59:25 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstdlib>
#include <climits>
#include <algorithm>

// Constructors and destructor //

Span::Span(uint const &n) :
_size(0),
_sizemax(n),
_list()
{
	if (DEBUG)
		std::cout << "Span constructor called\n";
}

Span::Span(Span const &src) :
_size(src._size),
_sizemax(src._sizemax),
_list(src._list)
{
	if (DEBUG)
		std::cout << "Span copy constructor called\n";
}

Span::~Span()
{
	if (DEBUG)
		std::cout << "Span destructor called\n";
}

// Accessors //

uint const	&Span::getSize(void) const
{
	if (DEBUG)
		std::cout << "Span getSize() accessor called\n";
	return this->_size;
}

uint const	&Span::getSizeMax(void) const
{
	if (DEBUG)
		std::cout << "Span getSizeMax() accessor called\n";
	return this->_sizemax;
}

std::list<int> const	&Span::getList(void) const
{
	if (DEBUG)
		std::cout << "Span getList() accessor called\n";
	return this->_list;
}

// Exceptions //

char const	*Span::AlreadyFullException::what() const throw()
{
	if (DEBUG)
		std::cout << "Span alreadyFullException thrown\n";
	return "Span is already full";
}

char const	*Span::NoSpanException::what() const throw()
{
	if (DEBUG)
		std::cout << "Span NoSpanException thrown\n";
	return "Can't get span";
}

// Mandatory functions //

void	Span::addNumber(int const &n)
{
	if (DEBUG)
		std::cout << "Span addnumber() member function called\n";
	if (this->_size == this->_sizemax)
		throw Span::AlreadyFullException();
	this->_list.push_back(n);
	++this->_size;
}
	
uint	Span::shortestSpan(void) const
{
	if (DEBUG)
		std::cout << "Span shortestSpan() member function called\n";
	if (this->_size < 2)
		throw Span::NoSpanException();
	
	uint							ret(UINT_MAX);
	std::list<int>::const_iterator	i = this->_list.begin();
	std::list<int>::const_iterator	j = ++this->_list.begin();
	int								a;
	int								b;

	while (i != this->_list.end())
	{
		a = *i;
		while (j != this->_list.end())
		{
			b = *j;
			if (static_cast<uint>(a - b) < ret)
				ret = abs(a - b);
			j++;
		}
		j = ++i;
		j++;
	}
	return ret;
}

uint	Span::longestSpan(void) const
{
	if (DEBUG)
		std::cout << "Span longestSpan() member function called\n";
	if (this->_size < 2)
		throw Span::NoSpanException();
	return *std::max_element(this->_list.begin(), this->_list.end()) - *std::min_element(this->_list.begin(), this->_list.end());
}

void	Span::addRange(std::list<int>::const_iterator itBegin, std::list<int>::const_iterator itEnd)
{
	if (std::distance(itBegin, itEnd) + this->_size > this->_sizemax)
		throw Span::AlreadyFullException();
	this->_list.insert(this->_list.end(), itBegin, itEnd);
	this->_size += std::distance(itBegin, itEnd);
}

// Operators //

Span	&Span::operator=(Span const &src)
{
	if (DEBUG)
		std::cout << "Span copy operator called\n";
	if (this != &src)
	{
		this->_size = src._size;
		this->_sizemax = src._sizemax;
		this->_list = src._list;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &o, Span const &src)
{
	std::list<int>::const_iterator	iter;

	o << "Span\n" << "\t" "size: " << src.getSize() << '\n'
	<< "\t" "maxSize: " << src.getSizeMax() << '\n'
	<< "\t" "list: {";
	iter = src.getList().begin();
	while (iter != src.getList().end())
	{
		o << *iter;
		if (++iter != src.getList().end())
			o << ", ";
	}
	o << "}\n";
	return o;
}
