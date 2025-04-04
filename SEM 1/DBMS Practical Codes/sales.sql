/* creating the table Sales */
/*create table sales(sale_id int primary key, product_id int , quantity_sold int , sale_date Date , total_price Decimal(10,2));*/

/* adding data to the table sales  
insert into sales values(1,1,5,'2024-08-12',50);
insert into sales values(2,5,17,'2024-08-15',170);
insert into sales values(3,4,6,'2024-07-27',90);
insert into sales values(4,1,5,'2024-08-02',50);
insert into sales values(5,7,2,'2024-09-17',830);
insert into sales values(6,2,20,'2024-08-12',150);
insert into sales values(7,8,11,'2024-09-02',440); */


/* showing data from the database */  

select * from sales;

/*retriving the sales id , and sale date */ 

select sale_id , product_id from sales;

/* fiter the sales table to show only sales with a totla price greater than 100 */
select * from sales where total_price > 100;

/* retriving the sales id and total price from the sales tables for sales with a quantity sold greater than 4 */ 
select sale_id , total_price from sales where quantity_sold > 4;

/* retriving sale id and total price from the sales table for sales made on 12 august 2024;*/ 
select sale_id, total_price from sales where sale_date = '2024-08-12';

/* retriving data order by total price in desc order */
select sale_id , total_price from sales order by total_price desc;

/* retriving vales between 500rs to 1000rs */
select * from sales where sale_price between 500 and 1000;


