create table student(
    sno char(10),
    sname char(8),
    sgender char(2),
    sage int,
    sdept char(2),
    constraint student_pkey primary key (sno)
);
insert into student (sno,sname,sgender,sage,sdept) values ('20025121','李勇','男',20,'CS');
insert into student (sno,sname,sgender,sage,sdept) values ('20025122','李','男',10,'PS');
