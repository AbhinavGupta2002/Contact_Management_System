#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "contact_library.h"


/////////////////////////////// GLOBAL CONSTANTS ///////////////////////////////
const int MAX_CONTACTS = 30;
////////////////////////////////////////////////////////////////////////////////


////////////////////////// GLOBAL Arrays & Structures //////////////////////////
struct contact_details contact_storage[30];
struct introduction main_user_details = {" ", 30, 0, MAX_CONTACTS};
////////////////////////////////////////////////////////////////////////////////


// initialize_contacts() initializes every variable of every contact_details 
//                       structure element in contact_storage appropriately
void initialize_contacts() {
  for (int i = 0; i < MAX_CONTACTS; ++i) {
    strncpy(contact_storage[i].name, "NOT_FILLED", 50);
    strncpy(contact_storage[i].address1, "NOT_FILLED", 100);
    strncpy(contact_storage[i].address2, "NOT_FILLED", 100);
    strncpy(contact_storage[i].mobile, "NOT_FILLED", 50);
    strncpy(contact_storage[i].work, "NOT_FILLED", 50);
    strncpy(contact_storage[i].home, "NOT_FILLED", 50);
    contact_storage[i].block = false;
    contact_storage[i].emergency = false;
  }
}

// check_invalid_input(num_input) accepts an integer, which should be
//                                either 1 or 0. If an invalid input
//                                is accepted, an error  message is
//                                displayed and the program asks
//                                again for an input
// requires: num_input is valid
// effects: modifies num_input
void check_invalid_input(int *num_input) {
  assert(num_input);
  while (1) {
    int retval = scanf("%d", num_input);
    if (retval == 0) {
      int c; while ((c = getchar()) != EOF && c != '\n');
      printf("Invalid Input! ");
      printf("Enter Again\n");
    } else if (*num_input!= 1 && *num_input != 0) {
      while (getchar() != '\n');
      printf("Invalid Input! ");
      printf("Enter Again\n");
    } else {
      break;
    }
  }
}

// view_list_blocked_contacts() assists view_blocked_contacts() in
//                              displaying a list of blocked contacts.
//                              An appropriate message is displayed
//                              if there are no blocked contacts
void view_list_blocked_contacts() {
  int count_blocked_filled = 0;
  int check_blocked = 0;
  int count = 1;
  for (int i = 0; i < main_user_details.filled_contacts; ++i) {
    if(contact_storage[i].block == true) {
      ++check_blocked;
      break;
    }
  }
  if (check_blocked == 0) {
    printf("You have no blocked contacts!\n");
  } else {
    while (count_blocked_filled < main_user_details.filled_contacts) {
      if (contact_storage[count_blocked_filled].block == true) {
        printf("%d. %s", count, contact_storage[count_blocked_filled].name);
        ++count;
      }
      ++count_blocked_filled;
    }
  }
  printf("\n");
}

// view_blocked_contacts() displays a list of blocked contacts.
//                         An appropriate message is displayed
//                         if there are no saved contacts
void view_blocked_contacts() {
  int user_view = 0;
  printf("Would you like to view your blocked contacts?");
  printf(" (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_view);
  printf("\n");
  if (user_view == 1) {
    if (main_user_details.filled_contacts <= 0) {
      printf("You have no saved contacts!\n\n");
    } else {
      view_list_blocked_contacts();
    }
  }
}

// view_list_emergency_contacts() assists view_emergency_contacts() in
//                                displaying a list of emergency contacts.
//                                An appropriate message is displayed if
//                                there are no emergency contacts
void view_list_emergency_contacts() {
  int count_emergency_filled = 0;
  int check_emergency = 0;
  int count = 1;
  for (int i = 0; i < main_user_details.filled_contacts; ++i) {
    if(contact_storage[i].emergency == true) {
      ++check_emergency;
      break;
    }
  }
  if (check_emergency == 0) {
    printf("You have no emergency contacts!\n");
  } else {
    while (count_emergency_filled < main_user_details.filled_contacts) {
      if (contact_storage[count_emergency_filled].emergency == true) {
        printf("%d. %s", count, contact_storage[count_emergency_filled].name);
        ++count;
      }
      ++count_emergency_filled;
    }
  }
  printf("\n");
}

// view_emergency_contacts() displays a list of emergency contacts. 
//                           An appropriate message is displayed 
//                           if there are no saved contacts
void view_emergency_contacts() {
  int user_view = 0;
  printf("Would you like to view your emergency contacts?");
  printf(" (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_view);
  printf("\n");
  if (user_view == 1) {
    if (main_user_details.filled_contacts <= 0) {
      printf("You have no saved contacts!\n\n");
    } else {
      view_list_emergency_contacts();
    }
  }
}

// check_invalid_contact(contact_input) accepts a contact number, which should
//                                      be from the list of saved contacts. If
//                                      an invalid input is accepted, an error
//                                      message is displayed and the program 
//                                      asks again for an input
// requires: contact_input is valid
// effects: modifies contact_input
void check_invalid_contact(int *contact_input) {
  assert(contact_input);
  while (1) {
    int retval = scanf("%d", contact_input);
    if (retval == 0) {
      int c; while ((c = getchar()) != EOF && c != '\n');
      printf("Invalid Input! ");
      printf("Enter Again\n");
    } else if (*contact_input < 1 || 
               *contact_input > main_user_details.filled_contacts) {
      while (getchar() != '\n');
      printf("Invalid Input! ");
      printf("Enter Again\n");
    } else {
      break;
    }
  }
}

// view_specific_contact(contact_num) displays a specific contact by
//                                    printing out the contents of 
//                                    contact_storage[contact_num]
void view_specific_contact(int contact_num) {
  printf("\n");
  printf("******************** CONTACT %d ********************\n", 
         contact_num + 1);
  printf("NAME: %s", contact_storage[contact_num].name);
  printf("1ST ADDRESS: %s", contact_storage[contact_num].address1);
  printf("2ND ADDRESS: %s", contact_storage[contact_num].address2);
  printf("MOBILE: %s", contact_storage[contact_num].mobile);
  printf("WORK: %s", contact_storage[contact_num].work);
  printf("HOME: %s", contact_storage[contact_num].home);
  if (contact_storage[contact_num].emergency) {
    printf("THIS IS AN EMERGENCY CONTACT\n");
  }
  if (contact_storage[contact_num].block) {
    printf("THIS CONTACT HAS BEEN BLOCKED\n");
  }
  printf("****************************************************\n\n");
}

// view_list_contacts() assists view_contacts() in displaying
//                      a list of saved contacts
void view_list_contacts() {
  int count_filled = 0;
  while (count_filled < main_user_details.filled_contacts) {
    printf("%d. %s", count_filled + 1, contact_storage[count_filled].name);
    ++count_filled;
  }
}

// view_contacts() displays a list of saved contacts, if asked by the user.
//                 An appropriate message is displayed if either the user's
//                 input is invalid or there are no saved contacts
void view_contacts() {
  int user_view = 0;
  int contact_view = 0;
  printf("Would you like to view your contacts? (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_view);
  printf("\n");
  if (user_view == 1) {
    if (main_user_details.filled_contacts <= 0) {
      printf("You have no saved contacts!\n\n");
    } else {
      view_list_contacts();
      printf("\nWould you like to view a contact in detail?");
      printf(" (1 for YES/ 0 for NO)\n");
      check_invalid_input(&user_view);
      if (user_view == 1) {
        printf("Enter the contact number\n");
        check_invalid_contact(&contact_view);
        view_specific_contact(contact_view - 1);
      }
    }
  }
}

//  contact_removal_process(contact_index) is the main process of removing
//                                         the contents of a particular contact
//                                         in contact_storage[contact_index]
void contact_removal_process(int contact_index) {
  int len = main_user_details.filled_contacts;
  for(int i = contact_index; i < len - 1; ++i) {
    contact_storage[contact_index] = contact_storage[contact_index + 1];
  }
  main_user_details.available_contacts += 1;
  main_user_details.filled_contacts -= 1;
}

//  remove_contact_details() assists in removing a contact mainly
//                           by accepting a valid contact number 
//                           from the user
void remove_contact_details() {
  int c; while ((c = getchar()) != EOF && c != '\n');
  int contact_remove = 0;
  printf("Enter the contact number\n");
  check_invalid_contact(&contact_remove);
  contact_removal_process(contact_remove - 1);
  printf("*********** CONTACT HAS BEEN REMOVED SUCCESSFULLY ***********\n\n");
}

// remove_check() returns true if it possible to remove a contact. 
//                Else, it returns false
bool remove_check() {
  if (main_user_details.filled_contacts <= 0) {
    return false;
  }
  return true;
}

// remove_contact() removes a contact if the user wishes to do so.
//                  If an invalid input is accepted, an error
//                  message is displayed and the program asks 
//                  again for an input
void remove_contact() {
  int user_remove = 0;
  printf("Would you like to remove a contact? (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_remove);
  if (user_remove == 1) {
    if (remove_check()) {
      remove_contact_details();
      printf("You currently have %d available contacts.\n", 
             main_user_details.available_contacts);
      printf("You currently have %d saved contacts.\n", 
             main_user_details.filled_contacts);
    } else {
      printf("\nYou cannot remove anymore contacts!\n");
    }
    printf("\n");
  }
}

// add_contact_details(contact_index) adds the details, accepted by the user,
//                                    to the new contact appropriately
void add_contact_details(int contact_index) {
  int c; while ((c = getchar()) != EOF && c != '\n');
  int user_add = 0;
  printf("Enter the name: ");
  fgets(contact_storage[contact_index].name,
        sizeof(contact_storage[contact_index].name), stdin);
  printf("\n");
  printf("Enter the 1st address: ");
  fgets(contact_storage[contact_index].address1,
        sizeof(contact_storage[contact_index].address1), stdin);
  printf("\n");
  printf("Enter the 2nd address: ");
  fgets(contact_storage[contact_index].address2,
        sizeof(contact_storage[contact_index].address2), stdin);
  printf("\n");
  printf("Enter the mobile number: ");
  fgets(contact_storage[contact_index].mobile,
        sizeof(contact_storage[contact_index].mobile), stdin);
  printf("\n");
  printf("Enter the work phone number: ");
  fgets(contact_storage[contact_index].work,
        sizeof(contact_storage[contact_index].work), stdin);
  printf("\n");
  printf("Enter the home phone number: ");
  fgets(contact_storage[contact_index].home,
        sizeof(contact_storage[contact_index].home), stdin);
  printf("\n");
  printf("Do you want to make this an emergency contact?");
  printf(" (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_add);
  if (user_add == 1) {
    contact_storage[contact_index].emergency = true;
  }
  printf("Do you want to block this contact?\n");
  check_invalid_input(&user_add);
  if (user_add == 1) {
    contact_storage[contact_index].block = true;
  }
  printf("*********** CONTACT HAS BEEN ADDED SUCCESSFULLY ***********\n\n");
}

// add_check() returns true if it possible to add a contact. 
//             Else, it returns false
bool add_check() {
  if (main_user_details.available_contacts <= 0) {
    return false;
  }
  return true;
}

// add_contact() adds a contact if the user wishes to do so.
//               If an invalid input is accepted, an error
//               message is displayed and the program asks 
//               again for an input
void add_contact() {
  int user_add = 0;
  printf("Would you like to add a contact? (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_add);
  if (user_add == 1) {
    if (add_check()) {
      main_user_details.available_contacts -= 1;
      main_user_details.filled_contacts += 1;
      add_contact_details(main_user_details.filled_contacts - 1);
      printf("You currently have %d available contacts.\n", 
             main_user_details.available_contacts);
      printf("You currently have %d saved contacts.\n", 
             main_user_details.filled_contacts);
    } else {
      printf("\nYou cannot add anymore contacts!\n");
    }
    printf("\n");
  }
}

// contacts_homepage() displays the main section of the homepage
//                     of the system and redirects the program
//                     to another function appropriately
void contacts_homepage() {
  printf("You currently have %d available contacts.\n", 
         main_user_details.available_contacts);
  printf("You currently have %d saved contacts.\n\n", 
         main_user_details.filled_contacts);
  add_contact();
  remove_contact();
  view_contacts();
  view_emergency_contacts();
  view_blocked_contacts();
}

void introduction() {
  int user_exit = 0;
  printf("******************* CONTACT MANAGEMENT SYSTEM *******************\n");
  printf("*******************         HOMEPAGE          *******************\n");
  if(main_user_details.username[0] == ' ') {
    initialize_contacts();
    printf("Enter Your Name:\n");
    fgets(main_user_details.username, 
          sizeof(main_user_details.username), stdin);
    printf("\n\n");
  }
  printf("Welcome, %s", main_user_details.username);
  contacts_homepage();
  printf("Do you wish to exit? (1 for YES/ 0 for NO)\n");
  check_invalid_input(&user_exit);
  if (user_exit) {
    printf("\n");
    printf("******* THANK YOU FOR USING THE CONTACT MANAGEMENT SYSTEM *******");
    printf("\n\n");
    exit(EXIT_SUCCESS);
  } else {
    printf("\n");
    introduction();
  }
}
