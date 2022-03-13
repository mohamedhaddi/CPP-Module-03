/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:44:14 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/11 05:31:24 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_H
# define SCAVTRAP_H

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
{
	std::cout << "ScavTrap default constructor called" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
	std::cout << "ScavTrap constructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap & src)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = src;
	std::cout << *this << std::endl;
	return ;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & rhs)
{
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ScavTrap::attack(std::string const & target)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= 1;
		std::cout	<< this->_name
					<< " hits " << target
					<< ", causing " << this->_attackDamage
					<< " points of damage!" << std::endl;
	}
	else
		std::cout	<< this->_name
					<< " has no energy left!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout	<< this->_name
				<< " is now in Gate keeper mode."
				<< std::endl;
}

#endif
