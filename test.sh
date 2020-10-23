DIR_NAME="yah"

git clone git@github.com:Kwevan/minishell_tester.git $DIR_NAME

cd $DIR_NAME

make re -C ../

cp ../minishell ./


bash tests.sh

cd ..

rm -rf $DIR_NAME
