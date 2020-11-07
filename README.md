# minishell


echo ok | ./minishell

1 ça avord car double free

2 pas sur de savoir ce que la commande fait




## Tests


### quotes and \

quotes with | ; >

ex : echo "ls -la; echo ok"

open quotes ' or "



echo \;
echo \\
echo \"
echo \\$HOME
echo \\\\$HOME
echo "\\$HOME"
echo '\\$HOME'
echo "\""


## echo 

echo 

echo -n

echo -n -n -n -n ok

echo -n -n -n -n 

echo "-n ok"

echo -n

echo "slt" \; "sava"


# parser

echo ~~

echo ~

echo ok \| wc 

echo ok "|" wc 

echo ok '|' wc 



# cd

cd $HOME

cd $HOME/Desktop

cd $HOMEanything (its like cd with no args )

cd > ok.txt

cd folder; rm -rf ../folder; pwd

# exit


exit

exit 1

exit abcd

exit 1 1

exit  150


# VAR

echo $

echo $HOME

echo $HOME$HOME$HOME

echo "$HOME"

echo '$HOME'

echo abc$HOME

echo $HOMEweird

echo ok && echo $?

cd nofolder && echo $?

#echo $_

echo $SHLVL

$? (error)

# executable

/bin/ls

"ls"

'ls'

unset PATH puis ls

cat ~/anything | cat ~/anything

ls ; cd malekazelkl ; echo ok

./minishell (x2)

cp  minishell mini; chmod -x mini; ./mini


### pipes and redir





| less

| more

| sort

| grep "a" - va display la ligne contenant a et mettre a en evidence

| sed -e "s/a/u/"  remplace tous les 'a' par 'u'




# pas vraiment réfléchi

ls | | wc = segfault

echo ls | ./minishell pour la gestion erreur lecture


# good to know 


max exit code = (LONG_MAX) +9223372036854775807

exit 9223372036854775808
