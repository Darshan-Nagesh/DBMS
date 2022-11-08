/*Create a table for the structure Student with attributes as SID, NAME, BRANCH, SEMESTER, ADDRESS, PHONE, EMAIL, 
Insert atleast 10 tuples and performthe following operationsusing SQL.
a. Insert a new student
b. Modify the address of the student based on SID
c. Delete a student
d. List all the students
e. List all the students of CSE branch.
f. List all the students of CSE branch and reside in Kuvempunagar.
*/

DROP TABLE Student;
CREATE TABLE Student(
	SID VARCHAR(13),
    NAME VARCHAR(15),
    BRANCH VARCHAR(5),
    SEMESTER INT,
    ADDRESS VARCHAR(25),
    PHONE LONG,
    EMAIL VARCHAR(20)
);
describe student;
INSERT INTO Student VALUES
('01JST20CS044','DARSHAN','CSE',5,'VIVEKANANDANAGAR',9900000001,'xyz@gmail.com'),
('01JST20CS086','MALLIKARJUN','CSE',5,'NAGVALA',9900000002,'abc@gmail.com'),
('01JST20CS088','MANOJ','CSE',5,'SHIRSI',9900000003,'def@gmail.com'),
('01JST20CS111','ROHITH','CSE',5,'KUVEMPUNAGAR',9900000004,'ghi@gmail.com'),
('01JST20IS222','VIRAT','IS',5,'VIVEKANANDANAGAR',9900000005,'jkl@gmail.com');

SELECT * FROM Student;

INSERT INTO Student VALUES ('01JST20IS101','RAHUL','IS',5,'KUVEMPUNAGAR',9900000006,'mno@gmail.com');

UPDATE Student
SET ADDRESS = 'KUVEMPUNAGAR'
WHERE SID = '01JST20CS222'; 

DELETE FROM Student
WHERE SID = '01JST20CS088';

SELECT * FROM Student;

SELECT *
FROM Student
WHERE BRANCH = 'CSE';

SELECT *
FROM Student
WHERE BRANCH = 'CSE' AND ADDRESS = 'KUVEMPUNAGAR';
