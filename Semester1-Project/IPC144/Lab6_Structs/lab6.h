struct DateTime
{
	int day;
	int month;
	int year;
	int hour;
	int minute;
};

void makeChange(int, int*, int*, int*);
void setDate(const char [], struct DateTime*);
void printDateTime(const struct DateTime*);
void setTime(const char [], struct DateTime*);
void countCharacters(const char*, int*, int*);
void minMaxAverage(int [],int, int*, int*, double*);