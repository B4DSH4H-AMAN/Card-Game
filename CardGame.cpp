#include <iostream>
#include <algorithm>
using namespace std;

enum suits {diamond, club, heart, spade};

class Card{
public:
		// constructors
	Card();            // Initialize a Card with default values
	Card(suits, int);   // Initialize a Card with given values

	// Data fields
	int rank;      // Hold rank of card
	suits suit;    // Hold suit of card
};
/**
 *
 * Aman Upadhyay
 * India
 *
*/
Card::Card(){
	// Initialize a new Card
	// Default value is the ace of spades
	rank = 1;
	suit = spade;
}

Card::Card(suits sv, int rv){
	// Initialize a new Card using the argument
	rank = rv;
	suit = sv;
}

ostream & operator << (ostream & out, Card & aCard){
	// First output rank
	switch (aCard.rank){
		case 1:out << "Ace";   break;
		case 11:out << "Jack";  break;
		case 12:out << "Queen"; break;
		case 13:out << "King";  break;
		default:	// output number
			out << aCard.rank; break;
		}

	// Output
	switch (aCard.suit){
		case diamond:out << " of Diamonds"; break;
		case spade:out << " of Spades";   break;
		case heart:out << " of Hearts";   break;
		case club:out << " of Clubs";    break;
		}
	return out;
}

class randomInteger{
	public:
		unsigned int operator () (unsigned int);
} randomizer;

unsigned int randomInteger::operator () (unsigned int max){
		// Rand returning random integer
		// Converting to unsigned to make positive
	unsigned int rval = rand();
	return rval % max;
}

class Deck{
public:
	Deck (); // Constructor
	void shuffle(){
		// Operations
		 random_shuffle (cards, cards+52, randomizer);
    }
	bool isEmpty(){
		return topCard <= 0;
	}
	Card draw ();

protected:
	Card cards[52];
	int topCard;
};

Deck::Deck (){
	// Initialize a Deck
	topCard = 0;
	for (int i = 1; i <= 13; i++){
		Card c1(diamond, i), c2(spade, i), c3(heart, i), c4(club, i);
		cards[topCard++] = c1;
		cards[topCard++] = c2;
		cards[topCard++] = c3;
		cards[topCard++] = c4;
		}
}

Card Deck::draw (){
	if (! isEmpty()){
	// Return card from the end of deck
		return cards[--topCard];
	}
	else {
		// Return ace of spades
		Card spadeAce(spade, 1);
		return spadeAce;
	}
}

class Player {
public:
	// Constructor
	Player (Deck &);
	// Operations
	Card draw ( );
	void addPoints (int);
	int score ();
	void replaceCard (Deck &);

protected:
	Card myCards[3];
	int	myScore;
	int	removedCard;
};

Player::Player (Deck & aDeck){
	// Initialize the data fields for a player
	myScore = 0;
	for (int i = 0; i < 3; i++)
		myCards[i] = aDeck.draw();
	removedCard = 0;
}

Card Player::draw (){
	// Return a Random Card from our Hand
	removedCard = randomizer(3);
	return myCards[removedCard];
}

void Player::addPoints (int howMany){
	// Add the Given Number of points in current score
	myScore += howMany;
}

int	Player::score (){
	// Return the Current Score
	return myScore;
}

void Player::replaceCard (Deck & aDeck){
	// Replace Last Card with New Card
	myCards[removedCard] = aDeck.draw();
}

int main(){
	char choice;
	Deck theDeck; // Create and Shuffle the Deck
	theDeck.shuffle();
	cout << "\n************   WELCOME TO CARD GAMES MAX PRO   *************\n" << endl;
	cout << "READY TO PLAY THE GAME ?: Yes[Y] No[N] "<< endl;
	cin >> choice;

	if (choice = 'Y'){

	Player player1(theDeck); // Creating Player One
	Player player2(theDeck); // Creating Player Two

	// Round will continue untill the Deck is Empty
	while (! theDeck.isEmpty() ) {
		Card card1  = player1.draw();
		cout << "\n******************************************************" << endl;
		cout << "Player One playing: " << card1 << endl;
		Card card2 = player2.draw();
		cout << "Player Two playing: " << card2 << endl;
		cout << "******************************************************" << endl;

		if (card1.rank == card2.rank) { // tie
			player1.addPoints(1);
			player2.addPoints(1);
			cout << "Players tie\n";
			cout << "******************************************************" << endl;
			}
		else if (card1.rank > card2.rank) {
			player1.addPoints(2);
			cout << "Player One wins round\n";
			cout << "******************************************************" << endl;
			}
		else {
			player2.addPoints(2);
			cout << "Player Two wins round\n";
			cout << "******************************************************" << endl;
			}

		// Now Replace the Cards Drawn
		player1.replaceCard(theDeck);
		player2.replaceCard(theDeck);
	}
	cout << "\n\n********************** RESULT ************************" << endl;
	cout << "Player 1 score " << player1.score() << endl;
	cout << "Player 2 score " << player2.score() << endl;
	cout << "******************************************************" << endl;
	}

}

