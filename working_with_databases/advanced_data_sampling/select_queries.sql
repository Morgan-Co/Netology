SELECT
	name,
	duration
FROM
	tracks
WHERE
	duration = (
	SELECT
	MAX(duration)
FROM
	tracks);

SELECT
	name,
	duration
FROM
	tracks
WHERE
	duration > 3.5;

SELECT
	name
FROM
	playlists
WHERE
	YEAR BETWEEN 2018 AND 2020;

SELECT
	name
FROM
	musicians
WHERE
	name NOT LIKE '% %';

SELECT
	name
FROM
	tracks
WHERE
	name LIKE '%my%'
	OR name LIKE '%мой%';

SELECT
	g.name,
	COUNT(ga.musician_id) AS artist_count
FROM
	genres g
	LEFT JOIN musiciansgenres ga ON
	g.id = ga.genre_id
GROUP BY
	g.name
ORDER BY
	artist_count DESC;

SELECT
	a.name AS album_name,
	COUNT(a.id) AS track_count
FROM
	albums a
	LEFT JOIN tracks t ON
	a.id = t.ALBUM_ID
WHERE
	a.year BETWEEN 2019 AND 2020
GROUP BY
	a.name;

SELECT
	a.name AS album_name,
	COUNT(t.id),
	AVG(t.duration)
FROM
	albums a
	LEFT JOIN tracks t ON
	a.id = t.album_id
GROUP BY
	a.name;

SELECT
	m.name
FROM
	musicians m
	LEFT JOIN albumsmusicians am ON
	am.MUSICIAN_ID = m.ID
	LEFT JOIN albums a ON
	a.ID = am.ALBUM_ID
		AND a."year" = 2020
WHERE
	a.ID IS NULL;

SELECT
	pl.name
FROM
	playlists pl
	LEFT JOIN playliststracks plt ON
	plt.PLAYLIST_ID = pl.ID
	LEFT JOIN tracks t ON
	t.ID = plt.TRACK_ID
	LEFT JOIN albumsmusicians am ON
	t.ALBUM_ID = am.ALBUM_ID
	LEFT JOIN musicians m ON
	m.ID = am.MUSICIAN_ID
WHERE
	m.name = 'Metro Boomin';

SELECT
	DISTINCT a.name AS album_name
FROM
	albums a
	LEFT JOIN albumsmusicians am ON
	am.ALBUM_ID = a.ID
	LEFT JOIN musiciansgenres mg ON
	mg.MUSICIAN_ID = am.MUSICIAN_ID
GROUP BY
	a.id,
	a."name"
HAVING
	COUNT(DISTINCT mg.GENRE_ID) > 1;

SELECT
	t.name
FROM
	tracks t
	LEFT JOIN playliststracks pt ON
	pt.TRACK_ID = t.ID
WHERE
	pt.PLAYLIST_ID IS NULL


WITH
	ShortestTrack
AS
(
		SELECT
	name AS track_name,
	duration,
	album_id
FROM
	tracks
WHERE
		duration = (
		SELECT
	MIN(duration)
FROM
	tracks)
	)
SELECT
	DISTINCT m."name",
	st.track_name,
	st.duration
FROM
	ShortestTrack st
	LEFT JOIN albumsmusicians am ON
	st.album_id = am.ALBUM_ID
	LEFT JOIN musicians m ON
	m.ID = am.MUSICIAN_ID

WITH
	AlbumsTrackCount
	AS
	(
		SELECT
			album_id,
			COUNT(*) AS track_count
		FROM
			tracks
		GROUP BY
		album_id
	)
SELECT
	a.name AS album_name,
	atc.track_count
FROM
	albums a
	LEFT JOIN AlbumsTrackCount atc ON
	atc.album_id = a.ID
WHERE
	atc.track_count = (
	SELECT
	MIN(track_count)
FROM
	AlbumsTrackCount)