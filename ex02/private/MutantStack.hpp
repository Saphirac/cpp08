/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:00:24 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/20 19:00:24 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>

# ifndef DEBUG
#  define DEBUG 0
# endif

template <typename T>
class	MutantStack : public std::stack<T>
{
	public:
	typedef typename std::stack<T>::container_type::iterator		iterator;
	typedef typename std::stack<T>::container_type::const_iterator	const_iterator;

	// Constructors
	MutantStack<T>(void)
	{
		if (DEBUG)
			std::cout << "MutantStack default constructor called\n";
	}

	MutantStack<T>(MutantStack<T> const &src) :
	std::stack<T>(src)
	{
		if (DEBUG)
			std::cout << "MutantStack copy constructor called\n";
	}

	// Destructors
	virtual ~MutantStack<T>(void)
	{
		if (DEBUG)
			std::cout << "MutantStack destructor called\n";
	}

	// Member functions
	iterator		begin(void)
	{
		if (DEBUG)
			std::cout << "MutantStack iterator begin() function called\n";		
		return this->c.begin();
	}

	iterator		end(void)
	{
		if (DEBUG)
			std::cout << "MutantStack iterator end() function called\n";
		return this->c.end();
	}

	const_iterator	begin(void) const
	{
		if (DEBUG)
			std::cout << "MutantStack const_iterator begin() function called\n";
		return this->c.begin();
	}

	const_iterator	end(void) const
	{
		if (DEBUG)
			std::cout << "MutantStack const_iterator end() function called\n";
		return this->c.end();
	}

	// Operators
	MutantStack<T>	&operator=(MutantStack<T> const &src)
	{
		if (DEBUG)
			std::cout << "MutantStack copy operator called\n";
		return	std::stack<T>::operator=(src);
	}
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, MutantStack<T> const &src)
{
	MutantStack<int>::const_iterator	iter;

	o << "MutantStack:" << '\n';
	for (iter = src.begin(); iter != src.end(); ++iter)
		o << "\t" << *iter << ": " << &*iter << '\n';
	return o;
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, typename MutantStack<T>::iterator const &src)
{
	o << "MutantStack::iterator:" << '\n'
	<< "\t" "*src: " << *src << '\n'
	<< "\t" "&*src: " << &*src << '\n';
	return o;
}

template <typename T>
std::ostream	&operator<<(std::ostream &o, typename MutantStack<T>::const_iterator const &src)
{
	o << "MutantStack::const_iterator:" << '\n'
	<< "\t" "*src: " << *src << '\n'
	<< "\t" "&*src: " << &*src << '\n';
	return o;
}


#endif
