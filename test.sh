DIR_NAME="yah"

git clone https://github.com/solaldunckel/minishell-tester $DIR_NAME

cd $DIR_NAME

make re -C ../



bash test.sh

cd ..

rm -rf $DIR_NAME
