NAME := ft_containers
STD_NAME := std_containers

SRCS := main.cpp

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

FT_DIR := ../../

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -MMD -I $(FT_DIR)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

.PHONY : all clean flcean re std

all : $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)
	$(RM) $(STD_NAME)

re : fclean all

std :
	make "NAME := $(STD_NAME)" "CPPFLAGS = -MMD -D STD_TEST" all