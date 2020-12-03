DIR_NAME="yah"
OS=$(uname -s)


git clone https://github.com/solaldunckel/minishell-tester $DIR_NAME

cd $DIR_NAME

make re -C ../


if [ $OS == "Darwin" ]; then
	echo 'Mac os'
#	sed -i '' '/head -c 100/d' ./test.sh
else
	echo 'Linux'
#//	sed -i '/head -c 100/d' ./test.sh
fi

bash test.sh

cd ..

rm -rf $DIR_NAME
