-- bank  
-- 1)

delimiter //
drop trigger accountNoCheck //
create trigger accountNoCheck before insert on account for each row 
begin 
if new.acc_no< 0 then 
    SIGNAL SQLSTATE '45000'
    SET MESSAGE_TEXT = 'Account Number cannot be 0';
end if;

end//
delimiter ;

delete from account where acc_no = -1;
insert into account(acc_no) values(-1);
delete from account where acc_no=111111;
delete from account where acc_no = 1111;
insert into account(acc_no) values(111111);
-- select * from account;


-- 2)  
delimiter //
drop trigger checkLoanAmt // 
create trigger checkLoanAmt before insert on loan_application for each row 
begin 
if new.lamtapproved > new.lamtrequired  then 
  SIGNAL SQLSTATE '45000'
  SET MESSAGE_TEXT = 'Loan Ammount Approved Should be less than or Equal to Required';
end if;
end // 
delimiter ;

insert into loan_application(lno,lamtrequired,lamtapproved) values (1006,50000,60000) ;


-- Railway 

-- 1)  
delimiter // 
drop trigger validateTrain // 
create trigger validateTrain before insert on train for each row 
begin 
if  not new.arrivalTime < new.departTime  then
  SIGNAL SQLSTATE '45000'
  SET MESSAGE_TEXT = 'Arrival Time should be less than depart time';

end if;
end //
delimiter ;
delete from train  where trainNo = 1010;
insert into train(trainNo,departTime,arrivalTime) values (1010 , '12:00:00', '15:00:00');


-- 2)  
delimiter // 
drop trigger changeStatusField // 
create trigger changeStatusField before update on ticket for each row 
begin
if old.trainStatus = 'failed' then 
  SIGNAL SQLSTATE '45000'
  SET MESSAGE_TEXT = 'Status is failed cannot be changed ';
end if ;
end // 
delimiter ;

update ticket set trainStatus = 'waiting' where trainStatus = 'failed';


-- 3) 