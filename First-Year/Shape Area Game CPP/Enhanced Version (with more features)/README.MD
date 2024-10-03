# Shape Area Game Enhanced Version (with more features):

This is a C++ console-based game where players are tasked with calculating the area of randomly generated shapes (rectangles). The game adjusts its difficulty based on the player's selected level and requires players to calculate the shape's area within a given time limit. Players earn points based on their performance, and their goal is to achieve the highest possible score before the game ends.

## Features

- **Level Selection:** The player can choose between three levels of difficulty: Easy, Medium, and Hard. Each level has different parameters for the number of trials, time limits, and scoring.
- **Random Shape Generation:** Rectangular shapes of random sizes are generated for the player to calculate their areas.
- **Timer-based Gameplay:** Players need to answer within a specific time frame, with bonuses for answering quickly.
- **Hearts and Lives:** Players have three hearts at the start of each level. A heart is lost for every incorrect or missed answer.
- **High Score Tracking:** The game keeps track of the player's highest score across multiple playthroughs.

## Game Flow

1. **Start Screen:**  
   When the game starts, a welcome message is displayed. The player can choose the level of difficulty and proceed to the game.

2. **Level Setup:**  
   Each level comes with its specific number of trials, score per correct answer, time limit, and number of hearts. The difficulty and parameters change based on the selected level.

3. **Main Gameplay:**  
   - The game presents a randomly generated rectangle.
   - The player calculates the area and inputs their answer.
   - The game calculates how long the player took to answer and compares the answer to the correct area.
   - Points are awarded based on how quickly the player answers and whether the answer is correct.

4. **End of Level:**  
   When the player completes the level (either by finishing all trials or losing all hearts), their score is updated, and they can choose to play again or exit.

5. **Game Over:**  
   When the player exits or completes the game, the final score and high score are displayed.

## Code Overview

### Functions

1. **`start_screen()`**  
   Displays the welcome message and basic game instructions.

2. **`choose_level(int &level)`**  
   Prompts the player to select a difficulty level (1 = Easy, 2 = Medium, 3 = Hard).

3. **`header(int s_trial, int score, int level, int heart)`**  
   Displays the current trial number, score, level, and remaining hearts. This function is called at the start of each trial.

4. **`level_inst(int l_score, int l_timeout, int l_trial, int level)`**  
   Displays the instructions for the selected level, including how many points the player will earn, the time limit, and other game rules.

5. **`draw_shape(int length, int width)`**  
   Randomly generates and displays a rectangle shape using the '#' character. The player will need to calculate its area.

6. **`game_over(int high_score)`**  
   Displays the player's final score and the highest score achieved.

7. **`start_next()`**  
   Displays a countdown between trials to allow the player to prepare for the next shape.

### Variables

- `l_trial`, `s_trial`: Track the number of total and current trials.
- `score`: The player's current score.
- `width`, `length`: Dimensions of the generated shape.
- `user_areas`, `area`: User input and correct area value.
- `table_size`: The range of possible rectangle sizes based on the level.
- `heart`: The number of remaining lives (hearts).
- `level`: The current difficulty level.
- `l_score`, `l_timeout`: The points for each correct answer and the time limit for each trial.
- `high_score`: The highest score achieved across multiple playthroughs.
- `play`: Determines if the player wants to continue playing.

## How to Play

1. Run the program.
2. Choose a difficulty level (1 for Easy, 2 for Medium, 3 for Hard).
3. Watch the randomly generated shape and calculate its area.
4. Enter the area as quickly as possible within the time limit.
5. Earn points for correct answers and double points for answering quickly.
6. Lose hearts for incorrect answers or running out of time.
7. After finishing all trials or losing all hearts, see your score and decide whether to play again.

## Game Rules

- **Correct Answers:** Earn points based on the level.
- **Double Score Bonus:** Answer within half the time limit to double your points.
- **Hearts:** You start with three hearts. Each incorrect answer or timeout reduces one heart.
- **Game Over:** The game ends when all hearts are lost or the player chooses to quit.