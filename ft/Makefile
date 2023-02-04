NAME := ft_container

SRCS := \
		vector/vector.tpp \
		vector/iterator.tpp \
		map/map.tpp \
		map/iterator.tpp \
		stack/stack.tpp \
		stack/iterator.tpp \
		iterator_trais.tpp \
		reverse_iterator.tpp \
		enable_if.tpp \
		is_integral.tpp \
		equal.tpp \
		lexicographical_compare.tpp \
		pair.tpp \
		make_pair.tpp \

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
