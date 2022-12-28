#include "../headers/music.hpp"

Music::Music(const QString& FILE_PAHT, LOOPING_MODE looping_mode) : 
        _file_path_url(FILE_PAHT),_music(nullptr), 
	_music_list(nullptr), _volume(100) {
	if ( looping_mode != LOOPING_MODE::LOOPING ) {
		this->_looping_mode = QMediaPlaylist::CurrentItemOnce;
	}
	else {
		this->_looping_mode = QMediaPlaylist::CurrentItemInLoop;
	}
    	return ;
}

Music::~Music() {
	delete this->_music_list; 
	delete this->_music;
	this->_music_list = nullptr;
	this->_music = nullptr;
	return ;
}


void Music::start() {
	delete this->_music_list; 
	delete this->_music;
	this->_music_list = nullptr;
	this->_music = nullptr;
	this->_music = new QMediaPlayer();
	this->_music_list = new QMediaPlaylist();
	this->_music->setPlaylist(this->_music_list);  
        this->_music_list->addMedia(_file_path_url); 
        this->_music_list->setPlaybackMode(this->_looping_mode); 
	this->set_volume(this->_volume);
        this->_music->play();
	return ;
}

void Music::stop() {
	if ( !this->_music ) {
		return ;
	}
	this->_music->stop();
	return ;
}

int Music::get_volume() const {
	return this->_volume;
}

void Music::set_volume(int number) {
	if ( this->_music ) {
	    this->_music->setVolume(number);
	}
	this->_volume = number;
	return ;
}
