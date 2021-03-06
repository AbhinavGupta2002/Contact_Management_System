// This header file consists of the structures used in this
// program along with the function, introduction(), which
// redirects the program to other functions appropriately

#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

extern const int MAX_CONTACTS;
struct contact_storage;

struct introduction{
  char username[50];
  int available_contacts;
  int filled_contacts;
  int total_contacts;
};

struct contact_details {
  char name[50];
  char address1[100];
  char address2[100];
  char mobile[50];
  char work[50];
  char home[50];
  bool block;
  bool emergency;
};

// introduction() displays the introductory section of the homepage
//                of the system and redirects the program to another
//                function appropriately. If the program is not
//                exited, it recursively calls itself
void introduction();
