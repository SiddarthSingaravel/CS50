select distinct(name) from people join stars on people.id = stars.person_id join movies on stars.movie_id = movies.id where movies.title IN(select distinct(movies.title) from people
join stars on people.id = stars.person_id join movies on stars.movie_id = movies.id where people.name = "Kevin Bacon" and people.birth = 1958) and people.name != "Kevin Bacon";