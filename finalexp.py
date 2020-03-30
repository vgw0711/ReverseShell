import os

os.system("cd Desktop")

for i in range(50625):
    os.system("python3 exploit.py 8010 369 {}".format(str(i)))
