select * from course;
select * from student;


-- creating instructor table 
-- create table instructors( instructorId int primary key,   instructorName varchar(30),departement varchar(30),title varchar(30));

insert into instructors values(111,'Sudam','MCS','Worker');


/*creating table courseOffering*/

-- create table courseOfferings(courseOfferingId int , courseId int,couseYear int ,totalSemester int ,sectionNo int ,instructorId int , department varchar(50),
-- primary key (courseOfferingId,courseId,instructorId),
-- foreign key (courseId) references course(courseId),
-- foreign key (instructorId) references instructors(instructorId)
-- );

insert into courseOfferings values(101,1,2,4,1,111,'MCS');


-- create table enrollment(enrollmentId int ,studentId int ,marksId int,   courseOfferingId int,Grade char(2),
--     primary key(enrollmentId,studentId,marksId,courseOfferingId),
--     foreign key(studentId) references student(studId),
--     foreign key(courseOfferingId) references courseOfferings(courseOfferingId),
--     foreign key(marksId) references marks(marksId)
--     );

insert into enrollment values(1000,1,101,101,'A+');
