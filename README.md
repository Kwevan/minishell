# minishell






## Tests


quotes with | ; >

ex : echo "ls -la; echo ok"

open quotes ' or "

## echo 

echo -n -n -n -n ok

echo -n -n -n -n 

echo "-n ok"

echo 

echo -n

echo "slt" \; "sava"

multi ~

cat ~/anything | cat ~/anything

/bin/ls ?

and all others bin path exec

env -i ./minishell


?='salut' (special char env variable)


# cd

cd $HOME
cd $HOME/Desktop

cd $HOMEanything je comprends pas pk il ignore le anything

cd > ok.txt

cd folder; rm -rf folder; pwd

echo ls | ./minishell pour la gestion erreur lecture

# VAR


#echo $_

echo $SHLVL

# executable

/bin/ls

"ls"
'ls'

unset PATH puis ls



### pipe


| less

| more

| sort

| grep "a" - va display la ligne contenant a et mettre a en evidence

| sed -e "s/a/u/"  remplace tous les 'a' par 'u'




# pas vraiment réfléchi

ls | | wc = segfault
