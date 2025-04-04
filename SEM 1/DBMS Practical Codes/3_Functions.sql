
-- Bank Database 
-- 1) Write the function that returns the total loan amount of a perticular branch. 
drop function total_loan_amt;
delimiter //
create function total_loan_amt()
returns int deterministic 
begin 
declare total_amt int ;
select sum(lamtapproved) into total_amt from loan_application;
return total_amt;
end // 
delimiter ;


select total_loan_amt();

-- 2) Write a function to count the no. of customers of a perticular branch.  
drop function total_customer;  
delimiter // 
create function total_customer() 
returns int deterministic 
begin 
declare total int;
select count(c.cno) into total from customer c, branch b where c.bid = b.bid and b.brname = 'BANK OF MAHARASHTRA';
return total;
end // 
delimiter ;

select total_customer();



-- Railway Database 

-- 1) write a function which accepts train name and date as input paramter and calculate total ticket amount for that the train on the given data. 
drop function ticket_amt;
delimiter //
create function ticket_amt(trainName varchar(20) , trainDate date)
returns int deterministic 
begin 
declare total_amt int;
select sum(ticket.ticketAmt) into total_amt from train,ticket where train.trainNo = ticket.trainNo and ticket.trainDate = trainDate and train.trainName = trainName;
return total_amt;
if total_amt is null then set total_amt = 0;
end if;
end//
delimiter ;

select ticket_amt('Mumbai Express','2027-08-01') ;


-- 2) Write a function to calculate total no. of berths reserved for the train mumbai express on 2027-08-01
drop function total_berths;
delimiter //
create function total_berths()
returns int deterministic 
begin 
declare total_no_berths int;
select sum(ticket.noOfBerths) into total_no_berths from ticket,train where train.trainNo = ticket.trainNo and train.trainName = 'Mumbai Express';
return total_no_berths;
end// 
delimiter ;

select total_berths();
