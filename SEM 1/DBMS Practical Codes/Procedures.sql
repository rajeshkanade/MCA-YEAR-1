-- procedure is used for performing and executing multiple statement and 
-- it is used with insert update delete (DML Command) 

-- Excecuted using the exce command  


-- syntax : 
-- Delimiter $$ 

-- create procedure procedure_name(
--     In parameter1 Datatype,
--     out paramter2 Datatype,
--     INOUT paramter3 Datatype
-- )
-- begin 
--     select paramter1 into paramter2 from table_name ;
-- end $$

-- Delimeter ; 

-- To call : 
-- syntax : 
-- call procedure_name(parameter1,@outputParamter)

-- to select :- 
-- select @outputParamter;

-- eg  
drop procedure procedure1;

delimiter $$ 
create procedure procedure1(
    out id int , 
    out name varchar(20)
)
begin 
    select ID into id  from sample;
end $$ 
delimiter ;

call procedure1(1,'PUBG');