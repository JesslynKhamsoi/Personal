#include "Deck.h"
//Matching card game using images of animals
//using sfml

int main(void)
{
	sf::RenderWindow window(sf::VideoMode(1900, 1000), "Can you find the matching animals?");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	Deck mCards;
	bool two_clicked = false;
	
	float t = 0;
	int flipT = 10;
	sf::Clock clock;
	sf::Time time = sf::seconds(1.0f);
	mCards.fillDeck(&window);
	while (window.isOpen())
	{
		
		sf::Event event;
		

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			if (mCards.checkTwo() < 2) //only allows player to look at 2 cards at once
			{

				mCards.clickCard(&window, event);
			}

			cout << time.asSeconds() << "  "; //displays time for develping purposes
		}
		if (mCards.checkTwo() == 2) //once 2 cards are flipped a timer begins, allowing the play only to see them for a certain amount of time
		{
			time += clock.getElapsedTime();
			clock.restart();
			int i = mCards.checkTwo(); cout << i;
			mCards.checkedPair = true;
			if (time.asSeconds() >= flipT)
			{
				for (int i = 0; i < 6; i++)
				{
					mCards.allCards[i].clicked = false;
					clock.restart();
					time = sf::seconds(1.0f);
				}
		
			}
		}

		window.clear();
		int positionX = 375;
		int positionY = 100;
		for (int i = 0; i < 6; i++) //displays backs of 6 cards
		{
			if (mCards.allCards[i].matched == false)
			{
				mCards.allCards[i].back.setPosition(positionX, positionY);
				mCards.allCards[i].front.setPosition(positionX + 25, positionY + 25);
				positionX += 400;
				if (i == 2)
				{
					positionY += 500;
					positionX = 375;
				}
				window.draw(mCards.allCards[i].back);
				
				if (mCards.allCards[i].clicked == true)
				{
					window.draw(mCards.allCards[i].front);
				}
				
				
			}
			
		}
		window.display();
	}

	return 0;
}
