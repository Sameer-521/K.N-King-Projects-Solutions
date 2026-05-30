# Chapter 3 - Programming Projects

## Project 1 (`p01_date.c`)

Write a program that accepts a date from the user in the form mm/dd/yyyy and then displays it in the form yyyymmdd:

```
Enter a date (mm/dd/yyyy): 2/17/2011
You entered the date 20110217
```

---

## Project 2 (`p02_product_info.c`)

Write a program that formats product information entered by the user. A session with the program should look like this:

```
Enter item number: 583
Enter unit price: 13.5
Enter purchase date (mm/dd/yyyy): 10/24/2010
Item       Unit       Purchase
           Price      Date
583        $ 13.50    10/24/2010
```

The item number and date should be left justified; the unit price should be right justified. Allow dollar amounts up to $9999.99. Hint: Use tabs to line up the columns.

---

## Project 3 (`p03_isbn.c`)

Books are identified by an International Standard Book Number (ISBN). ISBNs assigned after January 1, 2007 contain 13 digits, arranged in five groups, such as 978-0-393-97950-3. (Older ISBNs use 10 digits.) The first group (the GS1 prefix) is currently either 978 or 979. The group identifier specifies the language or country of origin (for example, 0 and 1 are used in English-speaking countries). The publisher code identifies the publisher (393 is the code for W. W. Norton). The item number is assigned by the publisher to identify a specific book (97950 is the code for this book). An ISBN ends with a check digit that's used to verify the accuracy of the preceding digits. Write a program that breaks down an ISBN entered by the user:

```
Enter ISBN: 978-0-393-97950-3
GS1 prefix: 978
Group identifier: 0
Publisher code: 393
Item number: 97950
Check digit: 3
```

Note: The number of digits in each group may vary; you can't assume that groups have the lengths shown in this example. Test your program with actual ISBN values (usually found on the back cover of a book and on the copyright page).

---

## Project 4 (`p04_telephone_num.c`)

Write a program that prompts the user to enter a telephone number in the form (xxx) xxx-xxxx and then displays the number in the form xxx.xxx.xxx:

```
Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
You entered 404.817.6900
```

---

## Project 5 (`p05_rows_and_cols.c`)

Write a program that asks the user to enter the numbers from 1 to 16 (in any order) and then displays the numbers in a 4 by 4 arrangement, followed by the sums of the rows, columns, and diagonals:

```
Enter the numbers from 1 to 16 in any order:
16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1

16  3  2 13
 5 10 11  8
 9  6  7 12
 4 15 14  1

Row sums: 34 34 34 34
Column sums: 34 34 34 34
Diagonal sums: 34 34
```

If the row, column, and diagonal sums are all the same (as they are in this example), the numbers are said to form a magic square. The magic square shown here appears in a 1514 engraving by artist and mathematician Albrecht Dürer. (Note that the middle numbers in the last row give the date of the engraving.)

---

## Project 6 (`p06_addfrac_modified.c`)

Modify the addfrac.c program of Section 3.2 so that the user enters both fractions at the same time, separated by a plus sign:

```
Enter two fractions separated by a plus sign: 5/6+3/4
The sum is 38/24
```
