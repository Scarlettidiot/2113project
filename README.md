# 2113project
-proposal
#Identification of the team members.
Group Number: 63
Li Sijia (UID 3035771440)
Yang Xiaoyue (UID 3035772858)


#A description of your game and introduce the game rules.

Name: Avalon

Description: A one-player text-based detective game. The background of the game content is set to be the King Arthur time. In the game, the player will play the character of a good minister, who need to distinguish good or bad fellows and select part of them to complete several tasks. If the player recruit any bad fellow officer to complete the "task" together, the task will fail. In a total of five tasks need to be completed, the player is required to hold at least three successful task to win the game. 

Game rules: 
- player: 1
- There are 10 "ministers" in total, 4 of them are bad. The good and bad ministers will be randomly assigned to identity number from 0 to 9.
- There will be up to five rounds for the player to select ministers for joining the task.
- For the first round, the player need to select three ministers; for the second and the third round, the player need to select four ministers; for the forth and the fifth round, the player need to select five ministers.
- Player will win the game if three rounds are successful.   
- No information about the ministers' identity will be given to the player during the game, unless the player failed the tasks succesively for two rounds. Then, one good minister's identity will be revealed to the player.
- The player need to reason the identity of the ministers by the success or failure of the tasks.

#A list of features that you plan to implement, and explain how each coding element from 1 to 5 listed under the coding requirements aforementioned have supported your features.

- Random sequence of characters (good and bad ministers' distribution) in each new game.
  element 1 support this feature because the random sequence can be achieved by random function in c++.
- Players input a set of numbers in every round of the game. The success/fail of each round will be printed in screen.
  element 4 support this feature. The input number will be processed by the program and output the result of the round.
- The success/fail of each round will be stored to track the win or loss of the game.
  element 2 support this feature. A data structure which can store the game status after each round will be designed.

