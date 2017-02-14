# runs a.out in each directory

#script to run C files

echo -e "running "$PWD"/main.c\n"

./a.out $*

echo -e "\ninput file : \n"

cat input.txt

echo -e "\noutput file : \n"

cat output.txt

echo -e "\n"
