CREATE TABLE IF NOT EXISTS Musicians (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) UNIQUE
);

CREATE TABLE IF NOT EXISTS Genres (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) UNIQUE
);

CREATE TABLE IF NOT EXISTS Albums (
    id SERIAL PRIMARY KEY,
    name VARCHAR(40) UNIQUE,
    YEAR INTEGER
);

CREATE TABLE IF NOT EXISTS Tracks (
    id SERIAL PRIMARY KEY,
    name VARCHAR(40) UNIQUE,
    duration FLOAT,
    album_id INTEGER NOT NULL REFERENCES Albums(id)
);

CREATE TABLE IF NOT EXISTS Playlists (
	id SERIAL PRIMARY KEY,
	name VARCHAR(40) UNIQUE,
	YEAR INTEGER
);

CREATE TABLE IF NOT EXISTS MusiciansGenres (
	musician_id SERIAL REFERENCES Musicians(id),
	genre_id SERIAL REFERENCES Genres(id),
	CONSTRAINT MG PRIMARY KEY (musician_id,
genre_id)
);

CREATE TABLE IF NOT EXISTS AlbumsMusicians (
	musician_id SERIAL REFERENCES Musicians(id),
	album_id SERIAL REFERENCES Albums(id),
	CONSTRAINT AM PRIMARY KEY (musician_id,
album_id)
);

CREATE TABLE IF NOT EXISTS PlaylistsTracks (
	track_id SERIAL REFERENCES Tracks(id),
	playlist_id SERIAL REFERENCES Playlists(id),
	CONSTRAINT PT PRIMARY KEY (track_id,
playlist_id)
);