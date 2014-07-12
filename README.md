Warcraft--this file is still being updated!!!!!!
========

C++ project for EC327

To Compile:

g++ main.cpp Game_Object.cpp Gold_Mine.cpp Input_Handling.h Person.cpp Cart_Point.cpp Game_Command.cpp Miner.cpp Soldier.cpp Inspector.cpp View.cpp Model.cpp Town_Hall.cpp Cart_Vector.cpp

To run:
./a.out

Once compiled, the commands include: 

Implement a new command: 
n TYPE ID X Y- create a new object with the specified TYPE, ID number, (X, Y) location 
TYPE is a one letter abbreviation for the type of object: 
• g – goldmine 
• t – townhall 
• m – miner 
• s – soldier

The inspector inspects mines, 
visiting each one and reporting how much gold is present in each mine when it arrives. After visiting all 
of the mines, it retraces its path, visiting all of the mines in reverse order, and reports the difference in 
the amount of gold present on its outbound visit and on its inbound visit.

S filename
R filename

