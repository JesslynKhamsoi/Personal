#include "Deck.h"
#include <SFML/Graphics.hpp>
Deck::Deck(bool newChecked)
{
	checkedPair = newChecked;
}
void Deck::fillDeck(sf::RenderWindow *window)
{
	Card* pCard = new Card(false);
	sf::RectangleShape allBacks;
	allBacks.setFillColor(sf::Color::Blue);
	allBacks.setSize(sf::Vector2f(350,250));
	pCard->back = allBacks;
	int positionX = 375;
	int positionY = 100;
	int j = 0;
	for (int i = 0; i < 6; i++)
	{
		allCards[i].makeSprite(i);
		allCards[i].back = allBacks;
		allCards[i].x = positionX + (400*i);
		allCards[i].y = positionY;
			if (i > 2)
			{
				allCards[i].x = positionX + (400* j);
				allCards[i].y = positionY + 500;
				j++;
			}
	
	}
}
void Deck::clickCard(sf::RenderWindow *window, sf::Event press)
{
	if (press.type == sf::Event::MouseButtonPressed) //chekcing if user pressed button, then finding out if stand or hit button was pressed
	{
		if (press.mouseButton.button == sf::Mouse::Right)
		{

			for (int i = 0; i < 6; i++)
			{
				if ((press.mouseButton.x > allCards[i].x) && (press.mouseButton.x < allCards[i].x + 250) && (press.mouseButton.y > allCards[i].y) && (press.mouseButton.y < allCards[i].y + 250))
				{
					cout << "card " << i << " was clicked";
					allCards[i].clicked = true;
				}
			}
		}
	}
}
void Deck::unClickCard(sf::RenderWindow *window, sf::Event press)
{
	if (press.type == sf::Event::MouseButtonPressed) //chekcing if user pressed button, then finding out if stand or hit button was pressed
	{
		if (press.mouseButton.button == sf::Mouse::Right)
		{

			for (int i = 0; i < 6; i++)
			{
				if ((press.mouseButton.x > allCards[i].x) && (press.mouseButton.x < allCards[i].x + 250) && (press.mouseButton.y > allCards[i].y) && (press.mouseButton.y < allCards[i].y + 250))
				{
					
					cout << "card " << i << " was clicked";
					if (allCards[i].clicked == true)
					{
						allCards[i].clicked = !(allCards[i].clicked);
					}
				}
			}
		}
	}
}
int Deck:: checkTwo()
{
	//if (mCards.checkTwo() < 2)
	//{
	//	mCards.clickCard(&window, event);
	//}
	//mCards.unClickCard(&window, event);


	int count = 0;
	for (int i = 0; i < 6; i++)
	{
		if (allCards[i].clicked == true)
		{
			count++;
		}
	}
	return count;
}