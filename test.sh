# mode to test file
cd ./ft_containers_tester

# vector test
cd ./vector
./vector_test.sh

printf "\n"
# map test
cd ../map
./map_test.sh

printf "\n"
# stack test
cd ../stack
./stack_test.sh

printf "\n"
# set test
cd ../set
./set_test.sh

printf "\n"
# performance test
cd ../performance
./performance_test.sh