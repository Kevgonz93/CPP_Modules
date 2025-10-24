#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
    if (argc < 2) 
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) 
    {
        for (int j = 0; argv[i][j]; j++) 
        {
            std::cout << static_cast<char>(std::toupper(argv[i][j]));
            if (argv[i][j + 1] == '\0' && i < argc - 1)
                std::cout << " ";
        }
    }
    std::cout << std::endl;
    return 0;
}
