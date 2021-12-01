#include "Audio.hh"

Audio::Audio(std::string audioUrl)
{
    this->audioUrl = audioUrl;
    buffer->loadFromFile(audioUrl);
}

Audio::~Audio()
{
}
