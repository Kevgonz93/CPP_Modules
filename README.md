# 🧩 C++ Modules — 42 Madrid

> Progresión de los proyectos de C++ del cursus de 42.  
> Cada módulo introduce nuevos conceptos del paradigma orientado a objetos, desde lo más básico (CPP00) hasta la herencia múltiple, plantillas y excepciones.

---

## 📚 Progreso

| Módulo    | Tema principal                                                           | Estado        |
| :-------- | :----------------------------------------------------------------------- | :------------ |
| **CPP00** | Fundamentos de C++: namespaces, clases, `static`, `const`, streams       | ✅ Completado |
| **CPP01** | Referencias, punteros a miembros, `new` / `delete`, `this`               | ✅ Completado |
| **CPP02** | Sobrecarga de operadores, forma canónica ortodoxa                        | ✅ Completado |
| **CPP03** | Herencia simple y múltiple                                               | ✅ Completado |
| **CPP04** | Polimorfismo y clases abstractas (`virtual`, `override`, `pure virtual`) | 🔜 Próximo    |

---

## ⚙️ Compilación

Cada ejercicio incluye su propio **Makefile**.  
Compila desde el directorio del ejercicio, por ejemplo:

```bash
cd CPP03/ex02
make
./fragtrap
```

Los flags usados siguen las normas de 42:

```bash
-Wall -Wextra -Werror -std=c++98
```

---

## 🧠 Conceptos aprendidos hasta ahora

- **Fundamentos:** `std::cout`, `std::cin`, `std::string`
- **Clases y objetos:** constructores, destructores, encapsulación
- **Forma canónica ortodoxa:** `constructor`, `copy constructor`, `operator=`, `destructor`
- **Operadores sobrecargados:** `<<`, `+`, `-`, `*`, `/`, comparaciones
- **Herencia:** visibilidad (`public` / `protected`), sobreescritura, clases derivadas
- **Polimorfismo inicial:** llamadas a métodos de la clase base desde derivadas
- **Buena práctica:** separación `.hpp` / `.cpp`, inicialización de miembros, const-correctness

---

## 🧩 Estructura del repositorio

```
CPP_Modules/
├── cpp00/
│   ├── ex00/ → Megaphone
│   ├── ex01/ → My Awesome PhoneBook
│   ├── ex02/ → Account
│   ├── cpp00.pdf
│   └── notas.md
│
├── cpp01/
│   ├── ex00/ → BraiiiiiiinnnzzzZ
│   ├── ex01/ → Moar Brainz!
│   ├── ex02/ → HI THIS IS BRAIN
│   ├── ex03/ → Unnecessary Violence
│   ├── ex04/ → Sed is for losers
│   ├── ex05/ → Harl 2.0
│   ├── ex06/ → HarlFilter
│   └── cpp01.pdf
│
├── cpp02/
│   ├── ex00/ → My First Class (Fixed)
│   ├── ex01/ → Canonical Form
│   ├── ex02/ → Arithmetic Operators
│   ├── ex03/ → BSP (Point in Triangle)
│   └── cpp02.pdf
│
├── cpp03/
│   ├── ex00/ → ClapTrap
│   ├── ex01/ → ScavTrap
│   ├── ex02/ → FragTrap
│   ├── ex03/ → DiamondTrap
│   └── cpp03.pdf
│
├── cpp04/
│   └── (pendiente)
│
├── README.md
└── notas.md
```

---

## 👨‍💻 Autor

<p align="center">
  <b>Kevin Gonzales</b>  
  <br>Estudiante en <a href="https://www.42madrid.com">42 Madrid</a>  
  <br><a href="https://github.com/Kevgonz93">github.com/Kevgonz93</a>
</p>
