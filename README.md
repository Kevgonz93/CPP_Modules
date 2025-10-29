# 🧩 C++ Modules — 42 Madrid

> Progresión de los proyectos de C++ del cursus de 42.  
> Cada módulo introduce nuevos conceptos del paradigma orientado a objetos, desde lo más básico (CPP00) hasta la herencia múltiple, plantillas y excepciones.

---

## 📘 Módulo actual

### **CPP00 — My First Class in C++**

> Namespaces, clases, funciones miembro, `static`, `const` y streams (`std::cout`, `std::cin`).

#### 🗂️ Estructura

```
CPP00/
├── ex00/  → Megaphone
├── ex01/  → My Awesome PhoneBook
└── ex02/  → The Job of Your Dreams
```

#### 📋 Ejercicios

| Ejercicio | Nombre                 | Conceptos clave                                                                        |
| :-------- | :--------------------- | :------------------------------------------------------------------------------------- |
| **ex00**  | `megaphone`            | argumentos de programa, `std::toupper`, bucles, `argv`/`argc`                          |
| **ex01**  | `My Awesome PhoneBook` | clases, métodos, arrays de objetos, entrada/salida con `std::getline`                  |
| **ex02**  | `Account`              | clases, métodos estáticos, listas de inicialización, `const`, `std::vector`, timestamp |

---

## ⚙️ Compilación

Cada ejercicio incluye su propio **Makefile**.  
Compila desde el directorio del ejercicio, por ejemplo:

```bash
cd CPP00/ex02
make
./account
```

Los flags usados siguen las normas de 42:

```bash
-Wall -Wextra -Werror -std=c++98
```

## 🧠 Conceptos aprendidos

    •	std::cout / std::cin / std::string
    •	Clases y objetos (class, atributos privados)
    •	Funciones miembro y listas de inicialización
    •	Variables y métodos static
    •	Calificación const para funciones miembro
    •	Formato de salida (std::setw, std::setfill)
    •	Tipos y plantillas básicas (std::vector, std::pair, std::for_each)

## 🚀 Próximos pasos

- [x] **CPP00** – Fundamentos de C++: namespaces, clases, `static`, `const`, streams
- [ ] **CPP01** – Referencias, punteros a miembros, `new` / `delete`, `this`
- [ ] **CPP02** – Sobrecarga de operadores, forma canónica ortodoxa
- [ ] **CPP03–CPP09** – Herencia, polimorfismo, excepciones, plantillas, STL

## 👨‍💻 Autor

<p align="center">
  <b>Kevin Gonzales</b>  
  <br>Estudiante en <a href="https://www.42madrid.com">42 Madrid</a>  
  <br><a href="https://github.com/Kevgonz93">github.com/Kevgonz93</a>
</p>
