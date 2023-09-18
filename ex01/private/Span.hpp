/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 22:44:20 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/18 22:44:20 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# ifndef DEBUG
#  define DEBUG 0
# endif

# include <list>
# include <iostream>

class	Span
{
private :

	uint			_size;
	uint			_sizemax;
	std::list<int>	_list;

	class	AlreadyFullException : public std::exception
	{
	private :
		virtual char const	*what(void) const throw();
	};

	class	NoSpanException : public std::exception
	{
	private :
		virtual char const	*what(void) const throw();
	};

public :

	Span(uint const &size = 0);
	Span(Span const &src);

	virtual ~Span(void);

	uint const	&getSize(void) const;
	uint const	&getSizeMax(void) const;
	std::list const	&getList(void) const;

	void	addNumber(int const &n);
	
	uint const	shortestSpan(void) const;
	uint const	longestSpan(void) const;

	Span	&operator=(Span const &src);
};

std::ostream	&operator<<(std::ostream &o, Span const &src);

#endif
