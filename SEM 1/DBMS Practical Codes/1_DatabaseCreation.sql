-- bank creation  
drop table account;
drop table loan_application;
drop table customer;
DROP TABLE branch;


create table branch(bid int primary key,
                    brname varchar(50),
                    brcity varchar(10)
                    );

    insert into branch values(001,'BANK OF BARODA','BHENDA');
    insert into branch values(002,'BANK OF MAHARASHTRA','PUNE');
    insert into branch values(003,'STATE BANK INDIA','SHIRUR');
    insert into branch values(004,'BANK OF MAHARASHTRA','DHAYARI');


create table customer(cno int primary key ,
                      bid int,
                     cname varchar(20),
                     caddr varchar(35),
                     city varchar(20),
                     foreign key (bid) references branch(bid)
                     );
    insert into customer values(100,001,'RAJESH','BHENDA','Ahemdnagar');
    insert into customer values(101,002,'SUJIT','BEKARAINAGAR','PUNE');
    insert into customer values(102,002,'Shreyas','Koregaon','Satara');
    insert into customer values(103,003,'Shubham','Shirur','Beed');




create table loan_application(lno int ,
                               cno int,
                               bid int,
                             lamtrequired double ,
                             lamtapproved double ,
                             l_date date,
                             primary key (lno),
                             foreign key (cno) references customer(cno),
                             foreign key (bid) references branch(bid)
                             );

    insert into loan_application values(1001,100,001,5000,10000,'2024-10-02');
    insert into loan_application values(1002,101,002,50000,40000,'2024-09-03');
    insert into loan_application values(1003,102,002,75000,70000,'2024-08-05');
    insert into loan_application values(1004,103,003,65000,50000,'2024-11-23');




create table account(acc_no int , 
                    cno int,
                    bid int,
                    acc_type varchar(10),
                    acc_balance float(8,2),
                    primary key (acc_no),
                    foreign key (bid) references branch(bid),
                    foreign key (cno) references customer(cno)
                    );

    insert into account values(24933,100,001,'SAVING',700000.00);
    insert into account values(34523,101,002,'CURRENT',200000.00);
    insert into account values(80801,102,002,'SAVING',500000.00);
    insert into account values(45232,103,003,'SAVING',250000.00);
    

-- ------------------------------------------------------------ Railway creation -----------------------------------------------------------------
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
insert into ticket values(1004,103,002,10,40, '2025-12-27',400,'conformed');
insert into ticket values(1001,102,003,55,42, '2024-12-09',670,'waiting');
insert into ticket values(1006,104,004,9,5, '2026-08-24',1460,'failed');
insert into ticket values(1003,105,005,4,2, '2025-02-05',700,'waiting');
insert into ticket values(1008,101,007,9,5, '2027-09-01',1000,'conformed');
insert into ticket values(1007,104,008,15,6, '2027-10-10',150,'conformed');
insert into ticket values(1006,101,009,14,5, '2027-10-01',1460,'conformed');
insert into ticket values(1008,102,010,9,5, '2027-08-01',1000,'conformed');
insert into ticket values(1008,103,011,9,5, '2027-07-01',1000,'conformed');
insert into ticket values(1008,104,012,9,5, '2027-05-01',1000,'conformed');
insert into ticket values(1003,102,013,55,42, '2024-12-09',670,'waiting');



