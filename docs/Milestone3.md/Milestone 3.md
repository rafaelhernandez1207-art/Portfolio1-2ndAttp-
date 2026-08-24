## Features  Added
- Added TurnOrder class to take in two vectors of Heroes and enemies. This will sort them by their speed stats and then let them take turns to take an action.
- Finally added my Use Potion option to the player command when battling.

## Factoring Improvements
- I have improved on my battle loop since it was crashing before but still needs work to be done.
- Fixed an issue with Potions not being deleted from the Heroes inventory
- Fixed an issue with user's name input not being stored correctly and displaying during a battle

## Testing Completed
- Tested number of potions a Hero has upon using it
- Tested the Hero's name being changed with user's input
- Tested the battle loop several times to see if Hero attacks work correctly
- Tested why battle loop does not exit upon winning a battle

## Challenges
- Had some issues figuring out why the name wasn't stored properly once the user inputs a name
- Had to fix a crash when hero did an action once but wouldn't do it again
- Still figuring out how to exit the battle loop once the enemy health reaches 0

## Next Steps
- Finally fix the battle loop
- Add my TurnOrder class to before the fight to sort all Characters by speed and each taking one action
- Add color to the text in the console
- Add more floors and enemies














