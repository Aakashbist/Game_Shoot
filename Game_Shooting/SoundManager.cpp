#include "SoundManager.h"


SoundManager::SoundManager()
{
}


SoundManager::~SoundManager()
{
	for each (SoundListing listing in sounds) {
		Mix_FreeChunk(listing.sound);
	}
}

void SoundManager::loadSound(string name, string file) {
	SoundListing listing;
	listing.name = name;
	listing.sound = Mix_LoadWAV(file.c_str());
	sounds.push_back(listing);
}
void SoundManager::playSound(string name) {
	for (SoundListing listing : sounds) {
			if (listing.name == name) {
			Mix_PlayChannel(-1, listing.sound, 0);
			break;
		}
	}
}

SoundManager SoundManager::soundManager;
