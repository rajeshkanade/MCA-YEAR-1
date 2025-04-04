/* creating the game table in sql */ 
/*create table games(id int , title varchar(50) , company varchar(30), production_year int , system_name varchar(30), production_cost int , revenue int , rating float, type varchar(50));
*/

/* Updating the type of the production_cost and revenue */ 
/*alter table games modify column production_cost int ;
alter table games modify column revenue int ; 
*/ 


/* inserting the data into the table 
insert into games values(1,'The Legend of Zelda','Nintendo',2017,'Nintendo Switch, Wii U ',10000000,15000000,9.7,'Action and Adventure');
insert into games values(2,'Grand Theft Auto V','RockStar Games',2013,'Playstation 3, Xbox 360',26500000,70000000,9.7,'Action and Adventure, Open World');
insert into games values(3,'Red Dead Redemption 2','RockStar Games',2018,'PlayStation 4 , Xbox One ',3700000,1000000,9,'Action and Adventure');
insert into games values(4,'Cyberpunk 2077','CD Projekt Red',2020,'PlayStation 4, Xbox series X/S ',316000,500000,9.7,'Action and Adventure');
insert into games values(5,'The Legend of Zelda','Nintendo',2017,'Nintendo Switch, Wii U ',100000,1500000,9.7,'Action and Adventure');
insert into games values(6,'The Legend of Zelda','Nintendo',2017,'Nintendo Switch, Wii U ',1000000,1500000,9.7,'Action and Adventure');

*/

/* Displaying all the games */ 

select * from games;

/* Display average production cost */ 
select avg(production_cost) from games;

/* displaying the game title whoes revenue is greather than 2000000 */ 
select title from games where revenue > 2000000;

/* Displaying the no. of games greather than 7 */ 
select * from games where rating > 7;

/* Dipslyaing the list of profitable games */ 
select * from games where revenue > production_cost;




