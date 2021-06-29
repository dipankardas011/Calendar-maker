Calendar::Calendar(void) : YEAR(1), MONTH(1), DAY(1) {}

void Calendar::yearInput(int yy)
{

    try
    {
        if (yy < 0 || yy > 9999)
            throw(yy);
    }
    catch (int x)
    {
        cout << "^~~~~ INVALID YEAR" << endl;
        cout << "{0x01 program ending}" << endl;
        exit(0);
    }
    // so now assign the year val
    this->YEAR = yy;
}

void printMonthName(int mm)
{
    /* it prints the month name wrt to the month number */
    switch (mm)
    {
    case Jan:
        printf("%10s", "January");
        break;
    case Feb:
        printf("%10s", "February");
        break;
    case Mar:
        printf("%10s", "March");
        break;
    case Apr:
        printf("%10s", "April");
        break;
    case May:
        printf("%10s", "May");
        break;
    case Jun:
        printf("%10s", "June");
        break;
    case Jul:
        printf("%10s", "July");
        break;
    case Aug:
        printf("%10s", "August");
        break;
    case Sep:
        printf("%10s", "September");
        break;
    case Oct:
        printf("%10s", "October");
        break;
    case Nov:
        printf("%10s", "November");
        break;
    case Dec:
        printf("%10s", "December");
        break;
    }
}

void Calendar::monthInput(void)
{
    cout << "enter the month number for the calendar... " << endl;
    cin >> this->MONTH;
    try
    {
        if (this->MONTH < 0 || this->MONTH > 12)
            throw(this->MONTH);
    }
    catch (int x)
    {
        cout << "^~~~~ INVALID Month input" << endl;
        cout << "{0x02 program ending}" << endl;
        exit(0);
    }
}

/**
  * @def lastDayOfMonth
  * returning the last day of the months with respect to the year
  */
int lastDayOfMonth(int mm, int yy)
{
    // int mm = this->MONTH;
    if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        return 31;
    else if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        return 30;
    else if (mm == 2)
    {
        if (isLeapYear(yy))
            return 29;
        else
            return 28;
    }
    else
        return -9999;
}

int startingDayNumber(int day, int month, int year)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;
}

