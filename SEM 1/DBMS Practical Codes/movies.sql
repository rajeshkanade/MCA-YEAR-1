/* creating the movies table 

create table movies(id int , title varchar(30), rating decimal(1,1), y_release int , budget int , language varchar(10));*/ 


/* Inerting values in the table
  
insert into movies values (1,'RRR',8.5,2022,400,'Hindi');
insert into movies values (2,'Salaar',8.0,2024,650,'Hindi');
insert into movies values (3,'Dune',7.2,2019,350,'English');
insert into movies values (4,'Mangalavaram',9.0,2024,100,'Telugu');
insert into movies values (5,'Pushpa',9.0,2021,380,'hindi');
insert into movies values (6,'Brahmavugam',7.5,2022,70,'Malyalam'); */


/* retriving movie title , rating and year released */
select title,rating,y_release from movies;


/* modify the table add new attribute box_office (storing the details of box_office value) */ 


alter table movies add column box_office int;
select * from movies;
update movies set box_office = case 
	when id = 1 then '1400'
	when id = 2 then '1600'
	when id = 3 then '900'
	when id = 4 then '300'
	when id = 5 then '1700'
	when id = 6 then '200'
	end;


/*show only movies with earnings above 200 millions */

select * from movies where box_office - budget > 200;

/* show movies that has the letter r in their name */
select * from movies where title like '%r%';

/* show movies that are release before 2023 */ 
select * from movies where y_release < 2022;

/* show released movies after 2021 in asceding order */ 
select * from movies where y_release > 2021 order by y_release ;







