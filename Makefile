NAME := ft_container

SRCS := main.cpp

OBJS := $(SRCS:.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

FT_DIR := ./ft

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -I$(FT_DIR) -MMD

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS)

-include $(DEPS)

.PHONY : all clean flcean re

all : $(NAME)

clean :
	$(RM) $(OBJS)
	$(RM) $(DEPS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
