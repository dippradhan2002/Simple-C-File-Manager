#include <stdio.h>
#include <stdlib.h>

int main() {
  // Create a file pointer.
  FILE *fp;

  // Get the user's input.
  char command[100];
  printf("What would you like to do?\n");
  printf("1. Create a file\n");
  printf("2. Delete a file\n");
  printf("3. Modify a file\n");
  scanf("%s", command);

  // Check the user's input.
  if (strcmp(command, "1") == 0) {
    // Create a new file.
    printf("Enter the name of the file you want to create: ");
    char filename[100];
    scanf("%s", filename);
    fp = fopen(filename, "w");
    if (fp == NULL) {
      printf("Error opening file.\n");
      return 1;
    }
    printf("File created successfully.\n");
    fclose(fp);
  } else if (strcmp(command, "2") == 0) {
    // Delete a file.
    printf("Enter the name of the file you want to delete: ");
    char filename[100];
    scanf("%s", filename);
    if (remove(filename) == 0) {
      printf("File deleted successfully.\n");
    } else {
      printf("Error deleting file.\n");
      return 1;
    }
  } else if (strcmp(command, "3") == 0) {
    // Modify a file.
    printf("Enter the name of the file you want to modify: ");
    char filename[100];
    scanf("%s", filename);
    fp = fopen(filename, "r+");
    if (fp == NULL) {
      printf("Error opening file.\n");
      return 1;
    }
    // Get the user's input.
    char line[100];
    printf("Enter the text you want to add to the file: ");
    scanf("%s", line);
    fputs(line, fp);
    printf("Text added successfully.\n");
    fclose(fp);
  } else {
    printf("Invalid command.\n");
    return 1;
  }

  return 0;
}

