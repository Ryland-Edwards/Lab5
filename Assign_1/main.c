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

double Avg(struct SaleToMonth sales[], int size){
  double sum = 0;
  for (int i = 0; i < size; i++){
    sum += sales[i].sales;
  }
  return sum / size;
}

struct SaleToMonth Min(struct SaleToMonth sales[], int size){
  struct SaleToMonth min = sales[0];
  for (int i = 1; i < size; i++){
    if (sales[i].sales < min.sales){
      min = sales[i];
    }
  }
  return min;
}

struct SaleToMonth Maximum(struct SaleToMonth sales[], int size){
  struct SaleToMonth max = sales[0];
  for (int i = 1; i < size; i++){
    if (sales[i].sales > max.sales){
      max = sales[i];
    }
  }
  return max;
}

int Compare(const void *a, const void *b) {
  double val_1 = ((struct SaleToMonth *)a)->sales;
  double val_2 = ((struct SaleToMonth *)b)->sales;
  
  if (val_2 < val_1) return -1;
  if (val_1 < val_2) return 1;
  return 0;
}

void sortSales(struct SaleToMonth *sales, size_t n) {
  qsort(sales, n, sizeof(struct SaleToMonth), Compare);
}




int main() {
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
    if (file_ch != EOF) {
      string[char_counter] = file_ch;
      char_counter++;
    }
    if (file_ch == '\n' || file_ch == EOF){
      // Convert the string to a number and store it in the array of structures
      sales[month_counter].sales = strtod(string, &end_point);

      for (int i = 0; i < 20; i++){
        sales[month_counter].month[i] = months[month_counter][i];
      }
      strcpy(string, "");
      month_counter++;
      char_counter = 0;
      continue;
    }

  }
  fclose(input_file);

  struct SaleToMonth Maximum;
  struct SaleToMonth Minimum;
  double Average;
  
  Maximum = Max(sales, 12);

  Minimum = Min(sales, 12);
  
  Average = Avg(sales, 12, 0, 12);

  printf("\nMonthly Sales Report for 2022:\n\n");
  printf("%-8s \t\t %-8s\n\n", "Month", "Sales");
  for (int i = 0; i < 12; i++){
    printf("%-8s \t\t $ %-8.2f\n", months[i], sales[i].sales);
  }

  

  printf("\nMonthly Sales Report for 2022:\n");
  printf("%-8s \t\t %-8s\n", "Month", "Sales");
  for (int i = 0; i < 12; i++)
  {
    printf("%-8s \t\t $ %-8.2f\n", months[i], sales[i].sales);
  }

  // Summary
  printf("\nMinimum sales: \t\t $ %-8.2f (%s)\n", Minimum.sales, Minimum.month);
  printf("Maxmimum sales: \t\t $ %-8.2f (%s)\n", Maximum.sales, Maximum.month);
  printf("Average sales: \t\t $ %-8.2f\n", Average);

  // 6-Month Moving Average
  char startMonth[20];
  char endMonth[20];
  printf("\nSix-Month Moving Average Report: \n");
  for (int i = 0; i < 7; i++)
  {
    strcpy(startMonth, months[i]);
    strcpy(endMonth, months[i+5]);
    printf("%-8s \t - \t %-8s \t\t $%-8.2d\n", startMonth, endMonth, Avg(sales, 12, i, i+6));
  }

  // Sorted Order
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


