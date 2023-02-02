NAME := ft_container

SRCS := main.cpp

OBJS := $(SRCS=.cpp=.o)
DEPS := $(SRCS:.cpp=.d)

FT := ft
FT_DIR := ./ft
FT_LD := -L$(FT_DIR) -l$(FT)

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -I$(FT_DIR) -MMD
LDFLAGS := $(FT_LD)

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
