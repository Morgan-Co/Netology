INSERT
	INTO
	musicians(name)
VALUES('Kendrick Lamar')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Ye')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Frank Ocean')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Bad Bunny')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('SZA')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Lil Baby')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('The Weeknd')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('MF DOOM')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Rihanna')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Tyler, The Creator')
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Metro Boomin')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musicians(name)
VALUES('Twista')

ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	genres(name)
VALUES('R&B')
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	genres(name)
VALUES('Rap')
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	genres(name)
VALUES('Pop')
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	genres(name)
VALUES('Latin-Pop')
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('The College Dropout',
2004)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('good kid, m.A.A.d city',
2012)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('Heroes & Villains',
2022)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('SOS',
2022)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('Mr. Morale & The Big Steppers',
2022)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('MM.. FOOD',
2004)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('Kamikaze',
2004)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('JESUS IS KING',
2019)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('Ye',
2019)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	albums(name,
	YEAR)
VALUES('My Beautiful Dark Twisted Fantasy',
2010)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Overnight Celebrity',
3.53,
7)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Through The Wire',
3.41,
1)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Hoe Cakes',
3.54,
6)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Rich Spirit',
3.22,
5)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Snooze',
3.21,
4)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Feel The Fiyaaaah',
3.09,
3)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Lil Jimmy Skit',
0.53,
1)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Closed On Sunday',
2.31,
8)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	tracks(name,
	duration,
	album_id)
VALUES('Violent Crimes',
3.35,
9)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	playlists(name,
	YEAR)
VALUES('Great Lyrics',
2024)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	playlists(name,
	YEAR)
VALUES('Best Samples',
2024)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	playlists(name,
	YEAR)
VALUES('Chill Mix',
2019)
ON
CONFLICT (name) DO NOTHING;

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(1,
2);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(2,
2);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(3,
1);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(4,
4);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(5,
1);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(6,
2);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(7,
1);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(8,
2);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(9,
3);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(10,
2);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(11,
2);

INSERT
	INTO
	musiciansgenres(musician_id,
	genre_id)
VALUES(12,
2);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(1,
2);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(2,
1);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(3,
11);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(4,
5);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(5,
1);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(6,
8);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(10,
2);

INSERT
	INTO
	albumsmusicians (album_id,
	musician_id)
VALUES(10,
9);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(1,
2);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(2,
2);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(3,
1);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(4,
1);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(5,
3);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(6,
1);

INSERT
	INTO
	playliststracks(track_id,
	playlist_id)
VALUES(6,
2);