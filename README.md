# 2113project
-proposal
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
- For the first round, the player need to select three ministers; for the second and the third round, the player need to select four ministers; for the forth and the fifth round, the player need to select five ministers. (excluding player himself)
- After each round, the player will immediately know the result of this round, and then judge the role of each number.
- Player will win the game if three rounds are successful. If there are already three successful rounds, then the game will end automatically with the result winning.
- No information about the ministers' identity will be given to the player during the game, unless the player failed the tasks succesively for two rounds. Then, one good minister's identity can be revealed to the player depend on player's demand.
  (This rule is to avoid the player feels too difficult to accomplish the task. The player can choose not to be given if already know the roles)
- The player need to reason the identity of the ministers by the success or failure of the tasks.
- After the game, regardless of the result, the game will show the role of each number on the screen.

#A list of features that you plan to implement, and explain how each coding element from 1 to 5 listed under the coding requirements aforementioned have supported your features.

- Use a random function to randomly assign the role (good or bad ministers' distribution) to different number 0-9.
  element 1 support this feature because the random sequence can be achieved by random function in c++.
- In each round, player will be asked to input numbers (3 numbers in first round, 4 numbers in second and third round, 5 numbers for forth and fifth round) to present the ministers that the player decided to bring each round.
- After the player made his decision, the screen will print out "success" or "fail" based on the input. There will be a function to analyze if there is any "bad" minister in these numbers, if yes, then the result will be processed as fail.
  element 4 support this feature. The input number will be processed by the program and output the result of the round.
- Meanwhile, the success/fail of each round will be stored to track the win or loss of the game.
  element 2 support this feature. A data structure which can store the game status after each round will be designed.
- Whenever there is three success rounds, players win the game against bad ministers, the program will print win and end the game. Also, if there are already five rounds and the player has less than 3 successful rounds, the program will print loss and end the game. Two functions will be written to test these two features.
  element 3 support this feature since the game round and the game result will change and stored in program memory.
- There will be a function judging if there are two rounds failed consecutively. If yes, then the program will provide an opportunity. The player can choose whether to be given a good minister's number randomly and automatically. One function will be used to store the input of the player and one function will be used to address a random good minister's number.
  This game will use a lot of defined functions and these functions will store in different files for supporting element 5.
