/* creating the table 
create table product(id int , code char(3) , name varchar(30) , quantity int , price decimal(10,2));


/* inserting the rows in the table 
insert into product values(1,'P','PEN',15,150.00);
insert into product values(2,'P','PENCIL',20,150.00);
insert into product values(3,'B','BRUSH',5,150.00);
insert into product values(4,'E','ERASER',10,150.00);
insert into product values(5,'S','SCALE',25,250.00);
insert into product values(6,'C','COMPASS',18,1000.00);
insert into product values(7,'B','BAG',3,1250.30);
insert into product values(8,'B','BOOKS',11,440.00); */  */


/* LISTING ALL ROWS WITH SPECIFIED COLUMN AND PRINTING */  
select code, price from product order by price desc;

/* listing all product details quantity above than 10 */ 
select * from product where quantity > 10;

/* List the product details whose details started by P */ 
select * from product where name  like 'p%';


/* displaying total price for the product Code P */ 
select price from product where code = 'P';

/* diplaying first two hightest price record from product table */ 
select * from product order by price desc limit 2;



 update product set price =(price + (price * ( 10/100)));
select * from product;


