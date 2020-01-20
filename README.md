# UGRP - Understanding of Computer Systems Security and Design of Secure Computer Systems
Undergraduate Group Research Project (Flush+Reload, Row-Hammering Detection Program)

Attacks which exploit hardware weakness such as Flush+Reload attack or Row-Hammering is serious security issue.
To avoid these kinds of attack fundamentally, the way the hardware work should be changed.
However, this kind of method will not be compatible with current computer systems.

Therefore, we decided to build a defense system that can be used on most of the computers in use today. In addition, we aimed to make our programs not only universal, but also capable of fast and accurate detection. 

Our program is based on Intel Performance Counter Monitor (PCM).


/*1. When Flush+Reload attack or Row-Hammering is applied on the hardware, High L3 Cache misses and Low Cache hit Ratio could be detected by PCM. Our program monitors data changes in PCM and determines whether the system is under attack or not.

2. When the program determined that the system is under attack, it finds the attacker process among the 'running' processes since the attackers will be always running to access the cache memory.

3. If there is only one suspicious process, it is considered the only attacker and is killed immediately. 

4. If there are two or more suspicious processes, each process is stopped. Then they are restarted to measure the cache miss and cache hit ratio generated by each process. After this, they are stopped again. When all information was provided, the user could determine the attacker process and kill the attacker process. The verification process that occurs in the second case prevents other naive programs from being forcibly terminated by our program, while at the same time enabling us to achieve accurate detection.*/


