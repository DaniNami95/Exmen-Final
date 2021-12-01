#include "SFML/Audio.hpp"
#include<iostream>
#include<string>

class Audio
{
private:
    sf::SoundBuffer* buffer{ new sf::SoundBuffer()} ;
    sf::Sound* sound{};
    std::string audioUrl;

public:
    Audio(std::string audioUrl);
    ~Audio();
    void SetAudio();
};

