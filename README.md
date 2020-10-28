# minishell






## Tests


# quotes

quotes with | ; >

ex : echo "ls -la; echo ok"

open quotes ' or "

# \
todo

## echo 

echo 

echo -n

echo -n -n -n -n ok

echo -n -n -n -n 

echo "-n ok"


echo -n

echo "slt" \; "sava"

multi ~


env -i ./minishell


?='salut' (special char env variable)


# cd

cd $HOME
cd $HOME/Desktop

cd $HOMEanything (its like cd with no args )

cd > ok.txt

cd folder; rm -rf folder; pwd

# exit
todo

# VAR

echo $HOME

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

### pipes and redir


| less

| more

| sort

| grep "a" - va display la ligne contenant a et mettre a en evidence

| sed -e "s/a/u/"  remplace tous les 'a' par 'u'




# pas vraiment réfléchi

ls | | wc = segfault

echo ls | ./minishell pour la gestion erreur lecture
