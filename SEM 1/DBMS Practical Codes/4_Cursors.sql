-- --------------------------------------------------Bank Database  ------------------------------------
-- 1) Write a procedure using cursor to disoplay the customers having loan amounts between 45000 and 60000 from branch name = 'MGROAD';
drop procedure printLoanAmt;
delimiter //
create procedure printLoanAmt()
begin 
declare done int default 0;
declare name varchar(20);
declare curl cursor for select c.cname from customer c join loan_application la join branch b on c.cno = la.cno and c.bid = b.bid where la.lamtapproved between 45000 and 60000 and b.brname = 'BANK OF MAHARASHTRA';
declare continue handler for SQLSTATE '02000' set done = 1;
-- declare continue handler for not found set done = 1;
open curl;
repeat 
fetch curl into name;
if not done then 
select name;
end if;
until done end repeat;
close curl;
end // 
delimiter ;

call printLoanAmt();


-- 2)  Write a procedure using cursor to add an interest of 4% to the balance of all accounts having balance > 7000 
drop procedure amountInterest;
delimiter // 
create procedure amountInterest()
begin 
declare done int default 0;
declare cname varchar(20);
declare acc_balance float(8,2);
declare interest_4_perc float(8,2);
declare curl cursor for select c.cname , a.acc_balance , (a.acc_balance * 0.04) from customer c join account a on c.cno = a.cno where a.acc_balance > 70000;
declare continue handler for not found set done = 1;
open curl;
read_loop : loop 
fetch curl into cname , acc_balance , interest_4_perc;
if done then 
leave read_loop;
end if;
select cname , acc_balance , interest_4_perc;
end loop;
close curl;
end//
delimiter ;

call amountInterest();

-- ------------------------------------------------------Railway   Database ---------------------------------------
-- 1)  Write a cursor to find the not confirmed bookings of all the trains on 1
drop procedure notConformedTrain;
delimiter //
create procedure notConformedTrain() 
begin 
declare done int default 0;
declare trainName varchar(20);
declare trainNo int;
declare trainStatus varchar(20);
declare ticketId int ;
declare ticketAmt float(8,2);
declare curl cursor for select t1.trainName , t1.trainNo , t2.ticketId , t2.ticketAmt , t2.trainStatus from train t1 join ticket t2 on t1.trainNo = t2.trainNo where t2.trainStatus = 'waiting' and t2.trainDate = '2024-12-09';
declare continue handler for not found set done = 1;
open curl;
read_loop : loop 
fetch curl into trainName , trainNo , ticketId , ticketAmt , trainStatus;
if done then 
leave read_loop;
end if;
select trainName , trainNo , ticketId , ticketAmt , trainStatus;
end loop;
close curl;
end // 
delimiter ;
call notConformedTrain();
-- 4  
drop procedure totalNoBerths;
delimiter //
create procedure totalNoBerths()
begin 
declare done int default 0;
declare totalBerths int ;
declare curl cursor for select sum(noOfBerths) from ticket where ticket.trainDate = '2025-06-04';
declare continue handler for not found set done = 1;
open curl;
read_loop : loop 
fetch curl into totalBerths;
if done then 
leave read_loop;
end if ;
select totalBerths;
end loop;
close curl;
end // 
delimiter ;
call totalNoBerths();
