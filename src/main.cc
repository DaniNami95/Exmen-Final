#include<iostream>
#include "Game.hh"
#include "SFML/Audio.hpp"

int main()
{

  /*sf::RectangleShape* rectangleShape{new sf::RectangleShape(sf::Vector2f(100, 100))};
  rectangleShape->setPosition(sf::Vector2f(200, 50));
  rectangleShape->setFillColor(sf::Color::Red);
*/

  Game* game{new Game()};
  sf::Music music;
  if(!music.openFromFile("assets/audio/Labyrinth_Of_Dreams.wav"))
  {
     std::cout <<"No se cargo el audio"<< std:: endl;
  }
  music.setVolume(60);
  music.play();

  game->Initialize();
  delete game;

  return EXIT_SUCCESS;
}
