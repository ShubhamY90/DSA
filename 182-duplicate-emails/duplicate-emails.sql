# Write your MySQL query statement below
select distinct p.email as Email from Person p join Person d on p.email = d.email where p.id <> d.id