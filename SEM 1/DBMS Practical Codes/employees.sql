/* created table employee */ 
create table employee(id int , fname varchar(20) , lname varchar(20) , bdate date, jdate date, salary decimal(10,2));

/* inserting values to employee table */

insert into employee(id,fname,lname,bdate,jdate,salary) values(1,'rajesh','kanade','2003-08-12','2024-10-02',120000.56);
insert into employee(id,fname,lname,bdate,jdate,salary) values(2,'shubham','bade','2003-04-11','2024-10-02',118000.23);
insert into employee(id,fname,lname,bdate,jdate,salary) values(3,'sujit','satpute','2003-01-01','2024-10-02',119000.01);


/* modify the employees table to add anew column department */ 
alter table employee add column department varchar(30);


/* modify change data type of salary column */
-- truncate table employee;

alter table employee modify column salary int;

/* adding the unique key contraint to employee id  */

ALTER TABLE employee ADD CONSTRAINT emp_id UNIQUE (id);


