/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:59:21 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/11 05:09:01 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	ClapTrap foo("foo");
	ScavTrap bar("bar");
	
	foo.setAttackDamage(7);

	std::cout << std::endl << foo << bar << std::endl;

	foo.attack(bar.getName());
	bar.takeDamage(foo.getAttackDamage());

	std::cout << std::endl << foo << bar << std::endl;

	bar.beRepaired(5);

	std::cout << std::endl << foo << bar << std::endl;

	bar.guardGate();

	return (0);
}

