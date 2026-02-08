/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmethakan <ahmethakan@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 04:20:46 by aakpinar          #+#    #+#             */
/*   Updated: 2026/02/08 11:34:59 by ahmethakan       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(const std::string type) : _type(type) {}

const std::string &Weapon::getType() const
{
    return _type;
}

void Weapon::setType(const std::string newType)
{
    _type = newType;
}