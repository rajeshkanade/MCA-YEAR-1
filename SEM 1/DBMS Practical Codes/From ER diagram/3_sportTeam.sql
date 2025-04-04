drop table player;
drop table matches;
drop table team ;


create table team(teamId int primary key, teamName varchar(20));

create table matches(matchId int primary key, teamId int, location varchar(20), finalScore int, foreign key (teamId) references team(teamId));

create table player(playerId int, playerName varchar(20),teamId int, foreign key (teamid) references team(teamId));

create table playerMatchParticipation(playerId int, matchId int , staticsticId int, foreign key (matchId) references matches(matchId), foreign key references player(playerId), foreign key (staticsticId) references playerStatistics(staticsticId));

create table playerStatistics(staticsticId int, goalScored int, assists int, minutesPlayed int , yellowCards int, redCards int, otherSpecificStats int , )


