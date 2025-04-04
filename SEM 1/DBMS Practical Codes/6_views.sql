

-- +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ For Bank Database +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
drop view v1;
drop view v2;
drop view v3;
drop view v4;

-- 1ST Query :-  
-- eg 1
create view v1 as  select c.cno,c.cname,c.caddr,c.city,a.acc_no,a.acc_type,a.acc_balance,b.brname,b.brcity  from customer c, account a, branch b  where c.cno = a.cno and a.bid = b.bid ;

-- eg 2

drop view customer_account_details;
create view customer_account_details as select c.*,a.acc_no,a.acc_type,a.acc_balance from customer c join account a  on c.cno = a.cno;
select c.*,a.* from customer c join account a on c.cno = a.cno ;

select * from customer_account_details;

-- 2ND Query :- 

create view v2 as select l.*, b.brname,b.brcity from loan_application l join branch b on l.bid = b.bid where b.brname = 'BANK OF MAHARASHTRA';

select * from v2;

-- ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ For Railway Database ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

-- 3RD Query :-  

create view v3 as select p.*,t2.ticketId,t2.ticketAmt,t1.trainName,t2.trainDate from passenger p join train t1 join ticket t2 on t2.trainNo = t1.trainNo and p.passId = t2.passId  where   t1.trainName = 'Mumbai Express';
select * from v3;


-- 4TH Query :-  
create view v4 as select p.* from passenger p join train t1 join ticket t2 on t1.trainNo = t2.trainNo and t2.passId = p.passId where t2.trainStatus = 'conformed' and t1.trainName = 'Mumbai Express';
select * from v4;