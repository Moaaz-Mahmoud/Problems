/*
Enter your query here.
Please append a semicolon ";" at the end of the query and enter your query in a single line to avoid error.
*/
with cte as (
    select
        min(lat_n) a,
        max(lat_n) b,
        min(long_w) c,
        max(long_w) d
    from station
)
select
    round(
        cast(
            sqrt((a-b)*(a-b) + (c-d)*(c-d))
            as decimal(19, 4)
        ),
        4
    )
from cte
;
