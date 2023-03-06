#!/bin/bash

TEST_NUM=3

make -s
make -s clean
make -s std

printf "\033[0;35mset test\033[0;0m\n"
if [ ! -e logs ] ; then
	mkdir logs
fi

for ((i = 1; i <= TEST_NUM; i++))
do
	./ft_containers < "./test_cases/case$i" > "./logs/ft_output$i"
	./std_containers < "./test_cases/case$i" > "./logs/std_output$i"
	diff "./logs/ft_output$i" "./logs/std_output$i" > "./logs/diff$i"

	if [ -s "./logs/diff$i" ] ; then
		printf "\033[0;31mcase $i FAIL \033[0;0m\n"
	else
		printf "\033[0;32mcase $i OK \033[0;0m\n"
		rm "./logs/ft_output$i" "./logs/std_output$i" "./logs/diff$i"
	fi
done

make -s fclean
