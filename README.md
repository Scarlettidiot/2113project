# 2113project

#Identification of the team members.
Group Number: 63
Li Sijia (UID 3035771440)
Yang Xiaoyue (UID 3035772858)


#A description of your game and introduce the game rules.

Name: Avalon

Description: A one-player text-based detective game. The background of the game content is set to be the King Arthur time. In the game, the player will play the character of a good minister, who need to distinguish good or bad fellows and select part of them to complete several tasks. If the player recruit any bad fellow officer to complete the "task" together, the task will fail. In a total of five tasks need to be completed, the player is required to hold at least three successful tasks to win the game. 

Game rules: 
- The player will play the role of a good minister.
- There are 10 "ministers" in total, 4 of them are bad. The good and bad ministers will be randomly assigned to identity number from 0 to 9.
- There will be up to five rounds for the player to select ministers for joining the task.
- For the first round, the player need to select three ministers; for the second and the third round, the player need to select four ministers; for the forth and the fifth round, the player need to select five ministers. (excluding the player herself). The player need to input the interger numbers in range 0-9, and separate each input by space or new line. 
- After each round, the player will immediately know the result of this round, which includes the number of bad ministers in her selection, and then judge the role of each number.
- Player will win the game if three rounds are successful. If there are already three successful rounds, then the game will end automatically with the result winning.
- No information about the exact ministers' identity will be given to the player during the game, unless the player failed the tasks succesively for two rounds. Then, one bad minister's identity can be revealed to the player depend on player's demand.
  (This rule is to avoid the player feels too difficult to accomplish the task. The player can choose not to be given if already know the roles)
- The player need to reason the identity of the ministers by the success, failure, and the number of bad ministers in the team of the tasks.
- After the game, regardless of the result, the game will show the role of each number on the screen.

#A list of features implemented, and explain how each coding element from 1 to 5 listed under the coding requirements aforementioned have supported your features.

- Requirement 1: Generation of random game sets or events
  - Feature: the function assign(). It uses a random function which use time as the seed to randomly assign the roles (4 bad ministers' distribution) to different number 0-9.
- Requirement 2: Data structures for storing game status
  - Feature: the dynamic array rresult[] records the result of each round (pass as int 1, fail as int 2) and also track the status of the round (which round is the current round.
  - Feature: the dynamic array currentcar[] records the selection of current round (status).
  - Feature: the for loop in which the int i stores the number of the current round. 
  - Feature: game_continue() tracks the game status after every round and break the loop if the win and lose of the full game has been a certainty (i.e., break the loop if there has been three succeed rounds or 3 failed rounds even though the game haven't been to the final fifth round).
  - Feature: hints(): a function judging if there are two rounds failed consecutively (track the game status). If yes, then the program will provide an opportunity. The player can choose whether to be given a bad minister's number randomly and automatically. 
- Requirement 3: Dynamic memory management
  - Feature: rresult[] is a dynamic array which stores the game status. The memory location will be freed after the one full game ends.  
  - Feature: currentcar[] is a dynamic array which stores the selection of the player in each round. The memory will be freed after each round, and a new array will be created if there is new round after. 
- Requirement 4: File input/output (e.g., for loading/saving game status)
  - Feature: there is a for loop to ask the player input numbers which will be stored in the the dynamic array currentcat[] In each round. 
  - Feature: round_result(): receive input in currentcar[] array and count the number of "bad ministers", which will be an output in the main function and also be used to decide and show the success or failure of the current round. 
  - Feature: final_result(): receive input in rresult[] array and count the pass and fail rounds, and output the success or failure by true or false. The main function structure will use the output to print out the result of the full game.
- Requirement 5: Program codes in multiple files
  - Feature: there will be three files in this program. 
    - Avalon.h is the header file containing the function declarations (except for the main function in main function file).
    - Avalon.cpp is the implementation file containin the function definitions (except for the main function in main function file).
    - main.cpp is the main file which contains the main body of the codes. 
