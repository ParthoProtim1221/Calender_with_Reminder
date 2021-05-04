#include<iostream>
using namespace std;
struct reminder
{
            int date;
            int year;
            string month;
            string info; 
            struct reminder *next;
};
reminder *head = NULL;
void addReminder(){
    int date;
    int year;
    string month;
    string info; 
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the date: ";
    cin >> date;
    cin.ignore();
    cout << "Enter the Message: ";
    getline(cin,info);
    if(head== NULL)
    {
        head = new reminder();
        head->date = date;
        head->year = year;
        head->month = month;
        head->info = info;
        return ;
    }
    else{
        reminder* current = head;
        while(current->next!=NULL)
        {
            
            current = current->next;
        }
        reminder* c1 = current;
        current = new reminder();
        current->date = date;
        current->year = year;
        current->month = month;
        current->info = info;
        c1->next = current;
    }
}
void showallReminder(){
    if(head== NULL)
    {
        cout << "There is no reminder" << endl;
        return ;
    }
    reminder* current = head;
    while(current!=NULL){
        {
            cout << "Year: " << current->year << endl;
            cout << "Month: "<< current->month << endl;
            cout << "Date: " << current->date<< endl;
            cout << "Message: " << current->info << endl;
            current = current->next;
        }
    }
}

int dayNumber(int day, int month, int year)
{

	static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
					4, 6, 2, 4 };
	year -= month < 3;
	return ( year + year/4 - year/100 +
			year/400 + t[month-1] + day) % 7;
}

string getMonthName(int monthNumber)
{
	string months[] = {"January", "February", "March",
					"April", "May", "June",
					"July", "August", "September",
					"October", "November", "December"
					};

	return (months[monthNumber]);
}

int numberOfDays (int monthNumber, int year)
{
	if (monthNumber == 0)
		return (31);

	if (monthNumber == 1)
	{
		if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
			return (29);
		else
			return (28);
	}

	if (monthNumber == 2)
		return (31);

	if (monthNumber == 3)
		return (30);

	if (monthNumber == 4)
		return (31);
	if (monthNumber == 5)
		return (30);

	if (monthNumber == 6)
		return (31);

	if (monthNumber == 7)
		return (31);

	if (monthNumber == 😎
		return (30);

	if (monthNumber == 9)
		return (31);

	if (monthNumber == 10)
		return (30);

	if (monthNumber == 11)
		return (31);
}

void printCalendar(int year)
{
	cout << "		 Calendar -" << year<< endl;
	cout << "----------------------------------------------------"<< endl << endl;
	int days;

	int current = dayNumber (1, 1, year);
for (int i = 0; i < 12; i++)
	{
		days = numberOfDays (i, year);

		
			string month = getMonthName (i);
			cout << "\n ------------"<< month <<"-------------\n",

		cout << " Sun Mon Tue Wed Thu Fri Sat\n";

		int k;
		for (k = 0; k < current; k++)
			cout << "	 ";

		for (int j = 1; j <= days; j++)
		{
			cout << j << "  ";

			if (++k > 6)
			{
				k = 0;
				cout << endl;
			}
		}

		if (k)
			cout << endl;

		current = k;
	}

	return;
}
void Calendar(){
    int year;
	cout << "Enter a Year: ";
	cin >> year;
	printCalendar(year);
}
int main()
{
    int choice;
    cout << "1. show a year Calendar. " << endl ;
    cout << "2. Set reminder. "<< endl ;
    cout << "3. Show All reminder. " << endl ;
    cout << "4. Exit. " << endl;
    
    cout << "Enter your choice: " ;
    cin >> choice;
    while(choice<4)
    {
        if(choice == 1)
        {
            Calendar();
        }
        else if(choice == 2)
        {
            addReminder();
        }
        else if(choice==3)
        {
            showallReminder();
        }
        cout << endl << endl;
        cout << "1. show a year Calendar. " << endl ;
        cout << "2. Set reminder. "<< endl ;
        cout << "3. Show All reminder. " << endl ;
        cout << "4. Exit. " << endl;
        
        cout << "Enter your choice: ";
        cin >> choice;
    }
	return 0;
}
