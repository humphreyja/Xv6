
struct USER {
  char *name;
  char *pass;
};

#ifdef CUR_USER
extern struct USER * users;
#endif

