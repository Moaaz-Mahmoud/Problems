/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
with join_all as (
    select 
        h.hacker_id hid,
        h.name hn,
        s.submission_id sid,
        s.challenge_id cid,
        s.score scr,
        c.difficulty_level dif,
        d.score fscr
    from
        hackers h
        join submissions s on h.hacker_id = s.hacker_id
        join challenges c on s.challenge_id = c.challenge_id
        join difficulty d on c.difficulty_level = d.difficulty_level
    where
        s.score = d.score
),
smart as(
    select 
        hid,
        count(*) as pass
    from 
        join_all
        join hackers on join_all.hid = hackers.hacker_id
    group by  hid
    having count(*) > 1
)
select 
    smart.hid id,
    hackers.name name
from 
    smart
    join hackers on hackers.hacker_id = smart.hid
order by 
    smart.pass desc,
    id asc
;
