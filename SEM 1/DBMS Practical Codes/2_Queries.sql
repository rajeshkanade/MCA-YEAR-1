-- bank Queries  

select * from customer,loan_application where  loan_application.lamtrequired > 50000 and customer.cno = loan_application.cno;
select * from customer,branch,loan_application where branch.brname = 'BANK OF MAHARASHTRA' and branch.bid = loan_application.bid and customer.cno = loan_application.cno;

select sum(l.lamtapproved) from loan_application l,branch b where l.bid = b.bid and b.brname = 'BANK OF MAHARASHTRA';

-- Railway Queries  


select * from passenger;
select * from train;
select * from ticket;


select * from train where sourceStn = "Mumbai" and destStn = "Pune";
select * from train where sourceStn = "Pune";


select count(ticket.passId) as 'Total No of Passenger' from ticket,train where ticket.trainNo = train.trainNo and train.trainName = 'India Tour Express';


select * from passenger p  join ticket t on t.ticketId = 001 and p.passId = t.passId;
select * from passenger p join ticket t on t.ticketId = 001 and p.passId = t.passId;


