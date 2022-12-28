#ifndef MYSIC_HPP
#define MYSIC_HPP

#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QString>

enum class LOOPING_MODE {
	LOOPING,
	NOT_LOOPING,
};

class Music {
public:
	Music(const QString& FILE_PAHT,
		LOOPING_MODE looping_mode = LOOPING_MODE::LOOPING);
        ~Music();

	void start();
	void stop();
	int get_volume() const;
	void set_volume(int number);

private:
	QMediaPlaylist::PlaybackMode _looping_mode;
	QUrl _file_path_url;
	QMediaPlayer* _music;
	QMediaPlaylist* _music_list;
	int _volume;
};

#endif
