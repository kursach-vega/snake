#include "../headers/music.hpp"
#include <iostream>

Music::Music(const QString& name, LOOPING_MODE looping_mode) {
	this->_music = new QMediaPlayer();
	this->_music_list = new QMediaPlaylist();
	this->_music_list->addMedia(QUrl(name));
	this->_music->setPlaylist(this->_music_list);
	if ( looping_mode == LOOPING_MODE::LOOPING ) {
		this->_music_list->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
	
	}
	return ;
}

Music::~Music() {
	delete this->_music_list;
	delete this->_music;
	this->_music = nullptr;
	this->_music_list = nullptr;
	return ;
}

void Music::start() {
	this->resume();
	return ;
}

void Music::stop() {
	this->_music->stop();
	return ;
}

void Music::pause() {
	this->_music->pause();
	return ;
}

void Music::resume() {
	this->_music->play();
	return ;
}

void Music::restart() {
	this->_music->setPosition(0);
	this->resume();
	return ;
}

int Music::get_volume() const {
	return this->_music->volume();
}

void Music::set_volume(int number) {
	std::cout << number << std::endl;
	this->_music->setVolume(number);
	std::cout << this->get_volume() << std::endl << std::endl;
	return ;
}

