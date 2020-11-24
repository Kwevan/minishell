# redirections



## basic

* echo text > ok

 [>] delete the file, recreate it write text inside
 
 [>>] write text at the end of the file


---

* grep "" < readme

Will read the readme and send it to the grep command

---

## Multi

* echo text > a > b > c

will only write the file c
a and b will be created but empty
if a and b exist, they will be deleted and recreated

---

* echo text >> a >> b >> c

The only difference is that, if a or b exist, their content won't change

---


* grep "" < a < b < c

will simply read the last file

---

* grep > a < b

Will read the content of b, send it to grep, and the result of grep will be written in a


---

* grep > a < b < c

Same, logic, all files will be read

---

* grep > a < b > c > d > z

Read b, send it to grep, great output written in the last file, z

---

* grep > a > b < readme > c > d > z

or 

* grep < readme > c > d > z

same logic

No matter how many < >> > we get and where they are positioned 

Bash will always read all the files [<] from left to right

Send the result to the command 

then write the result in the last file after some [>] or [>>]

---

* grep "" < file_that_doesnt_exit

error no such file or dir

---

echo ok > "oui>i"

---

echo it > empty_file1  joins the > empty_file2 parts > empty_file3 > empty_file4 > file of this command

> its echo magic

echo ok > ok abc'>'def > ok
