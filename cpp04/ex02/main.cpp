#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

int main() {
	std::cout << "\n=== Test 1: Instanciación directa ===" << std::endl;
	// ❌ Esto debe dar error si descomentas:
	// Animal a;             // Error: cannot declare variable ‘a’ to be of abstract type ‘Animal’
	// Animal* ptr = new Animal(); // Error también

	std::cout << "\n=== Test 2: Instanciación de clases derivadas ===" << std::endl;
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << "\n=== Test 3: Polimorfismo ===" << std::endl;
	dog->makeSound(); // debe imprimir "Woof!"
	cat->makeSound(); // debe imprimir "Meow!"

	std::cout << "\n=== Test 4: Array de punteros a Animal ===" << std::endl;
	const Animal* animals[4];
	for (int i = 0; i < 4; i++) {
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "\n--- Llamando makeSound() en bucle ---" << std::endl;
	for (int i = 0; i < 4; i++)
		animals[i]->makeSound();

	std::cout << "\n=== Test 5: Liberando memoria ===" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "\n=== Test 6: Copia profunda ===" << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
		std::cout << "Fin del bloque interno -> tmp se destruye" << std::endl;
	}

	std::cout << "\n=== Test 7: Destructores finales ===" << std::endl;
	delete dog;
	delete cat;

	std::cout << "\n=== Fin del programa ===" << std::endl;
	return 0;
}
