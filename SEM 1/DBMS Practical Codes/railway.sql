drop table ticket;
drop table train;
drop table passenger;


create table train(trainNo int primary key, trainName varchar(20), departTime time, arrivalTime time, sourceStn varchar(20), destStn varchar(20), noOfResBogies int, bogieCapacity int);

insert into train values(1001,'Chennai Express','11:30','11:00','Mumbai','Chennai',30,25);
insert into train values(1002,'Kolhapur Express','24:00','23:00','Hingoli','Kolhapur',24,15);
insert into train values(1003,'Rajdhani Express','1:45','24:00','Mumbai','Nagpur',60,20);
insert into train values(1004,'Kokan Express','4:50','3:30','Mahad','Mumbai',10,40);
insert into train values(1005,'Bangalore Express','7:30','6:00','Delhi','Bangalore',70,45);
insert into train values(1006,'India Tour Express','9:00','7:00','Jammu Kashmir','Kanyakumari',90,40);
insert into train values(1007,'Pune Express','13:00','12:00','Mumbai','Pune',65,40);
insert into train values(1008,'Mumbai Express','18:00','17:00','Mumbai','Pune',30,46);
insert into train values(1009,'Ganpati Express','18:00','17:00','Pune','Bangalore',30,46);




create table passenger(passId int primary key, passName varchar(20), address varchar(30), age int , gender char);


insert into passenger values(101,'Shreyash','Dhayri', 23 , 'M');
insert into passenger values(102,'Shubham','Parvati', 21 , 'M');
insert into passenger values(103,'Sujit','Bekrainagar', 22, 'M');
insert into passenger values(104,'Rajesh','Karvenagar', 21 , 'M');
insert into passenger values(105,'Sakshi','Shivajinagar', 21 , 'F');

create table ticket(trainNo int , passId int, ticketId int primary key , bogieNo int, noOfBerths int, trainDate date , ticketAmt decimal(7,2) , trainStatus char(10), foreign key (trainNo) references train(trainNo), foreign key (passId) references passenger(passId), unique(trainNo,passId));

insert into ticket values(1001,101,001,9,5, '2025-06-04',600,'conformed');
insert into ticket values(1003,105,005,4,2, '2025-02-05',700,'waiting');
insert into ticket values(1004,103,002,10,40, '2025-12-27',400,'conformed');
insert into ticket values(1005,102,003,55,42, '2024-12-09',670,'waiting');
insert into ticket values(1006,104,004,9,5, '2026-08-24',1460,'failed');
insert into ticket values(1007,104,008,15,6, '2027-10-10',150,'conformed');
insert into ticket values(1008,101,007,9,5, '2027-09-01',1000,'conformed');
insert into ticket values(1008,102,010,9,5, '2027-08-01',1000,'conformed');
insert into ticket values(1008,103,011,9,5, '2027-07-01',1000,'conformed');
insert into ticket values(1008,104,012,9,5, '2027-05-01',1000,'conformed');
insert into ticket values(1006,101,009,14,5, '2027-10-01',1460,'conformed');





select * from passenger;
select * from train;
select * from ticket;


select * from train where sourceStn = "Mumbai" and destStn = "Pune";
select * from train where sourceStn = "Pune";


select count(ticket.passId) as 'Total No of Passenger' from ticket,train where ticket.trainNo = train.trainNo and train.trainName = 'India Tour Express';


select * from passenger p left outer join ticket t on t.ticketId = 001 and p.passId = t.passId;
select * from passenger p join ticket t on t.ticketId = 001 and p.passId = t.passId;




