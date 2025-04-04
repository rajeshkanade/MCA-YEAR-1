-- create table student(studId int primary key  , studName varchar(30) , studEmail varchar(50));

-- create table course(courseId int primary key, courseName varchar(30));
-- create table marks(
--                     studId int,
--                     courseId int,
--                     marksId int , 
--                     marksObtained float , 
--                     totalMarks float,  
--                     Grade char(2),
--                     primary key (marksId,studId,courseId),
--                     foreign key (studId) references student(studId),
--                     foreign key (courseId) references course(courseId)
--                 );


-- insert into student values(1,'Rajesh Kanade', 'rajeshkanade121@gmail.com');
-- insert into course values(1,'MCS');
-- insert into marks values (1,1,101,98.56,100.00,'A+');


select * from student;
select * from course;
select * from marks;