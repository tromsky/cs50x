#include <cs50.h>
#include <math.h>
#include <stdio.h>

int get_sub_sum(int number);
int get_checksum(long credit_card_number, int number_of_digits);
int get_first_digit(long number);
int get_first_pair_of_digits(long number);

int main(void) {
  long credit_card_number = 0;

  // prompt the user for a credit card number
  // continue prompting until a valid number is entered
  do {
    credit_card_number = get_long("Number: ");
  } while (credit_card_number <= 0);

  // had to look this up
  int number_of_digits = floor(log10(credit_card_number)) + 1;
  int sum = get_checksum(credit_card_number, number_of_digits);

  int first_number = get_first_digit(credit_card_number);
  int first_pair = get_first_pair_of_digits(credit_card_number);

  // determine validity and card type
  if ((number_of_digits == 13 || number_of_digits == 16) && sum % 10 == 0 &&
      first_number == 4) {
    printf("VISA\n");
  } else if (number_of_digits == 16 && sum % 10 == 0 &&
             (first_pair == 51 || first_pair == 52 || first_pair == 53 ||
              first_pair == 54 || first_pair == 55)) {
    printf("MASTERCARD\n");
  } else if (number_of_digits == 15 && sum % 10 == 0 &&
             (first_pair == 34 || first_pair == 37)) {
    printf("AMEX\n");
  } else {
    printf("INVALID\n");
  }
}

int get_sub_sum(int number) {
  int first = number / 1 % 10;
  int second = number / 10 % 10;
  int sub_sum = first + second;

  return sub_sum;
}

int get_checksum(long credit_card_number, int number_of_digits) {
  long start = 1;
  int sum;

  for (int i = 1; i <= number_of_digits; i++) {
    // number / 1 % 10 gives last digit
    // number / 10 % 10 gives second last digit
    int number = credit_card_number / start % 10;
    start = start * 10;

    // for every other number multiply by 2
    if (i % 2 == 0) {
      int product = number * 2;
      if (product > 9) {
        int sub_sum = get_sub_sum(product);
        sum = sum + sub_sum;
      } else {
        sum = sum + product;
      }
    } else {
      sum = sum + number;
    }
  }

  return sum;
}

int get_first_digit(long number) {
  // https://www.geeksforgeeks.org/find-first-last-digits-number/
  // remove last digit from number
  // until only one digit is left
  do {
    number = number / 10;
  } while (number >= 10);

  return number;
}

int get_first_pair_of_digits(long number) {
  // https://www.geeksforgeeks.org/find-first-last-digits-number/
  do {
    number = number / 10;
  } while (number >= 100);

  return number;
}
