# Monopoly
Monopoly game implementation, utilizing a singly linked list to travers the board with player and CPU objects.

## Game Description
This project models the board game monopoly. Monopoly is a board game that can have up to 8 players, where the goal of the game is to travel around the board
and buy properties as you land on them. If a property you land on is owned by someone else then you have to pay that player an amount equal to the rent of that
property. If a player runs out of money and does not have enough properties to mortgage to go above debt, then they have lost the game and are declared
bankrupt. When only one player remains they are the winner.

The board of monopoly consists of 40 different spaces. The four corners of the board have special spaces, these spaces are called GO, JAIL, FREE PARKING, and GO TO
JAIL. The GO square is where players start out and each time they pass go, players are awarded $200. If a player rolls onto the JAIL square then they are simply 
visiting, but if they land on the GO TO JAIL square, or get sent to jail by another means, then they are sent to JAIL and must stay there for 3 turns unless they 
either roll double while they are in jail, or if they pay a $50 fine. Finally, there is the FREE PARKING square, when a player lands on this square they earn all of 
the money that has been payed for fines, taxes, or fees since the last player landed on FREE PARKING. The rest of the board is made up of different properties and 
several specialty squares. Every property is divided into a color group consisting of 2 to 3 properties each and there two color groups on each side of the board. If a 
player owns all properties belonging to that color, then they have a "monopoly" on that color and can buy houses and hotels to increase the price of that properties 
rent. There are four railroads on the board, one of each side, and the price of rent is based on how many railroads that player owns. There are also two utilities 
called "Water Works" and "Electric Company", whose rent's are determined by 4 times the dice number the player rolled to land on that property, if the owner has one 
utility, or 10 times, if the owner has both utilities. There are two tax squares where the player has to pay money to the bank when they land on that space. Finally, 
there are chance spaces and community chest spaces. Whenever a player lands on one of these spaces they must  draw a card from the corresponding deck. The cards from 
these decks can do a variety of things most commonly giving or taking money from the player, but they can also  move the player to a different space on the board. The 
chance cards can send you to different properties or railroads, and both sets of cards can send you to JAIL or to GO. Both decks also have a "Get Out of Jail Free" 
card which allows the player to leave jail immediately.

Each player starts off with $1500 and must roll 2 dice on their turn to determine how many spaces they move on the board. If a player rolls a double then they are 
allowed to roll again after they are finished with the first property they landed on. A player can continue to roll everytime they roll doubles until they roll three 
doubles in a single turn. When this happens that player is immediately sent to jail for speeding. On their turn a player can buy the property they land on (if it is 
unowned), buy a house/hotel for a property (if they own all properties of that color), mortgage a property they own, trade with other players, and auction off the 
property they landed on if they don't want to buy it.

## Changes Made
In this version of monopoly I changed several things to get the project done in a more timely and simple manner. These are the changes:

1. There is no condition about owning all the colors of a properties type in order to buy houses/hotels for it. So, if a player owns a property they can immediately 
buy houses/hotels for it.

2. The player cannot trade or auction off their properties to other players.

3. The player rolling doubles does not do any aditional features, they don't get to roll again, and they don't go to JAIL if they roll three doubles in a turn.

4. JAIL simply fines the player for $100 instead of holding them for 3 turns or allowing them to try and roll doubles to get out.

5. FREE PARKING is just a safe space. The player does not receive the money spent on taxes, fees, or fines.

6. A player is not allowed to mortgage their properties on their turn, instead if they were to go bankrupt the player "sells" their properties back to the bank and is
allowed to continue playing if they are no longer in debt. If they are still in debt then they are bankrupt and lose.

7. I reduced the number of chance and community chest cards in the game from 32 total to 15, 10 chance and 5 community chest. I removed the "Get Out of Jail Free"
card since JAIL no longer holds you for multiple turns and simply charges a fine. Community chest has cards that charge and gift money to the player, while chance has 
those and movement cards.

## Recommended Software
The code can be compiled on windows and apple through Clion or any ide that supports C++. To compile the code you just need to download and use the game.cpp file, 
which has the code for all of the features the game needs to run properly. This is the only file needed to run the game and play.

## Code Status and Interesting Features
All of the features that the game was designed to have currently work, but there are some extra things. The player is always asked if they want to buy a house/hotel
even if they have no property or the property they own is not capable of having houses/hotels like the utilities, saying yes does nothing and the game continues.
The game will say that player x payed player x whenever a player lands on their own property. Also the game does not have srand() implemented so the seed is not 
randomized.

## Computer Player and Viewing
The computer player is very aggressive when playing. If the computer player lands on an available property, they will purchase it if they have three times the amount or more in their balance. When given the option to purchase a house, they computer player will do so if they have ten times the amount of a house or more in their balance.
The game is viewed in two ways, the terminal and a text file. The terminal will output information needed for a turn such as the following: whos turn it is, space player is on, player balance, rent paid, special card actions, and more. The status of the board can be found in the board.txt file which is updated after a cycle of turns (each player has gone). This shows the space number, owner, space name, and value of the space. 
