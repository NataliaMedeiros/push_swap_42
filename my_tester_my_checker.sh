#!/bin/bash
BOLD=$(tput bold)
RESET=$(tput sgr0)

red_color(){
	printf "\033[0;31m%s\033[0m" "$1"
}

# Função para colorir o texto em verde
green_color(){
	printf "\033[0;32m%s\033[0m" "$1"
}

yellow_color(){
	printf "\033[0;33m%s\033[0m" "$1"
}

execute_test(){
	checker_output=$(./push_swap "$ARG" | ./checker "$ARG")

	if [ "$checker_output" = "OK" ]; then
		green_color "OK"
	else
		red_color "KO"
	fi
	./push_swap "$ARG" | wc -l | tr -d '\n' ; printf " op;   "
}

make re
make bonus

echo ""
echo ""
echo "Test edges cases - no number - Should display ERROR"
echo "-----"
yellow_color "1:"; ARG="a b c d e f g h i"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "2:"; ARG="1 2 9 3 a"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "3:"; ARG="8 2 4 avocado 5 10 29"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "4:"; ARG=" ++4 5 6 2"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "5:"; ARG="\ 5 8 2 "; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "6:"; ARG="? 0 2 5 1"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "7:"; ARG="-10 10 +5 3 --8 -5"; ./push_swap $ARG | ./checker $ARG
yellow_color "8:"; ARG="10 ++5 3 8 4 5 11 21 105"; ./push_swap $ARG | ./checker $ARG
yellow_color "10:"; ARG="1111 / 1114 1115 1116 111117 1111"; ./push_swap $ARG | ./checker $ARG
yellow_color "11:"; ARG="10 + 5 3 8 4 5 11 21 105"; ./push_swap $ARG | ./checker $ARG
yellow_color "12:"; ARG="10 5 3 8 4 5 11 21 105 -"; ./push_swap $ARG | ./checker $ARG

echo ""
echo "Test edges cases - doubles - Should display ERROR"
echo "-----"
yellow_color "1:"; ARG="2 9 5 10 39 +2"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "2:"; ARG="109 1124 32 -32 1124 1 0 45"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "3:"; ARG="10 10 5 3 8 -5"; ./push_swap $ARG | ./checker $ARG
yellow_color "4:"; ARG="10 5 3 8 4 5 11 21 105"; ./push_swap $ARG | ./checker $ARG
yellow_color "5:"; ARG="1111 1114 1115 1116 111117 1111"; ./push_swap $ARG | ./checker $ARG

echo ""
echo "Test edges cases - limites - Should display ERROR"
echo "-----"
yellow_color "1:"; ARG="2147483647 2147483648 2147483645"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "2:"; ARG="-2147483649 -2147483648"; ./push_swap "$ARG" | ./checker "$ARG"
yellow_color "3:"; ARG="10 3 2147483648 4 5 11 21 105"; ./push_swap $ARG | ./checker $ARG
yellow_color "4:"; ARG="1111 1114 1115 1116 3147483647 1111"; ./push_swap $ARG | ./checker $ARG
yellow_color "5:"; ARG="10 5 3 8 4 5 11 21 105 2147483650"; ./push_swap $ARG | ./checker $ARG
yellow_color "6:"; ARG="1111 1114 1115 1116 -3147483647 1111"; ./push_swap $ARG | ./checker $ARG
yellow_color "7:"; ARG="10 5 3 8 4 5 11 21 105 -2147483650"; ./push_swap $ARG | ./checker $ARG

echo ""
echo "Test edges cases - Should be fine"
echo "-----"
yellow_color "1:"; ARG="+1 -1 +2 -2 +9"; execute_test "ARG"
yellow_color "2:"; ARG="2147483647 2147483640 2147483645"; execute_test "ARG"
yellow_color "3:"; ARG="-2147483648 -2147483647 -2147483645"; execute_test "ARG"
yellow_color "4:"; ARG="2147483647"; execute_test "ARG"
yellow_color "5:"; ARG="10 3 -2147483648 4 5 11 21 105" ; execute_test "ARG"



echo ""
echo "Test for 3 numbers"
echo "-----"
numbers=("1 2 3" "1 2 4" "1 3 2" "1 3 4" "1 4 2" "1 4 3" "2 1 3" "2 1 4" "2 3 1" "2 3 4" "2 4 1" "2 4 3" "3 1 2" "3 1 4" "3 2 1" "3 2 4" "3 4 1" "3 4 2" "4 1 2" "4 1 3" "4 2 1" "4 2 3" "4 3 1" "4 3 2")

for ARG in "${numbers[@]}"; do
	execute_test "ARG"
done

echo ""
echo "Test for 4 numbers"
echo "-----"
numbers4=("1 2 3 4" "1 2 4 3" "1 3 2 4" "1 3 4 2" "1 4 2 3" "1 4 3 2" "2 1 3 4" "2 1 4 3" "2 3 1 4" "2 3 4 1" "2 4 1 3" "2 4 3 1" "3 1 2 4" "3 1 4 2" "3 2 1 4" "3 2 4 1" "3 4 1 2" "3 4 2 1" "4 1 2 3" "4 1 3 2" "4 2 1 3" "4 2 3 1" "4 3 1 2" "4 3 2 1")
for ARG in "${numbers[@]}"; do
	execute_test "ARG"
done

echo ""
echo "Test for 5 numbers"
echo "-----"
numbers4=("1 2 3 4 5" "1 2 3 5 4" "1 2 4 3 5" "1 2 4 5 3" "1 2 5 3 4" "1 2 5 4 3" "1 3 2 4 5" "1 3 2 5 4" "1 3 4 2 5" "1 3 4 5 2" "1 3 5 2 4" "1 3 5 4 2" "1 4 2 3 5" "1 4 2 5 3" "1 4 3 2 5" "1 4 3 5 2" "1 4 5 2 3" "1 4 5 3 2" "1 5 2 3 4" "1 5 2 4 3" "1 5 3 2 4" "1 5 3 4 2" "1 5 4 2 3" "1 5 4 3 2" "2 1 3 4 5" "2 1 3 5 4" "2 1 4 3 5" "2 1 4 5 3" "2 1 5 3 4" "2 1 5 4 3" "2 3 1 4 5" "2 3 1 5 4" "2 3 4 1 5" "2 3 4 5 1" "2 3 5 1 4" "2 3 5 4 1" "2 4 1 3 5" "2 4 1 5 3" "2 4 3 1 5" "2 4 3 5 1" "2 4 5 1 3" "2 4 5 3 1" "2 5 1 3 4" "2 5 1 4 3" "2 5 3 1 4" "2 5 3 4 1" "2 5 4 1 3" "2 5 4 3 1" "3 1 2 4 5" "3 1 2 5 4" "3 1 4 2 5" "3 1 4 5 2" "3 1 5 2 4" "3 1 5 4 2" "3 2 1 4 5" "3 2 1 5 4" "3 2 4 1 5" "3 2 4 5 1" "3 2 5 1 4" "3 2 5 4 1" "3 4 1 2 5" "3 4 1 5 2" "3 4 2 1 5" "3 4 2 5 1" "3 4 5 1 2" "3 4 5 2 1" "3 5 1 2 4" "3 5 1 4 2" "3 5 2 1 4" "3 5 2 4 1" "3 5 4 1 2" "3 5 4 2 1" "4 1 2 3 5" "4 1 2 5 3" "4 1 3 2 5" "4 1 3 5 2" "4 1 5 2 3" "4 1 5 3 2" "4 2 1 3 5" "4 2 1 5 3" "4 2 3 1 5" "4 2 3 5 1" "4 2 5 1 3" "4 2 5 3 1" "4 3 1 2 5" "4 3 1 5 2" "4 3 2 1 5" "4 3 2 5 1" "4 3 5 1 2" "4 3 5 2 1" "4 5 1 2 3" "4 5 1 3 2" "4 5 2 1 3" "4 5 2 3 1" "4 5 3 1 2" "4 5 3 2 1" "5 1 2 3 4" "5 1 2 4 3" "5 1 3 2 4")
for ARG in "${numbers4[@]}"; do
    execute_test "ARG"
done

echo ""
echo "Test for 100 numbers"
echo "-----"
numbers100=("100 99 98 97 96 95 94 93 92 91 90 89 88 87 86 85 84 83 82 81 80 79 78 77 76 75 74 73 72 71 70 69 68 67 66 65 64 63 62 61 60 59 58 57 56 55 54 53 52 51 50 49 48 47 46 45 44 43 42 41 40 39 38 37 36 35 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0")
	execute_test $numbers100

echo ""
echo "Test for 100 numbers"
echo "-----"
numbers100=("36 -92 18 -47 63 -28 51 -84 75 -56 42 -19 60 -73 26 -65 14 -37 48 -68 81 -23 57 -96 33 -54 70 -11 39 -78 22 -89 45 -61 29 -42 66 -15 54 -87 27 -69 92 -32 10 -52 78 -7 93 -45 15 -30 59 -74 21 -58 87 -13 71 -36 49 -81 37 -64 19 -49 84 -22 56 -93 31 -50 68 -9 46 -72 24 -67 12 -44 64 -80 40 -55 76 -17 53 -88 28 -71 91 -34 8 -60 67 -25 43 -77 20 -53")
	execute_test $numbers100
