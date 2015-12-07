#include "passwd.h"

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"






int init_checkuser() {
	users = loadusers();
	while(){
		struct u = readuser();
		int valid = compareuser(u);
		if(valid != 1){
			printf("Invalid user\n");
		}else{
			return 1;
		}
	}
}

struct USER *
loadusers(){
	FILE *passfile;
	passfile = fopen("auth_passwd.conf", "r");
	struct USER users[20];

	int ct = 0;
	while (!feof(passfile) && ct<20) {
		struct USER u;
		fgets(u.name, 50, passfile);
		fgets(u.pass, 50, passfile);
		users[ct] = u;
		ct++;
	}
	
	return users;
}

struct USER
readuser(){
	struct USER u;
	printf("Please enter a username: ");
	fgets(u.name, 50, stdin);
	printf("Please enter a password: ");
	fgets(u.pass, 50, stdin);
	return u;
}

int
compareuser(struct USER u){
	int ctr;
	for(ctr = 0; ctr < sizeof(users); ctr++)
	{
		if(!strcmp(u.name,users[ctr].name) && !strcmp(u.pass,users[ctr].pass))
		{
			return 1;
		}
	}
	return 0;
}