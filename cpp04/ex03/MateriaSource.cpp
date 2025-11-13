#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; i++)
		materia[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & other) {
	for (int i = 0; i < 4; i++) {
		if (other.materia[i])
			materia[i] = other.materia[i]->clone();
		else
			materia[i] = NULL;
	}
}

MateriaSource & MateriaSource::operator=(MateriaSource const & other) {
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (materia[i])
				delete materia[i];
			if (other.materia[i])
				materia[i] = other.materia[i]->clone();
			else
				materia[i] = NULL;
		}
	}
	return *this;
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; i++) {
		if (materia[i])
			delete materia[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; i++) {
		if (!materia[i]) {
			materia[i] = m->clone();
			delete m;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (materia[i] && materia[i]->getType() == type)
			return materia[i]->clone();
	}
	return NULL;
}
