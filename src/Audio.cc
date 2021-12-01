#include "Audio.hh"

Audio::Audio(std::string audioUrl, float volumen)
{
    this->audioUrl = audioUrl;
    buffer->loadFromFile(audioUrl);
}

Audio::~Audio()
{
}
