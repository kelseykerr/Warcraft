Warcraft
========

C++ project for EC327

Compile (this may be different for you):

g++ main.cpp Game_Object.cpp Gold_Mine.cpp Input_Handling.h Person.cpp Cart_Point.cpp Game_Command.cpp Miner.cpp Soldier.cpp Inspector.cpp View.cpp Model.cpp Town_Hall.cpp Cart_Vector.cpp

To run:
./a.out

Once compiled, the gameboard should print out with objects. The types of objects are:
[g]oldmine
[t]townhall
[m]iner
[s]oldier
[i]nspector

***Explanations of objects:

The *inspector* inspects mines, visiting each one and reporting how much gold is present in each mine when it arrives. After visiting all of the mines, it retraces its path, visiting all of the mines in reverse order, and reports the difference in the amount of gold present on its outbound visit and on its inbound visit.

A *miner* represents a simulated human character in the game. It can be told to move to a 
specified location, and it does so at a certain speed. When it arrives to the location, it stops. It can also 
be told to start mining a specified Gold_Mine and take the gold to a specified Town_Hall.

A *Town_Hall* object has a location and an amount of gold. It also has a display_code letter and id 
number that are used to help identify the object in the output.

A *Gold_Mine* has a location and an amount of gold. It also has a display_code letter and id 
number that are used to help identify the object in the output.

A *soldier* can move around and attack other Persons, either Miners or Soldiers. All Persons will acquire the ability to be "killed;" they will have a "health" value which is decremented whenever they are "hit." When the health hits 0, the object will "die". Soldiers can be told to attack another Person object; if the target object is within range, the Soldier will go into state for attack, and then on each update cycle, it will hit the target object, and continue on the next cycle until the target is either dead or goes out of range. 

***There are the following commands:

*add a new element to the game board: n [object] [id#] [x location] [y location]
  -Example of adding a new inspector with id=6, location=(10,18):
  Enter command: n i 6 10 18
    Game_Object constructed.
    Person constructed.
Inspector constructed!
20G1. . . . G2. . . . . 
  . . . . . I6. . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . . . . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . M2. . . . . 
  0   4   8   12  16  20 

*instruct a miner to mine and deposit gold in a town hall: w [id#] [mine id] [town hall id]
  -Example of command:
  Enter command: w 3 2 1
S3:Sorry, I can't work a mine.
20G1. . . . G2. . . . . 
  . . . . . I6. . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . . . . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . M2. . . . . 
  0   4   8   12  16  20  
Enter command: w 2 2 1
Miner 2 is mining at Gold_Mine 2 and depositing at Town_Hall 1.
M2: Yes, my lord.
20G1. . . . G2. . . . . 
  . . . . . I6. . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . . . . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . M2. . . . . 
  0   4   8   12  16  20 

*instruct an inspector to begin an ispection trip: i [id#]
  -Example:
  Enter command: i 6
I6 starting to inspect!
20G1. . . . G2. . . . . 
  . . . . . I6. . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . . . . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . M2. . . . . 
  0   4   8   12  16  20 

*Run the game until an "event" occurs: r
  -Example:
  Enter command: r
Advancing to next event.
M2: step...
I6: I'm there!
Time: 1
Miner status:M1 at (5,1)
   Stopped.
Miner status:M2 at (10,6)
    Outbound to a mine.
Soldier status: S3 at (5,15)
   Stopped.
Soldier status: S4 at (10,15)
   Stopped.
Inspector status: I5 at (5,5)
   Stopped.
Gold Mine status:Gold_Mine 1 at location (1,20) Contains 100.
Gold Mine status:Gold_Mine 2 at location (10,20) Contains 100.
Town_Hall status: t1 at (0,0) contains 0 of gold.   Not yet upgraded
Inspector status: I6 at (10,20)
    Doing outbound inspection
20G1. . . . * . . . . . 
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . . . . . . . 
8 . . . . . . . . . . . 
  . . . . . M2. . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . . . . . . . 
  0   4   8   12  16  20  

*Progress one time unit forward: g
  -Example:
  Enter command: g
Advancing one tick.
M2: step...
This mine contains 100 Gold!
Time: 2
Miner status:M1 at (5,1)
   Stopped.
Miner status:M2 at (10,11)
    Outbound to a mine.
Soldier status: S3 at (5,15)
   Stopped.
Soldier status: S4 at (10,15)
   Stopped.
Inspector status: I5 at (5,5)
   Stopped.
Gold Mine status:Gold_Mine 1 at location (1,20) Contains 100.
Gold Mine status:Gold_Mine 2 at location (10,20) Contains 100.
Town_Hall status: t1 at (0,0) contains 0 of gold.   Not yet upgraded
Inspector status: I6 at (10,20)
    Outbound Inspecting
20G1. . . . * . . . . . 
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . M2. . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . . . . . . . 
  0   4   8   12  16  20  

*Save the game: S [filename]
*Resume the game: R [filename]
  -Example:
  Enter command: S game
Epic game saved!
20G1. . . . * . . . . . 
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . M2. . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . . . . . . . 
  0   4   8   12  16  20  
Enter command: R game
    Model destructed
All objects are destoryed on DOOMS DAY!!
    Game_Object constructed.
    Person constructed.
    Miner constructed.
    Game_Object constructed.
    Person constructed.
    Miner constructed.
    Game_Object constructed.
    Person constructed.
    Soldier constructed.
    Game_Object constructed.
    Person constructed.
    Soldier constructed.
    Game_Object constructed.
    Person constructed.
Inspector constructed!
    Game_Object constructed.
    Gold_Mine constructed.
    Game_Object constructed.
    Gold_Mine constructed.
    Game_Object constructed.
    Town_Hall constructed.
    Game_Object constructed.
    Person constructed.
Inspector constructed!
Epic Game Restored
20G1. . . . * . . . . . 
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . M2. . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . . . . . . . 
  0   4   8   12  16  20  

*move an object: m [id#] [x location] [y location]
  -Example:
  Enter command: m 4 10 10
Moving 4 to (10,10)
S4: On my way.
20G1. . . . * . . . . . 
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . M2. . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . . . . . . . 
  0   4   8   12  16  20 

*instruct an object to attack another object: a [attacker id#] [attackee id#]
  -Example:
  Enter command: a 4 2
S4:Attacking.
20G1. . . . * . . . . . 
  . . . . . . . . . . . 
16. . . . . . . . . . . 
  . . S3. . S4. . . . . 
12. . . . . . . . . . . 
  . . . . . M2. . . . . 
8 . . . . . . . . . . . 
  . . . . . . . . . . . 
4 . . I5. . . . . . . . 
  . . . . . . . . . . . 
0 t1. M1. . . . . . . . 
  0   4   8   12  16  20 

*quit the game: q
