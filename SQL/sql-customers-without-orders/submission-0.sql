-- Write your query below
select name
from customers
where not exists
(select 1 from
 orders
where customers.id = orders.customer_id);