/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:44:14 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/11 05:00:02 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

#define CYAN    "\033[36m"
#define RESET   "\033[0m"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : 	_name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap & src)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
	std::cout << *this << std::endl;
	return ;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
	std::cout << *this << std::endl;
	return ;
}

ClapTrap & ClapTrap::operator=(const ClapTrap & rhs)
{
	std::cout << "ClapTrap assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}
	return (*this);
}

void ClapTrap::attack(std::string const & target)
{
	if (this->_energyPoints > 0)
	{
		this->_energyPoints -= (this->_energyPoints > 0);
		std::cout	<< "The ClapTrap "
					<< this->_name
					<< " attacks " << target
					<< ", causing " << this->_attackDamage
					<< " points of damage!" << std::endl;
	}
	else
		std::cout	<< this->_name
					<< " is out of energy!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout	<< this->_name
				<< " takes " << amount
				<< " points of damage!" << std::endl;
	if (amount > this->_hitPoints)
		amount = this->_hitPoints;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints -= 1;
		std::cout	<< this->_name
					<< " is repaired by " << amount
					<< " points!" << std::endl;
	}
	else
		std::cout	<< this->_name
					<< " is out of energy!" << std::endl;
}

std::string ClapTrap::getName(void) const
{
	return (this->_name);
}

unsigned int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

unsigned int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

unsigned int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::setName(std::string name)
{
	this->_name = name;
	std::cout	<< this->_name
				<< " name changed to " << name << std::endl;
}

void ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
	std::cout 	<< this->_name
				<< " hit points set to " << hitPoints << std::endl;
}

void ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
	std::cout 	<< this->_name
				<< " energy points set to " << energyPoints << std::endl;
}

void ClapTrap::setAttackDamage(unsigned int attackDamage)
{
	this->_attackDamage = attackDamage;
	std::cout 	<< this->_name
				<< " attack damage set to " << attackDamage << std::endl;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & rhs)
{
	o	<< CYAN << rhs.getName() << ": "
		<< "HP: " << rhs.getHitPoints() << ", "
		<< "EP: " << rhs.getEnergyPoints() << ", "
		<< "AD: " << rhs.getAttackDamage() << RESET <<  std::endl;
	return (o);
}














