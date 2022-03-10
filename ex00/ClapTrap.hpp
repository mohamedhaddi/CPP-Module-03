/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaddi <mhaddi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:36:31 by mhaddi            #+#    #+#             */
/*   Updated: 2022/03/10 19:22:37 by mhaddi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ClapTrap
{

	private:

		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap & src);
		~ClapTrap(void);

		ClapTrap & operator=(const ClapTrap & rhs);

		void attack(const std::string & target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void) const;
		unsigned int getHitPoints(void) const;
		unsigned int getEnergyPoints(void) const;
		unsigned int getAttackDamage(void) const;

		void setName(std::string name);
		void setHitPoints(unsigned int hitPoints);
		void setEnergyPoints(unsigned int energyPoints);
		void setAttackDamage(unsigned int attackDamage);

};

std::ostream & operator<<(std::ostream & o, ClapTrap const & rhs);
