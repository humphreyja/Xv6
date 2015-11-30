#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "passwd.h"

struct USER {
  char name[50];
  char pass[50];
};

int checkuser() {
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

  struct USER u;
  printf("Please enter a username: ");
  fgets(u.name, 50, stdin);
  printf("Please enter a password: ");
  fgets(u.pass, 50, stdin);

  int tmpct;
  for (tmpct = 0; tmpct<ct; tmpct++) {
    if (!strcmp(u.name, users[tmpct].name)) {
      return 1;
    }
  }

  return 0;
}