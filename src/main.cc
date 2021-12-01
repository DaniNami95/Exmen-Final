#include<iostream>
#include "Game.hh"
#include "SFML/Audio.hpp"

int main()
{
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
