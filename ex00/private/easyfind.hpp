/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcourtoi <mcourtoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 15:07:07 by mcourtoi          #+#    #+#             */
/*   Updated: 2023/09/15 15:44:13 by mcourtoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class	NotFoundException : public std::exception
{
public:
	virtual char const	*what(void) const throw()
	{
		return "not found";
	}
};

template<typename T>
typename T::const_iterator	easyfind(T const &container, int const tofind)
{
	typename T::const_iterator	ret;

	ret = find(container.begin(), container.end(), tofind);
	if (ret == container.end())
		throw NotFoundException();
	return ret;
}

#endif
