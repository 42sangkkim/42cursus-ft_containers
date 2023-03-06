#!/bin/bash

TEST_NUM=3

make -s
make -s clean
make -s std

printf "\033[0;35mperfoemance test\033[0;0m\n"

printf "\033[0;33mperformance of ft_containers\033[0;0m"
time (./ft_containers "sangkkim" > ft_out)
printf "\033[0;33mperformance of std_containers\033[0;0m"
time (./std_containers "sangkkim" > std_out)

rm ft_out std_out
make -s fclean
