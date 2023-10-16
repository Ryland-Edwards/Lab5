#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * The struct SaleToMonth represents the sales made in a specific month.
 * @property {char} month - A character array that can store the name of a month, with a maximum length
 * of 20 characters.
 * @property {double} sales - The "sales" property is a double data type, which means it can store
 * decimal numbers representing the amount of sales made in a particular month.
 */
struct SaleToMonth {
  double sales;
  char month[20];
};

/**
 * The function calculates the average sales from a given range of months.
 * 
 * @param sales The parameter "sales" is an array of structs named "SaleToMonth". Each struct in the
 * array represents sales data for a specific month.
 * @param size The size parameter represents the total number of elements in the sales array.
 * @param start The start parameter represents the index of the first element in the sales array that
 * should be included in the calculation of the average.
 * @param stop The "stop" parameter represents the index at which the loop should stop iterating. It is
 * the index of the last element in the range of the array that should be included in the calculation.
 * 
 * @return the average of the sales values in the given range.
 */
double Avg(struct SaleToMonth sales[], int size, int start, int stop){
  double sum = 0.0;
  for (int i = start; i < stop; i++)
  {
    sum += sales[i].sales;
  }
  return (sum / (double)(stop-start));
}

/**
 * The function "Min" finds the struct with the minimum sales value from an array of structs.
 * 
 * @param sales An array of structs of type SaleToMonth, representing sales data for each month.
 * @param size The parameter "size" represents the number of elements in the array "sales".
 * 
 * @return the struct SaleToMonth object with the minimum sales value.
 */
struct SaleToMonth Min(struct SaleToMonth sales[], int size){
  struct SaleToMonth min = sales[0];
  for (int i = 1; i < size; i++){
    if (sales[i].sales < min.sales){
      min = sales[i];
    }
  }
  return min;
}

/**
 * The function "Max" finds the struct with the highest sales value in an array of structs.
 * 
 * @param sales An array of structs of type SaleToMonth, representing sales data for each month.
 * @param size The parameter "size" represents the size of the array "sales". It indicates the number
 * of elements in the array that should be considered for finding the maximum value.
 * 
 * @return the struct SaleToMonth object with the highest sales value.
 */
struct SaleToMonth Max(struct SaleToMonth sales[], int size){
  struct SaleToMonth max = sales[0];
  for (int i = 1; i < size; i++){
    if (sales[i].sales > max.sales){
      max = sales[i];
    }
  }
  return max;
}

/**
 * The Compare function compares the sales values of two SaleToMonth structures.
 * 
 * @param a The parameter `a` is a pointer to a `void` type, which means it can point to any type of
 * data. In this case, it is expected to point to a structure of type `SaleToMonth`.
 * @param b The parameter `b` is a pointer to a constant void type. It is used to represent the second
 * element being compared in the `Compare` function.
 * 
 * @return The Compare function returns an integer value. It returns -1 if the sales value of the
 * second argument is less than the sales value of the first argument, 1 if the sales value of the
 * first argument is less than the sales value of the second argument, and 0 if the sales values are
 * equal.
 */
int Compare(const void *a, const void *b) {
  double val_1 = ((struct SaleToMonth *)a)->sales;
  double val_2 = ((struct SaleToMonth *)b)->sales;
  
  if (val_2 < val_1) return -1;
  if (val_1 < val_2) return 1;
  return 0;
}

/**
 * The function sorts an array of SaleToMonth structures using the qsort function.
 * 
 * @param sales sales is a pointer to an array of struct SaleToMonth objects.
 * @param n The number of elements in the sales array.
 */
void sortSales(struct SaleToMonth *sales, size_t n) {
  qsort(sales, n, sizeof(struct SaleToMonth), Compare);
}


/**
 * The above function is the main function in a C program.
 */
int main() {
  /* This block of code is declaring and initializing variables that will be used to read data from a
  file and store it in an array of structures. */
  FILE* input_file;
  struct SaleToMonth sales[12];
  char months[12][20] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  int char_counter = 0;
  int month_counter = 0;
  char file_ch;
  char* end_point;
  char string[100];

  input_file = fopen("sales_input.txt", "r");
  while (!feof(input_file)) {
    file_ch = fgetc(input_file);
    /* The code block `if (file_ch != EOF) { string[char_counter] = file_ch; char_counter++; }` is
    checking if the character read from the file is not the end-of-file (EOF) character. If it is
    not the end-of-file character, it means that there is still more data to be read from the file.
    In that case, the character is stored in the `string` array at the current `char_counter` index,
    and the `char_counter` is incremented to prepare for the next character to be read. This process
    continues until the end-of-file character is encountered or the end of the line is reached. */
    if (file_ch != EOF) {
      string[char_counter] = file_ch;
      char_counter++;
    }
    /* This code block is checking if the character read from the file is either a newline character
    (`'\n'`) or the end-of-file character (`EOF`). If either of these conditions is true, it means
    that a complete line of data has been read from the file. */
    if (file_ch == '\n' || file_ch == EOF){
      // Convert the string to a number and store it in the array of structures
      sales[month_counter].sales = strtod(string, &end_point);

      /* The code `for (int i = 0; i < 20; i++)` is a loop that iterates from 0 to 19. It is used to
      copy the characters from the `months` array to the `month` property of the `sales` struct. */
      for (int i = 0; i < 20; i++){
        sales[month_counter].month[i] = months[month_counter][i];
      }
      /* The `strcpy(string, "");` statement is used to copy an empty string into the `string` array.
      It essentially clears the contents of the `string` array, making it an empty string. This is
      done to prepare the `string` array for storing a new line of data read from the file. */
      strcpy(string, "");
      month_counter++;
      char_counter = 0;
      continue;
    }

  }
  fclose(input_file);

  /* The code is declaring three variables: `Maximum`, `Minimum`, and `Average`. */
  struct SaleToMonth Maximum;
  struct SaleToMonth Minimum;
  double Average;
  
  /* The line `Minimum = Min(sales, 12);` is calling the `Min` function and assigning the returned
  value to the variable `Minimum`. */
  Minimum = Min(sales, 12);

  /* The line `Maximum = Max(sales, 12);` is calling the `Max` function and assigning the returned
  value to the variable `Maximum`. The `Max` function finds the struct with the highest sales value
  in an array of structs. In this case, it is finding the struct with the highest sales value from
  the `sales` array, which contains sales data for each month. The `Max` function takes two
  arguments: the `sales` array and the size of the array (which is 12 in this case). It returns the
  struct `SaleToMonth` object with the highest sales value. */
  Maximum = Max(sales, 12);
  
  /* The line `Average = Avg(sales, 12, 0, 12);` is calculating the average sales value from the
  `sales` array. */
  Average = Avg(sales, 12, 0, 12);

  /* The code is printing a monthly sales report for the year 2022. */
  printf("\nMonthly Sales Report for 2022:\n\n");
  printf("%-8s \t\t %-8s\n\n", "Month", "Sales");
  for (int i = 0; i < 12; i++){
    printf("%-8s \t\t\t $ %-8.2f\n", months[i], sales[i].sales);
  }



  /* The `printf` statements are used to print the minimum sales, maximum sales, and average sales
  values. */
  printf("\nMinimum sales: \t\t $ %-8.2f (%s)\n", Minimum.sales, Minimum.month);
  printf("Maxmimum sales: \t\t $ %-8.2f (%s)\n", Maximum.sales, Maximum.month);
  printf("Average sales: \t\t $ %-8.2f\n", Average);


  /* The code block is generating a six-month moving average report. */
  char startMonth[20];
  char endMonth[20];
  printf("\nSix-Month Moving Average Report: \n");
  for (int i = 0; i < 7; i++)
  {
    /* The `strcpy` function is used to copy a string from one location to another. In this case,
    `strcpy(startMonth, months[i])` is copying the string stored in the `months[i]` array to the
    `startMonth` array. Similarly, `strcpy(endMonth, months[i+5])` is copying the string stored in
    the `months[i+5]` array to the `endMonth` array. */
    strcpy(startMonth, months[i]);
    strcpy(endMonth, months[i+5]);
    printf("%-8s \t - \t %-8s \t\t $%-8.2f\n", startMonth, endMonth, Avg(sales, 12, i, i+6));
  }


  /* This code block is generating a sales report in descending order, from highest to lowest sales. */
  printf("\nSales Report (Highest to Lowest)\n");
  printf("%8s \t\t %8s", "Month", "Sales\n");
  sortSales(sales, 12);
  for (int i = 0; i < 12; i++)
  {
    printf("%-10s \t\t $ %-10.2f", sales[i].month, sales[i].sales);
    printf("\n");
  }
  
  return 0;
}


