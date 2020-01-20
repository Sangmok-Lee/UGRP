# UGRP - Understanding of Computer Systems Security and Design of Secure Computer System
This is what I had done for UGRP (ndergraduated Group Research Program) from March 1st, 2019 to December 20th, 2019

Attacks which exploit hardware weakness such as Flush+Reload attack or Row-Hammering is serious security issue. To avoid these kinds of attack fundamentally, the best way is change the way hardwork works. However, this kind of method will not be compatible with current computer systems. Also, It is almost impossible with undergraduate knowledge.

Therefore, we decided to build a defense system that can be used on most of the computers in use today. In addition, we aimed to make our programs not only universal, but also capable of fast and accurate detection. 

To achieve this, our program is based on Intel Performance Counter Monitor (PCM). Detection system is consisted of 2 parts. 
1. Intel PCM : Monitors Hardware Performance Counters and determines whether the systems is under attack. When the system is under attack, High L3 Cache misses and Low Cache hit ratio could be deteced by PCM. Therefore, PCM determines that the system is under attack at this circumstance.
2. running : When PCM determines that the system is under attack, 'running' finds running process at that time and suggests them as suspicious processes. Since attacker process will acccess to cache memory insistently, they will be always running in the system.

In order to synchronize two codes, we modified Original PCM code to change the PCM output format and some code.
