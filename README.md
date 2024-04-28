# THIS PROJECT IS FOR EDUCATIONAL PURPOSES ONLY AND SHOULD NOT BE USED.


httplib.h is by yhirose.


To use preset parameters, place them in params.txt file.

EXAMPLE params.txt:

username:fibian


In params.txt, use $ to use a random string

Example:


username:$

$:hi

URL is url to attack.

SUB is page to attack (e.g. /index.html)

TIMES is number of requests to send

PARAMETERS are data sent (e.g. username=freddy). If they are not specified in params.txt, they will be random strings.


## DO NOT USE MALICIOUSLY! ONLY use on servers YOU OWN!



## TO COMPILE:
g++ -o https-dos https-dos.cpp -lssl -lcrypto



