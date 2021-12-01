#include "SFML/Audio.hpp"
#include<iostream>
#include<string>

class Audio
{
private:
    sf::SoundBuffer* buffer{ new sf::SoundBuffer()} ;
    sf::Sound* sound{};
    std::string audioUrl;
    float volumen; 

public:
    Audio(std::string audioUrl, float volumen);
    ~Audio();
    void SetAudio();
};

