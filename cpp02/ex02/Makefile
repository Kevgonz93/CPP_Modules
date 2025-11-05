NAME = MyFirstClassinOCF
SRCS = main.cpp Fixed.cpp
OBJS = $(SRCS:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f
INCLUDES = -I.

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
