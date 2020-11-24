make re

#echo " ls | wc; exit" | ./minishell; echo $?

#echo " ls | cat t; exit" | ./minishell; echo $?
#echo " ls | cat t; exit" | bash --posix; echo $?

#echo " ls -la | wtf; exit" | bash --posix; echo $?
#echo " ls -la | wtf; exit" | ./minishell; echo $?


#echo "  wtf; exit" | bash --posix; echo $?
#echo " wtf; exit" | ./minishell; echo $?

#echo "> file.txt echo test lol; cat file.txt" | bash --posix; echo $?
#echo "> lol echo test lol; cat lol" | ./minishell; echo $?


#echo '>lol1 echo > test>lol2>test>>lol3>test mdr >lol4 test >test; cat test ; exit' | ./minishell; echo $?


echo '>lol1 echo > test>lol2>test>>lol3>test mdr >lol4 test >test; cat test ; exit' | bash; echo $?











