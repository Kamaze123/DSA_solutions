-- Write your query below
select employee_id,
    CASE
        when (name not like 'M%' AND employee_id % 2 != 0) then salary
        else 0
    END AS bonus
from employees
 order by employee_id asc;