-- Write your query below
select u.name, coalesce(sum(r.distance),0) as dist
from users u
left join rides r on u.id = r.user_id
group by u.id, u,name
order by dist desc, u.name asc;