#include <string>
#include <iostream>
class Record{
public:
	void setRecord(int num, std::string str, int x, int y, int z);
	void printRecord() const;
private:
	int no;
	std::string name;
	int score1;
	int score2;
	int score3;
	float average;

};

void Record::setRecord(int num, std::string str, int x, int y, int z){
	score1 = x;
	score2 = y;
	score3 = z;
	no	   = num;
	name   = str;
	//type casting: int to float
	average= float( x + y + z ) / 3;
}

void Record::printRecord() const{

	std::cout << no << "\t" << name << "\t" << score1 << "\t"
				<< score2 << "\t" << score3 << "\t" << average << std::endl;
}



#include <vector>
using namespace std;

int main(){
	//ask records of students
	cout << "Input 10 records of students. Each record consists of a name (w/o space), and scores for three courses (in integer, 1 to 5):"
	 	<< endl;
	//set parameters
	string name = "";
	int score1 = 0;
	int score2 = 0;
	int score3 = 0;
	float sum1 = 0;
	float sum2 = 0;
	float sum3 = 0;
	int min1 = 6;
	int min2 = 6;
	int min3 = 6;
	int max1 = 0;
	int max2 = 0;
	int max3 = 0;
	int amount = 10;
	vector<Record> vec;
	//read in records
	for (int i = 1; i <= amount; i++){
		cout << "no." << i << "\tname:\tscore1:\tscore2:\tscore3:" << endl;
		cin >> name >> score1 >> score2 >> score3;

		Record recordi;
		recordi.setRecord(i, name, score1, score2, score3);
		vec.push_back(recordi);
		//calculate sum of each course
		sum1 = sum1 + score1;
		sum2 = sum2 + score2;
		sum3 = sum3 + score3;
		//calculate min & max
		if (min1 >= score1) min1 = score1;
		if (min2 >= score2) min2 = score2;
		if (min3 >= score3) min3 = score3;	
		if (max1 <= score1) max1 = score1;
		if (max2 <= score2) max2 = score2;
		if (max3 <= score3) max3 = score3;	
	}
	//output results
	cout << "no" << "\t" << "name" << "\t" << "score1" << "\t"
		    << "score2" << "\t" << "score3" << "\t" << "average" << endl;
	for (vector<Record>::iterator it = vec.begin(); it != vec.end(); it++){
		(*it).printRecord();
	}
	cout << "\taverage\t" << sum1/amount << "\t" << sum2/amount << "\t" << sum3/amount << endl
		 << "\tmin\t" << min1 << "\t" << min2 << "\t" << min3 << endl
		 << "\tmax\t" << max1 << "\t" << max2 << "\t" << max3 << endl;

	return 0;
}