-- Write your query below
(select distinct cus.customer_id, cus.customer_name
from customers cus
 where NOT EXISTS(
    select 1 
    from orders
    where orders.customer_id = cus.customer_id AND orders.product_name = 'C'
 )
INTERSECT
select cus.customer_id, cus.customer_name
 from customers cus
 natural join
 orders ord
 where product_name = 'B'
INTERSECT
select cus.customer_id, cus.customer_name
 from customers cus
 natural join
 orders ord
 where product_name = 'A')
 order by customer_name asc
 ;