/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmethakan <ahmethakan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 04:20:43 by aakpinar          #+#    #+#             */
/*   Updated: 2026/02/08 11:19:28 by ahmethakan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <string>

class Weapon
{
  public:
	Weapon(const std::string &type);
	const std::string &getType() const;
	void setType(const std::string &newType);

  private:
	std::string _type;
};

#endif 
