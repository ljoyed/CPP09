NAME = RPN

CXX = c++

CFLAGS = -Werror -Wall -Wextra -std=c++98 #-fsanitize=address

RM = rm -rf

SRCS = 	main.cpp\
		RPN.cpp\

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n-----Compiled Successfully------\n"
	@sleep 1
	@clear

fclean : clean
	$(RM) $(NAME)
	@clear

clean :
	$(RM) $(OBJS)

re : fclean all clean