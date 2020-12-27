Task description As a second assignment, you must develop a C++ program where two users play cards. The game is about users drawing each card from a dec of cards. Maximum card wins. A winner is decided in the form of the best of three.

Logic: In a Card game there is 52 cards and they are Randomly shuffled before distrubting it to players.
       We need to simulate Card shuffle and then give it to the Players. Whoever get Higher Rank Card wins the Round 1 by 1 and who has more wins at the last. Wins the game.

*** main() MAIN FUNCTION:
    1. Initialize Some Variable with need while making the Basics:

                    1.1 char Choice - For Taking User Input if He want to play the game.
                    1.2 Deck theDeck - Calling Class Deck for Creating and Shuffling the Deck.
                    1.3 Initialize IF (Choice = 'Y') statement to check if User is willing to Play.

                               1.3.1 IF statement is True then We will call Player Class and push Deck inside player1/2(theDeck)

                               1.3.2 Initialize WHILE LOOP (check if Deck is not Empty) then:

                                     1.3.2.1 Card card1/card2 = player1/2.draw() - Calling Class Card and storing    player1/2 and calling draw() FUNCTION to Draw Shuffled Deck and Store in card1/card2.

                                     1.3.2.2 Initialize IF (Player1 Card Rank == Player2 Card Rank) - Round Tie.
                                     1.3.2.3 ELSE IF (PLayer1 Card Rank > Player2 Card Rank) - Player 1 Wins the Round.
                                     1.3.2.4 ELSE Player 2 Wins the Round.
                                     1.3.2.5 Player1/2.replaceCard(theDeck) - replacing cards from Current Deck and Adding next cards.

                               1.3.3 Display Result.

*** class randomInteger{} CLASS FOR RANDOMIZING DECK:
    1. public: - So that we can access anywhere in program.
    2. unsigned int operator () (unsigned int) - Creating FUNCTION and exporting Randomizer.

    Explaination:  repeat for many times{
                                           select 2 random object in the array
	                                       exchange the selected objects
                                        }

*** FUNCTION randomInteger::operator():
    1. unsigned int rval = rand() - Storing Random Number for Deck cards.
    2. Return rval VALUE.

*** class Deck{} CLASS FOR MAKING FINAL DECK WIHT RANDOM CARDS:
    1. Deck() - Creating Constructor.
    2. void shuffle() - No Returing VALUE FUNCTION.
    3. Card draw() - FUNCTION to Draw Cards from Deck.

*** Deck::Deck() FOR INITIALIZING THE DECK:
    1. topCard = 0 - Initialize topCard with Value 0
    2. Initialize FOR (Every Shade Has 13 Cards So we will Run the Loop for 13)

                  2.1 Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i) - Taking Card Array and Filling it with Values 1 TO 13
                  2.2 Cards[diamond,spade,heart,club] - Increase Each Shape with 1 Each Time Loop Runs

    Explaination: The variable suit will go through the values Card.DIAMOND (= 1) upto and including Card.SPADE (= 4)
                  The variable rank will go through the values 1 upto and including 13
                  So we will create 4×13 = 52 cards
                  The variable i is incremented by 1 so each new card will be stored in a different array element deckOfCards[i].

*** Card Deck::draw() DRAWING CARDS FROM DECK:
    1. IF (! isEmpty()) - IF isEmpty() FUNCTION is called then.

                 1.1 return cards[--topCard] - Return card from the end of deck
    2. ELSE - We will Return Ace of Spades According to the Game Rules.

    Explaination: We can simulate "dealing" a card from a deck using an "current card" index variable


***CLASS:
	1. Card: CLASS FOR CARDS

			1.1. Using access Specifier- Public
			1.2. Using Constructors- 
							a)Card():- Initializes a Card with Default values
							b)Card(suits, int):- Initializes a Card with given values
			1.3. Data Fields-
							a)int rank:- Holds rank of card
							b)suits suit:- Hold suit of card
	
	2. Player: CLASS FOR PLAYERS

			1.1. Using access Specifier- Public:- To be accessed from anywhere in the program
			1.2. Using Constructor-
							a)Player(Deck &):- Uses a contructor to call the player and addresses to the location of Deck
			1.3. Using Operation-
							a)Card draw():- Functions to draw the card
							b)void addpoints(int):- Function to add points with each draw and initializes to integer value
							c)int score():- Functions to store the score
							d)void replaceCard(Deck &):- Function to to replace card from the Deck
			
			1.4. Using access specifier- Protected:- To be accessed from the derived class
			1.5. Data members-
							a)Card myCard[3]:- Calls card from the class Card and stores the value in myCard
							b)int myScore :- Initializes the score value to integer
							c)int removeCard :- Initializes the value if removed cards to integer
