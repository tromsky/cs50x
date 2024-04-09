#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_pyramid(int height);

int main(void) {
  // get a height from the user
  int height = get_height();
  print_pyramid(height);
}

int get_height(void) {
  // sets height to initial value of 0
  // then prompts the user to enter a number between 1 and 8
  // continue prompting until a value that meets the requirement is entered

  int height = 0;
  do {
    height = get_int("Height: ");
  } while (height < 1 || height > 8);

  return height;
}

void print_pyramid(int height) {
  // for the height of the pyramid
  // start at 1 and count up
  // "for each row"
  for (int i = 1; i <= height; i++) {
    // print spaces for height of the pyramid less one
    for (int j = 0; j < height - i; j++) {
      printf("%c", ' ');
    }

    // print hashes
    for (int k = 1; k <= i; k++) {
      printf("%c", '#');
    }

    // print the gap
    printf("  ");

    // print the hashes on the other side of the gap
    for (int l = 1; l <= i; l++) {
      printf("%c", '#');
    }

    // print newline
    printf("\n");
  }
}
