class Date 
{
private:
    int day; 
    int month; 
    int year;
public:
	Date(int = 1, int = 1, int = 1);
    bool isLeapYear();
    bool isValidDate();
};