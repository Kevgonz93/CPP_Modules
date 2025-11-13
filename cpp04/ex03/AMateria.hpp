#ifndef MATERIA_HPP
#define MATERIA_HPP

#include <string>

class AMateria {
	protected :
		std::string type;
	public :
		AMateria();
		AMateria(std::string const & type);
		virtual ~AMateria();

		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(class ICharacter& target);
};

#endif
