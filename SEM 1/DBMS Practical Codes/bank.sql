
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
    



select * from customer,loan_application where  loan_application.lamtrequired > 50000 and customer.cno = loan_application.cno;
select * from customer,branch,loan_application where branch.brname = 'BANK OF MAHARASHTRA' and branch.bid = loan_application.bid and customer.cno = loan_application.cno;

select sum(l.lamtapproved) from loan_application l,branch b where l.bid = b.bid and b.brname = 'BANK OF MAHARASHTRA';