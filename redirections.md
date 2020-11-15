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

will read a then b then c and give the files read to grep

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
