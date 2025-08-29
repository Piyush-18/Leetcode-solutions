# Write your MySQL query statement below
-- (select u.name, count(mr.movie_id) as results
-- from MovieRating mr natural join Users u
-- group by user_id
-- order by results desc, u.name asc
-- limit 1)
-- union
-- (select m.title, avg(mr.rating) as results
-- from MovieRating mr natural join Movies m
-- where year(created_at)=2020 and month(created_at)=02
-- group by movie_id
-- order by results desc, m.title asc
-- limit 1)

(select u.name as results
from MovieRating mr natural join Users u
group by user_id
order by count(mr.movie_id) desc, results asc
limit 1)
union all
(select m.title as results
from MovieRating mr natural join Movies m
where year(created_at)=2020 and month(created_at)=02
group by movie_id
order by avg(mr.rating) desc, results asc
limit 1)
