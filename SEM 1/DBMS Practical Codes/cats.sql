/* create table cats
create table cats(id int , name varchar(20), breed varchar(20) , coloration varchar(20), age int , sex char(1) , fav_toy varchar(20));
*/

/* insert the rows in the table 
insert into cats values(1,'kitty','Ragdoll','Tabby',6,'F','barbie Doll');
insert into cats values(2,'meww','persian','brown',10,'M','Granny'); 
*/
/* shows the all rows from the table */ 
select * from cats;

/* shows the younger cats */
select * from cats where age < 6;

/* shows the all ragdoll cats */ 
select * from cats where breed = 'Ragdoll';


/* shows the cats according to their age */ 
select * from cats order by age;
