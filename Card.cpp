#include "card.h"
//sets images of animals to cards
Card::Card(bool newMatched, bool newClicked, int newX, int newY)
{
	matched = newMatched;
	clicked = newClicked;
	x = newX;
	y = newY;
}
void Card::makeSprite(int cardNum)
{
	if (!frontTex.loadFromFile("card.png"))
	{
		cout << "could not load card images";
	}
	front.setTexture(frontTex);
	int animal;
	if (cardNum < 2)
	{
		animal = 0;
	}
	else if (cardNum < 4)
	{
		animal = 1;
	}
	else { animal = 2; }
		
	
	front.setTextureRect(sf::IntRect(522 - (165*animal), 280, 150, 100));
	front.setScale(sf::Vector2f(2, 2));
}
