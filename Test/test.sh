#!/bin/bash

g++ $1 -std=c++17 -O3 -o test_sh_program_1
g++ $2 -std=c++17 -O3 -o test_sh_program_2

./test_sh_program_1 < $3 > test_sh_output_1.txt
./test_sh_program_2 < $3 > test_sh_output_2.txt

diff test_sh_output_1.txt test_sh_output_2.txt

if [ $? -eq 0 ]; then
	echo "AC"
else
	echo "WA"
fi

rm test_sh_program_1
rm test_sh_program_2
rm test_sh_output_1.txt
rm test_sh_output_2.txt

