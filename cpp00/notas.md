# 🧱 CPP Module 00 — Apuntes

**Temas:** Namespaces · Clases · Funciones miembro · Flujos `iostream` · Listas de inicialización · `static` · `const` · Fundamentos de C++98.

## 🧠 Conceptos esenciales que debes entender

### 🔹 Namespaces

Permiten agrupar nombres (funciones, clases, variables) y evitar conflictos.

```cpp
namespace megaphone {
    void shout() { std::cout << "HELLO!" << std::endl; }
}

int main() {
    megaphone::shout();
}
```

⚠️ No usar using namespace std; en este módulo.

---

### 🔹 Flujos de entrada/salida (iostream)

Sustituyen a las funciones de C (printf, scanf).

```cpp
#include <iostream>

int main(int argc, char **argv)
{
    //crear variable
    std::string name;
    //imprimir en consola
    std::cout << "Enter your name: ";
    // leer de consola
    std::cin >> name;
    // imprimir en consola con nombre (variable creada)
    std::cout << "Hello, " << name << "!" << std::endl;
    //std::endl agrega un salto de linea
    return 0;
}
```

📌 Usa std::cout, std::cin, std::endl.

---

### 🔹 Clases y objetos

Base de la Programación Orientada a Objetos (POO).

```cpp
class Contact {
private:
    std::string name;
    std::string phone;
public:
    void setName(std::string n) { name = n; }
    std::string getName() const { return name; }
};
```

- private → solo accesible dentro de la clase
- public → accesible desde fuera
- const → garantiza que la función no modifica el objeto

---

### 🔹 Constructores, destructores e inicialización

```cpp
class Contact {
public:
    Contact() { std::cout << "Created!" << std::endl; }
    ~Contact() { std::cout << "Destroyed!" << std::endl; }
};
```

Listas de inicialización:

```cpp
Contact(std::string n, std::string p) : name(n), phone(p) {}
```

---

### 🔹 Atributos y funciones static

- Atributo static: compartido entre todas las instancias.
- Función static: se puede llamar sin crear un objeto.

```cpp
class Account {
private:
    static int _nbAccounts;
public:
    static int getNbAccounts() { return _nbAccounts; }
};
```

---

### 🔹 const correctness

Garantiza que una función no modifica el estado del objeto.

```cpp
int getAge() const;
```

---

### 🔹 Compilación y Makefile

Compilar siempre con:

```cpp
c++ -Wall -Wextra -Werror -std=c++98
```

Ejemplo de Makefile:

```Makefile
NAME = megaphone
SRC = megaphone.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)
$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
```

---

## 🧩 Conceptos por ejercicio

| Ejercicio                         | Conceptos clave                                                                                                                                                                                                                                                   |
| --------------------------------- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| **ex00 – Megaphone**              | `argc` y `argv`, bucles `for`, `std::string`, funciones de `<cctype>` como `toupper()`, uso de `std::cout` y `std::endl`.                                                                                                                                         |
| **ex01 – My Awesome PhoneBook**   | Clases, arrays fijos, entrada de texto con `std::getline`, truncado de strings con `substr`, formateo de columnas con `<iomanip>`, uso de `const` en funciones, control de flujo básico (`if`/`else`, `switch`).                                                  |
| **ex02 – The Job Of Your Dreams** | Clases con métodos y variables `static`, constructores y destructores, listas de inicialización, funciones miembro `const`, manejo de timestamps con `<ctime>`, encapsulación y seguimiento de estado global (número total de cuentas, depósitos, retiros, etc.). |

## 🧩 Const vs Static

| Palabra clave               | Qué hace                           | Ejemplo                     |
| --------------------------- | ---------------------------------- | --------------------------- |
| `const`                     | Evita modificaciones               | `int getAge() const;`       |
| `static` (variable miembro) | Compartida entre todos los objetos | `static int total;`         |
| `static` (función)          | Puede llamarse sin crear objeto    | `Account::getNbAccounts();` |
| `const` + `static`          | Valor constante global de clase    | `static const int MAX = 8;` |

## ⚔️ Diferencias entre C y C++

| Aspecto                 | C                    | C++                                |
| ----------------------- | -------------------- | ---------------------------------- |
| Paradigma               | Procedural           | Orientado a objetos                |
| Entrada/Salida          | `printf`, `scanf`    | `std::cout`, `std::cin`            |
| Estructuras             | `struct` sin métodos | `class` con funciones miembro      |
| Memoria dinámica        | `malloc` / `free`    | `new` / `delete`                   |
| Encapsulación           | No existe            | `public` / `private` / `protected` |
| Sobrecarga de funciones | No                   | Sí                                 |
| Archivos típicos        | `.h` / `.c`          | `.hpp` / `.cpp`                    |

## 📏 Buenas prácticas

- No pongas código en headers (.hpp) salvo templates.
- Evita leaks de memoria.
- Usa nombres descriptivos y consistentes.
- Evita funciones de C (printf, malloc, free, etc.).
- Cada header debe poder compilar de forma independiente.
- Usa include guards:

```cpp
#ifndef CONTACT_HPP
 #define CONTACT_HPP

#endif
```

---

## 🚀 Consejos finales

- Piensa en C++ como C con superpoderes: aprovecha clases, encapsulación y iostream.
- Practica con ejemplos pequeños antes de los ejercicios.
- Usa std::cerr para mensajes de debug temporales.
- Asegúrate de que tu código compila limpio, sin warnings.
- Lee el subject completo antes de empezar cada ejercicio.
- Y recuerda: ¡por Odín, usa tu cerebro!
