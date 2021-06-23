
//                   Hospital Management System

#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<stdlib.h>
#include<stdio.h>



using namespace std;

//function declarations



void clear_screen(); //go and adjust this function according to your system at bottom;
void menu();
int chooseMain();
void getDoctorDatabase();
void	getPatientDatabase();
void getBedDatabase();
void	getPatientReport();


//the password class
// ------------------------------------------------------------------------------------------------

class password {
private:
	string pass;
public:
	void getPassword() {
		cout << "\n\t\t\t\t\t\tChoose a password for your system: " ;
		cin >> pass;
	}

	int verifyPassword()
	{
		string x;
		cout << "\n\t\t\t\t\t\tEnter the password: ";
		cin >> x;
		if (x == pass)
			return 1;
		else
			return 0;
	}

	void passwordProtect() {
		int veri = verifyPassword();

		if (veri == 1) {
			cout << "\n\t\t\t\t\t\tAccess Granted!" << endl;
		}
		else
		{
			cout << "\n\t\t\t\t\tAccess Denied!\n\n\t\t\t\t\tSystem will shut down\n\n\t\t\t\t\tPlease come back again." << endl;
			exit(0);
		}
	}
};

// password class ends
// ---------------------------------------------------------------------------------------------------------




//the doctor class
// ---------------------------------------------------------------------------------------------------------


class doctor {
public:
	string d_fname, d_lname;
	int d_ID, d_age, experience, d_totalno;
	string qual, d_city;
	string getSpec();
	friend void addDoc();
	friend void editDoc(doctor &docobj);
	friend void displayDoc();
	friend void deleteDoc();
	friend void dispDatabase();
	friend void numberofDocs();
	friend void getDoctorDatabase();
};


// doctor class ends here
// ---------------------------------------------------------------------------------------------------------



// Doctor Specility
// ---------------------------------------------------------------------------------------------------------

string doctor::getSpec() {
	string sp;

	cout << "\t\t\t\t\t\t\t1.GENERAL_MEDICINE" << endl;
	cout << "\t\t\t\t\t\t\t2.NEUROLOGY" << endl;
	cout << "\t\t\t\t\t\t\t3.ONCOLOGY" << endl;
	cout << "\t\t\t\t\t\t\t4.HAEMATOLOGY" << endl;
	cout << "\t\t\t\t\t\t\t5.GASTROENTEROLOGY" << endl;
	cout << "\t\t\t\t\t\t\t6.GYNAECOLOGY " << endl;
	cout << endl;
	int s;
	cout << "\t\t\t\t\t\t";
	cin >> s;
	switch (s) {

	case 1: {
		sp = "GENERAL_MEDICINE";
		break;
	}
	case 2: {
		sp = "NEUROLOGY";
		break;
	}
	case 3: {
		sp = "ONCOLOGY";
		break;
	}
	case 4: {
		sp = "HAEMATOLOGY";
		break;
	}
	case 5: {
		sp = "GASTROENTEROLOGY";
		break;
	}
	case 6: {
		sp = "GYNAECOLOGY ";
		break;
	}
	default: {
		cout << "\n\t\t\t\t\tCome on!Enter a valid option." << endl;

	}

	}
	return sp;

}
// Doctor Speciality Ends
// ---------------------------------------------------------------------------------------------------------





//the Adding New Doctor function
// ---------------------------------------------------------------------------------------------------------



void addDoc() {
	doctor d;
	cout << "\n\t\t\t\t\tFill up the following details" << endl;
	cout << "\t\t-------------------------------------------------------------------------------------------" << endl;
	cout << "\n\t\t\t\t\t\tID: ";
	cin >> d.d_ID;
	cout << "\n\t\t\t\t\t\tFirst Name: ";
	cin >> d.d_fname;
	cout << "\n\t\t\t\t\t\tLast Name: " ;
	cin >> d.d_lname;
	cout << "\n\t\t\t\t\t\tAge: " ;
	cin >> d.d_age;
	cout << "\n\t\t\t\t\t\tChoose Qualification among the following:\n\t\t\t\t\t\t\t1.MBBS\n\t\t\t\t\t\t\t2.MD" << endl;
	int q;
	cout << "\t\t\t\t\t\t";
	cin >> q;
	if (q == 1)
		d.qual = "MBBS";
	else d.qual = "MD";
	cout << "\n\t\t\t\t\t\tChoose Specialization among the following: " << endl;;
	string spec = d.getSpec();
	cout << "\n\t\t\t\t\t\tExperience (in Years): ";
	cin >> d.experience;
	cout << "\n\t\t\t\t\t\tCity: ";
	cin >> d.d_city;


	clear_screen();
	fstream fileObj;
	fileObj.open("doctor.txt", ios::app );
	fileObj.seekp (0, ios::end);
	fileObj << d.d_ID << endl << d.d_fname << endl << d.d_lname << endl << d.d_age << endl << d.qual << endl << spec << endl << d.experience << endl << d.d_city << endl;
	fileObj.close();



	cout << "\n\t\t\t\t\tNew Doctor profile created successfully!" << endl << endl << endl;


	cout << "\n\t\t\t\t\tEnter 1 to return to Doctor Database\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getDoctorDatabase();
	}

	else
		exit(0);

}

// Add Doctor Functions End Here
// ---------------------------------------------------------------------------------------------------------




// Edit Doctor Function Starts Here
// ---------------------------------------------------------------------------------------------------------


void editDoc(doctor &docobj)
{

	string x;
	cout << "\n\n\t\t\t\t\tEnter the ID of the Doctor whose profile you want to Edit: " ;
	cin >> x;
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);

	int age, exp, count = 0;
	string ID, fname, lname, ci, qua, spe;
	while (fileObj >> ID >> fname >> lname >> age >> qua >> spe >> exp >> ci)
	{
		if (ID == x) {
			cout << "\n\n\t\t\t\t\t1.ID:" << ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age:" << age << endl << "\t\t\t\t\t5.Qualification:" << qua << endl << "\t\t\t\t\t6.Specialization:" << spe << endl << "\t\t\t\t\t7.Experience:" << exp << endl << "\t\t\t\t\t8.City:" << ci << endl << endl;
			count++;
			break;
		}
	}

	fileObj.close();



	if (count == 0) {
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;
		cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
		cout << "\t\t\t\t\t\t";
		int c;
		cin >> c;
		if (c == 1) {
			clear_screen();
			getDoctorDatabase();
		}

		else
			exit(0);
	}



	fstream file("doctor.txt");
	file.seekg (0, ios::beg);
	file.seekg(0);
	string line;
	ofstream tempObj;
	tempObj.open("copy.txt");
	tempObj.seekp(0);
	int skip = 0;
	int age1, exp1;
	string fname1, lname1, ci1, qua1, spe1;
	file.seekg(0); file.seekg(0, ios::cur);


	while (file >> line >> fname1 >> lname1 >> age1 >> qua1 >> spe1 >> exp1 >> ci1)
	{
		if (line != x) {
			tempObj << line << endl << fname1 << endl << lname1 << endl << age1 << endl << qua1 << endl << spe1 << endl << exp1 << endl << ci1 << endl;
		}
	}

	file.close();
	tempObj.close();
	remove("doctor.txt");
	int result;
	char oldname[] = "copy.txt";
	char newname[] = "doctor.txt";
	result = rename( oldname , newname );
	//datatransfer ends
	int edit;
	cout << "\t\t\t\t\tEnter number corresponding to the Field you want to Edit: ";
	cin >> edit;
	cout << endl;
	switch (edit)
	{
	case 1: {
		cout << "\t\t\t\t\tID :" ;
		cin >> ID;
		break;
	}
	case 2: {
		cout << "\t\t\t\t\tFirst Name: " ;
		cin >> fname;

		break;
	}
	case 3: {
		cout << "\t\t\t\t\tLast Name: " ;
		cin >> lname;

		break;
	}
	case 4: {
		cout << "\t\t\t\t\tAge: " ;
		cin >> age;
		break;
	}
	case 5: {
		cout << "\t\t\t\t\tChoose Qualification among the following:\n\t\t\t\t\t\t1.MBBS\n\t\t\t\t\t\t2.MD" << endl;
		cout << "\t\t\t\t\t";
		int q;
		cin >> q;
		if (q == 1) {
			qua = "MBBS";
		}

		else {
			qua = "MD";
		}

		break;
	}
	case 6: {
		clear_screen();
		spe = docobj.getSpec();
		break;
	}
	case 7: {
		cout << "\t\t\t\t\tExperience: " ;
		cin >> exp;
		break;
	}
	case 8: {
		cout << "\t\t\t\t\tCity: " ;
		cin >> ci;
		break;
	}
	default: {
		cout << "\t\t\t\t\t\tInvalid Input!" << endl;
		cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
		cout << "\t\t\t\t\t\t";
		int c;
		cin >> c;
		if (c == 1) {
			clear_screen();
			getDoctorDatabase();
		}

		else
			exit(0);
	}
	}

	clear_screen();

	cout << "\t\t\t\t--------------Updated Profile-----------------" << endl << endl;
	cout << "\n\n\t\t\t\t\t1.ID:" << ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age:" << age << endl << "\t\t\t\t\t5.Qualification:" << qua << endl << "\t\t\t\t\t6.Specialization:" << spe << endl << "\t\t\t\t\t7.Experience:" << exp << endl << "\t\t\t\t\t8.City:" << ci << endl << endl;

	fstream newObj;
	newObj.open("doctor.txt", ios::app);
	newObj.seekp (0, ios::end);
	newObj << ID << endl << fname << endl << lname << endl << age << endl << qua << endl << spe << endl << exp << endl << ci << endl;
	newObj.close();



	cout << "\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getDoctorDatabase();
	}

	else
		exit(0);
}


// Edit Doctor Functions Ends Here
// ---------------------------------------------------------------------------------------------------------




//the Display Doctor Function
// ---------------------------------------------------------------------------------------------------------


void displayDoc()
{
	int x;
	cout << "\n\n\t\t\t\t\tEnter the ID of the Doctor whose profile you want to Edit: " ;
	cin >> x;
	ifstream file; file.open("doctor.txt", ios::out | ios::in);
	file.seekg(0);

	int ID, age, exp, count = 0;
	string fname, lname, ci, qua, spe;

	while (file >> ID >> fname >> lname >> age >> qua >> spe >> exp >> ci)
	{

		if (ID == x)
		{
			cout << "\n\n\t\t\t\t\t1.ID:" << ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age:" << age << endl << "\t\t\t\t\t5.Qualification:" << qua << endl << "\t\t\t\t\t6.Specialization:" << spe << endl << "\t\t\t\t\t7.Experience:" << exp << endl << "\t\t\t\t\t8.City:" << ci << endl << endl;

			count++;
		}
	}
	file.close();
	if (count == 0)
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getDoctorDatabase();
	}

	else
		exit(0);

}

// Display Doctor Functions End
// ---------------------------------------------------------------------------------------------------------



//the Delete Doctor function
// ---------------------------------------------------------------------------------------------------------


void deleteDoc() {
	string x;
	cout << "\n\n\t\t\t\t\tEnter the ID of the Doctor whose profile you want to Edit: " ;

	cin >> x;
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);

	int age, exp, count = 0;
	string ID, fname, lname, ci, qua, spe;
	while (fileObj >> ID >> fname >> lname >> age >> qua >> spe >> exp >> ci)
	{
		if (ID == x) {
			cout << "\n\n\t\t\t\t\t1.ID:" << ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age:" << age << endl << "\t\t\t\t\t5.Qualification:" << qua << endl << "\t\t\t\t\t6.Specialization:" << spe << endl << "\t\t\t\t\t7.Experience:" << exp << endl << "\t\t\t\t\t8.City:" << ci << endl << endl;
			count++;
			break;
		}
	}

	fileObj.close();
	if (count == 0) {
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;
		cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
		cout << "\t\t\t\t\t\t";
		int c;
		cin >> c;
		if (c == 1) {
			clear_screen();
			getDoctorDatabase();
		}

		else
			exit(0);
	}


	cout << "\t\t\t\t\tAre you sure you want to delete this profile?\n\t\t\t\t\t1.YES\n\t\t\t\t\t2.NO" << endl;
	cout << "\n\t\t\t\t\t";
	int n; cin >> n;
	if (n == 1) {
		fstream file("doctor.txt");
		file.seekg (0, ios::beg);
		file.seekg(0);
		string line;
		ofstream tempObj;
		tempObj.open("copy.txt");
		tempObj.seekp(0);
		int skip = 0;
		int age1, exp1;
		string fname1, lname1, ci1, qua1, spe1;
		file.seekg(0); file.seekg(0, ios::cur);


		while (file >> line >> fname1 >> lname1 >> age1 >> qua1 >> spe1 >> exp1 >> ci1)
		{
			if (line != x) {
				tempObj << line << endl << fname1 << endl << lname1 << endl << age1 << endl << qua1 << endl << spe1 << endl << exp1 << endl << ci1 << endl;
			}
		}

		file.close();
		tempObj.close();
		remove("doctor.txt");
		int result;
		char oldname[] = "copy.txt";
		char newname[] = "doctor.txt";
		result = rename( oldname , newname );
		clear_screen();
		cout << "\n\t\t\t\t\tFile successfully deleted" << endl;

	}
	clear_screen();

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getDoctorDatabase();
	}

	else
		exit(0);

}

// Delete Doctor Functions Ends Here
// ---------------------------------------------------------------------------------------------------------




//the Display DataBase Function
// ---------------------------------------------------------------------------------------------------------




void dispDatabase() {
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	cout << "\t\t\t\t\t\tDOCTOR DATABASE" << endl << endl;
	int age, exp, count = 0;
	string ID, fname, lname, ci, qua, spe;
	while (fileObj >> ID >> fname >> lname >> age >> qua >> spe >> exp >> ci)
	{	count++;
		cout << "\t\t\t\t\t\tDoctor Profile:" << count << endl;
		cout << "\n\t\t\t\t\t1.ID:" << ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age:" << age << endl << "\t\t\t\t\t5.Qualification:" << qua << endl << "\t\t\t\t\t6.Specialization:" << spe << endl << "\t\t\t\t\t7.Experience:" << exp << endl << "\t\t\t\t\t8.City:" << ci << endl << endl;

		// cout << "\n\n1.ID:" << ID << endl << "2.First Name:" << fname << endl << "3.Last Name:" << lname << endl << "4.Age:" << age << endl << "5.Qualification:" << qua << endl << "6.Specialization:" << spe << endl << "7.Experience:" << exp << endl << "8.City:" << ci << endl << endl;
	}

	if (count == 0) {
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;
	}

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;


	cout << "\n\n\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getDoctorDatabase();
	}

	else
		exit(0);
}

// Display Database Function Ends Here
// ---------------------------------------------------------------------------------------------------------




//Total NUmber Of Doctors function
// ---------------------------------------------------------------------------------------------------------

void numberofDocs() {

	fstream fileObj("doctor.txt");
	fileObj.seekg(0);
	int age, exp, count = 0;
	string ID, fname, lname, ci, qua, spe;
	while (fileObj >> ID >> fname >> lname >> age >> qua >> spe >> exp >> ci)
	{	count++;
	}
	cout << "\n\n\t\t\t\t\tThe Total number of doctors in the hospital=" << count << endl << endl;

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getDoctorDatabase();
	}

	else
		exit(0);
}
//Total NUmber Of Doctors function Ends Here
// ---------------------------------------------------------------------------------------------------------








//Patient Class
// ---------------------------------------------------------------------------------------------------------


class patient {
public:
	string fname, lname, occupation, p_city, dis, addDate, relDate;
	int p_age, p_ID;
	long double phnumber, bill;
	string getDept();
	friend void getDoctor();
	friend void addPat();
	friend void editPat(patient &pat);
	friend void displayPat();
	friend void deletePat();
	friend void dispPatDatabase();
	friend void numberofPats();
	friend void getPatientDatabase();

};

// ---------------------------------------------------------------------------------------------------------


// Department Function
// ---------------------------------------------------------------------------------------------------------

string patient::getDept() {
	string sp;
	cout << "\t\t\t\t\t\t\t1.GENERAL_MEDICINE" << endl;
	cout << "\t\t\t\t\t\t\t2.NEUROLOGY" << endl;
	cout << "\t\t\t\t\t\t\t3.ONCOLOGY" << endl;
	cout << "\t\t\t\t\t\t\t4.HAEMATOLOGY" << endl;
	cout << "\t\t\t\t\t\t\t5.GASTROENTEROLOGY" << endl;
	cout << "\t\t\t\t\t\t\t6.GYNAECOLOGY " << endl << endl;
	int s;
	cout << "\t\t\t\t\t\t";
	cin >> s;
	switch (s) {

	case 1: {
		sp = "GENERAL_MEDICINE";
		break;
	}
	case 2: {
		sp = "NEUROLOGY";
		break;
	}
	case 3: {
		sp = "ONCOLOGY";
		break;
	}
	case 4: {
		sp = "HAEMATOLOGY";
		break;
	}
	case 5: {
		sp = "GASTROENTEROLOGY";
		break;
	}
	case 6: {
		sp = "GYNAECOLOGY ";
		break;
	}
	default: {
		cout << "\nCome on!Enter a valid option." << endl;

	}

	}
	return sp;
}
// ---------------------------------------------------------------------------------------------------------


// Get Doctor Function
// ---------------------------------------------------------------------------------------------------------

void getDoctor() {
	patient p;
	string dept;
	cout << "\n\t\t\t\t\tEnter the kind of specialization you are looking for:" << endl << endl;
	dept = p.getDept();
	fstream fileObj("doctor.txt");
	fileObj.seekg(0);

	int age, exp, count = 0;
	string ID, fname, lname, ci, qua, spe;
	while (fileObj >> ID >> fname >> lname >> age >> qua >> spe >> exp >> ci)
	{
		if (spe == dept) {
			cout << "\n\t\t\t\t\tThe doctors available with  " << dept << " specialization are:" << endl << endl;
			cout << "\n\t\t\t\t\t\t1.ID:" << ID << endl << "\t\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t\t4.Age:" << age << endl << "\t\t\t\t\t\t5.Qualification:" << qua << endl << "\t\t\t\t\t\t6.Specialization:" << spe << endl << "\t\t\t\t\t\t7.Experience:" << exp << endl << "\t\t\t\t\t\t8.City:" << ci << endl << endl;
			count++;
		}
	}

	fileObj.close();
	if (count == 0) {
		cout << "\t\t\t\t\tNo doctors with this specialization found!" << endl;
	}
	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;


	cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();
	}

	else
		exit(0);
}
// Get Doctor Functions End Here
// ---------------------------------------------------------------------------------------------------------



// Add patient Function
// ---------------------------------------------------------------------------------------------------------


void addPat() {

	patient p;
	cout << "\n\t\t\t\t\tFill up the following details" << endl;
	cout << "\t\t-------------------------------------------------------------------------------------------" << endl;

	cout << "\n\t\t\t\t\t\tID: ";
	cin >> p.p_ID;
	cout << "\n\t\t\t\t\t\tFirst Name: ";
	cin >> p.fname;
	cout << "\n\t\t\t\t\t\tLast Name: " ;
	cin >> p.lname;
	cout << "\n\t\t\t\t\t\tAge: " ;
	cin >> p.p_age;
	cout << "\n\t\t\t\t\t\tPhone No: " ;
	cin >> p.phnumber;
	cout << "\n\t\t\t\t\t\tOccupation: " ;
	cin >> p.occupation;
	cout << "\n\t\t\t\t\t\tCity: ";
	cin >> p.p_city;
	cout << "\n\t\t\t\t\t\tDisease/Symptoms: ";
	cin >> p.dis;
	cout << "\n\t\t\t\t\t\tAdmission date  (DD/MM/YYYY): " ;
	cin >> p.addDate;
	cout << "\n\t\t\t\t\t\tRelease date  (DD/MM/YYYY): " ;
	cin >> p.relDate;
	cout << "\n\t\t\t\t\t\tTotal Bill generated: " ;
	cin >> p.bill;
	cout << "\n\t\t\t\t\t\tKind of Specialization required: " << endl;
	string dept = p.getDept();
	clear_screen();
	fstream patObj;
	patObj.open("patient.txt", ios::app );
	patObj.seekp (0, ios::end);
	patObj << p.p_ID << endl << p.fname << endl << p.lname << endl << p.p_age << endl << p.phnumber << endl << p.occupation << endl << p.p_city << endl << p.dis << endl << p.addDate << endl << p.relDate << endl << p.bill << endl << dept << endl;
	patObj.close();


	cout << "\n\t\t\t\t\tNew Patient profile created successfully!" << endl << endl;

	cout << "\n\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\t\t\t\t\tEnter 1 to return to Patient Database\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();
	}

	else
		exit(0);
}

// Add Patient Ends Here
// ---------------------------------------------------------------------------------------------------------







// Edit Patient Detail
// ---------------------------------------------------------------------------------------------------------

void editPat(patient &pat)
{
	int x;
	cout << "\n\n\t\t\t\t\tEnter the ID of the Patient whose profile you want to Edit: " ;
	cin >> x;
	fstream patObj("patient.txt");
	patObj.seekg(0);
	string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
	int p_age, p_ID, count = 0;
	long double phnumber, bill;
	while (patObj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept)
	{
		if (p_ID == x) {
			cout << "\n\n\t\t\t\t\t1.ID: " << p_ID << endl << "\t\t\t\t\t2.First Name: " << fname << endl << "\t\t\t\t\t3.Last Name: " << lname << endl << "\t\t\t\t\t4.Age: " << p_age << endl << "\t\t\t\t\t5.Phone No.:" << phnumber << endl << "\t\t\t\t\t6.Occupation: " << occupation << endl << "\t\t\t\t\t7.City: " << p_city << endl << "\t\t\t\t\t8.Disease/Symptoms: " << dis << endl << "\t\t\t\t\t9.Admission date(DD/MM/YYYY): " << addDate << endl << "\t\t\t\t\t10.Release date(DD/MM/YYYY): " << relDate << endl << "\t\t\t\t\t11.Total Bill generated: " << bill << endl << "\t\t\t\t\t12.Kind of Specialization required: " << dept << endl << endl;
			count++;
			break;
		}
	}

	patObj.close();
	if (count == 0)
	{
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;
		cout << "\n\t\t\t\t\t" << "------------------------------------------------" << endl;

		cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
		cout << "\t\t\t\t\t\t";
		int c;
		cin >> c;
		if (c == 1) {
			clear_screen();
			getPatientDatabase();
		}
		else
			exit(0);
	}


	fstream file("patient.txt");
	file.seekg (0, ios::beg);
	file.seekg(0);
	int line;
	ofstream tempObj;
	tempObj.open("copy2.txt");
	tempObj.seekp(0);
	int skip = 0;
	string fname1, lname1, occupation1, p_city1, dis1, addDate1, relDate1, dept1;
	int p_age1;
	long double phnumber1, bill1;
	file.seekg(0); file.seekg(0, ios::cur);

	while (file >> line >> fname1 >> lname1 >> p_age1 >> phnumber1 >> occupation1 >> p_city1 >> dis1 >> addDate1 >> relDate1 >> bill1 >> dept1)
	{
		if (line != x) {
			tempObj << line << endl << fname1 << endl << lname1 << endl << p_age1 << endl << phnumber1 << endl << occupation1 << endl << p_city1 << endl << dis1 << endl << addDate1 << endl << relDate1 << endl << bill1 << endl << dept1 << endl;
		}
	}

	file.close();
	tempObj.close();
	remove("patient.txt");
	int result;
	char oldname[] = "copy2.txt";
	char newname[] = "patient.txt";
	result = rename( oldname , newname );
	//datatransfer ends
	int edit;
	cout << "\t\t\t\t\tEnter number corresponding to the Field you want to Edit: ";
	cin >> edit;
	switch (edit)
	{
	case 1: {
		cout << "\n\t\t\t\t\tID :" ;
		cin >> p_ID;
		break;
	}
	case 2: {
		cout << "\n\t\t\t\t\tFirst Name:" ;
		cin >> fname;

		break;
	}
	case 3: {
		cout << "\n\t\t\t\t\tLast Name:" ;
		cin >> lname;

		break;
	}
	case 4: {
		cout << "\n\t\t\t\t\tAge:" ;
		cin >> p_age;
		break;
	}
	case 5: {
		cout << "\n\t\t\t\t\tPhone No.:" ;
		cin >> phnumber;
		break;
	}
	case 6: {
		cout << "\n\t\t\t\t\tOccupation:";
		cin >> occupation;
		break;
	}
	case 7: {
		cout << "\n\t\t\t\t\tCity:" ;
		cin >> p_city;
		break;
	}

	case 8: {
		cout << "\n\t\t\t\t\tDisease/Symptoms:" ;
		cin >> dis;
		break;
	}
	case 9: {
		cout << "\n\t\t\t\t\tAdmission date  (DD/MM/YYYY):" ;
		cin >> addDate;
		break;
	}
	case 10:
	{
		cout << "\n\t\t\t\t\tRelease date  (DD/MM/YYYY):" ;
		cin >> relDate;
	}
	case 11: {
		cout << "\n\t\t\t\t\tTotal Bill generated:" ;
		cin >> bill;
		break;
	}
	case 12: {
		cout << "\n\t\t\t\t\tKind of Specialization required:" ;
		dept = pat.getDept();
		break;
	}
	default: {
		cout << "\n\t\t\t\t\t\tInvalid Input!" << endl;
		cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Doctor Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
		cout << "\t\t\t\t\t\t";
		int c;
		cin >> c;
		if (c == 1) {
			clear_screen();
			// getDoctorDatabase();
			getPatientDatabase();

		}

		else
			exit(0);
	}
	}



	clear_screen();
	cout << "\t\t\t\t--------------Updated Profile-----------------" << endl << endl;
	cout << "\n\n\t\t\t\t\t1.ID: " << p_ID << endl << "\t\t\t\t\t2.First Name: " << fname << endl << "\t\t\t\t\t3.Last Name: " << lname << endl << "\t\t\t\t\t4.Age: " << p_age << endl << "\t\t\t\t\t5.Phone No.: " << phnumber << endl << "\t\t\t\t\t6.Occupation: " << occupation << endl << "\t\t\t\t\t7.City: " << p_city << endl << "\t\t\t\t\t8.Disease/Symptoms: " << dis << endl << "\t\t\t\t\t9.Admission date(DD/MM/YYYY): " << addDate << endl << "\t\t\t\t\t10.Release date(DD/MM/YYYY): " << relDate << endl << "\t\t\t\t\t11.Total Bill generated: " << bill << endl << "\t\t\t\t\t12.Kind of Specialization required: " << dept << endl << endl;
	fstream newObj;
	newObj.open("patient.txt", ios::app);
	newObj.seekp (0, ios::end);
	newObj << p_ID << endl << fname << endl << lname << endl << p_age << endl << phnumber << endl << occupation << endl << p_city << endl << dis << endl << addDate << endl << relDate << endl << bill << endl << dept << endl;
	newObj.close();

	//after completion
	cout << "\n\t\t\t\t\t" << "------------------------------------------------" << endl;


	cout << "\n\n\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();

	}

	else
		exit(0);

}

// Edit Patient Detail Function Ends Here
// ---------------------------------------------------------------------------------------------------------







//the Display Particular Patient Function
// ---------------------------------------------------------------------------------------------------------

void displayPat()
{
	int x;
	cout << "\n\n\t\t\t\t\tEnter the ID of the Patient whose profile you want to Edit: " ;
	cin >> x;
	fstream patObj("patient.txt");
	patObj.seekg(0);
	string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
	int p_age, p_ID, count = 0;
	long double phnumber, bill;
	while (patObj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept)
	{
		if (p_ID == x) {
			cout << "\n\n\t\t\t\t\t1.ID: " << p_ID << endl << "\t\t\t\t\t2.First Name: " << fname << endl << "\t\t\t\t\t3.Last Name: " << lname << endl << "\t\t\t\t\t4.Age: " << p_age << endl << "\t\t\t\t\t5.Phone No.: " << phnumber << endl << "\t\t\t\t\t6.Occupation: " << occupation << endl << "\t\t\t\t\t7.City: " << p_city << endl << "\t\t\t\t\t8.Disease/Symptoms: " << dis << endl << "\t\t\t\t\t9.Admission date(DD/MM/YYYY): " << addDate << endl << "\t\t\t\t\t10.Release date(DD/MM/YYYY): " << relDate << endl << "\t\t\t\t\t11.Total Bill generated: " << bill << endl << "\t\t\t\t\t12.Kind of Specialization required: " << dept << endl << endl;

			count++;
			break;
		}
	}

	patObj.close();
	if (count == 0)
		cout << "\n\t\t\t\t\tNo matching records found!" << endl;

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();
	}

	else
		exit(0);
}
//the Display Particular Patient  Function Ends Here
// ---------------------------------------------------------------------------------------------------------




//Delete Patient function
// ---------------------------------------------------------------------------------------------------------


void deletePat()
{
	int x;
	cout << "\n\n\t\t\t\t\tEnter the ID of the Patient whose profile you want to Edit: " ;
	cin >> x;
	fstream patObj("patient.txt");
	patObj.seekg(0);
	string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
	int p_age, p_ID, count = 0;
	long double phnumber, bill;
	while (patObj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept)
	{
		if (p_ID == x) {
			cout << "\n\n\t\t\t\t\t1.ID:" << p_ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age" << p_age << endl << "\t\t\t\t\t5.Phone No.:" << phnumber << endl << "\t\t\t\t\t6.Occupation:" << occupation << endl << "\t\t\t\t\t7.City:" << p_city << endl << "\t\t\t\t\t8.Disease/Symptoms:" << dis << endl << "\t\t\t\t\t9.Admission date(DD/MM/YYYY):" << addDate << endl << "\t\t\t\t\t10.Release date(DD/MM/YYYY):" << relDate << endl << "\t\t\t\t\t11.Total Bill generated:" << bill << endl << "\t\t\t\t\t12.Kind of Specialization required:" << dept << endl << endl;
			count++;
			break;
		}
	}

	patObj.close();
	if (count == 0) {
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;
		cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
		cout << "\t\t\t\t\t\t";
		int c;
		cin >> c;
		if (c == 1) {
			clear_screen();
			getPatientDatabase();
		}

		else
			exit(0);
	}

	cout << "\t\t\t\t\tAre you sure you want to delete this profile?\n\t\t\t\t\t1.YES\n\t\t\t\t\t2.NO" << endl;
	cout << "\n\t\t\t\t\t";
	int n; cin >> n;
	if (n == 1)
	{
		fstream file("patient.txt");
		file.seekg (0, ios::beg);
		file.seekg(0);
		int line;
		ofstream tempObj;
		tempObj.open("copy2.txt");
		tempObj.seekp(0);
		int skip = 0;
		string fname1, lname1, occupation1, p_city1, dis1, addDate1, relDate1, dept1;
		int p_age1;
		long double phnumber1, bill1;
		file.seekg(0); file.seekg(0, ios::cur);


		while (file >> line >> fname1 >> lname1 >> p_age1 >> phnumber1 >> occupation1 >> p_city1 >> dis1 >> addDate1 >> relDate1 >> bill1 >> dept1)
		{
			if (line != x) {
				tempObj << line << endl << fname1 << endl << lname1 << endl << p_age1 << endl << phnumber1 << endl << occupation1 << endl << p_city1 << endl << dis1 << endl << addDate1 << endl << relDate1 << endl << bill1 << endl << dept1 << endl;
			}
		}

		file.close();
		tempObj.close();
		remove("patient.txt");
		int result;
		char oldname[] = "copy2.txt";
		char newname[] = "patient.txt";
		result = rename( oldname , newname );
		clear_screen();
		cout << "\n\t\t\t\t\tFile successfully deleted" << endl;

	}
	clear_screen();

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\t\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();

	}

	else
		exit(0);
}
// Delete Patient Function Ends Here
// ---------------------------------------------------------------------------------------------------------




//the Display Patient Database function
// ---------------------------------------------------------------------------------------------------------


void dispPatDatabase()
{
	fstream Obj("patient.txt");
	Obj.seekg(0);
	cout << "\t\t\t\t\t\tPATIENT DATABASE" << endl << endl;

	string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
	int p_age, p_ID, count = 0;
	long double phnumber, bill;
	while (Obj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept)
	{	count++;
		cout << "\n\t\t\t\t\t\tPatient Profile:" << count << endl;
		cout << "\n\t\t\t\t\t1.ID:" << p_ID << endl << "\t\t\t\t\t2.First Name:" << fname << endl << "\t\t\t\t\t3.Last Name:" << lname << endl << "\t\t\t\t\t4.Age" << p_age << endl << "\t\t\t\t\t5.Phone No.:" << phnumber << endl << "\t\t\t\t\t6.Occupation:" << occupation << endl << "\t\t\t\t\t7.City:" << p_city << endl << "\t\t\t\t\t8.Disease/Symptoms:" << dis << endl << "\t\t\t\t\t9.Admission date(DD/MM/YYYY):" << addDate << endl << "\t\t\t\t\t10.Release date(DD/MM/YYYY):" << relDate << endl << "\t\t\t\t\t11.Total Bill generated:" << bill << endl << "\t\t\t\t\t12.Kind of Specialization required:" << dept << endl << endl;


	}

	Obj.close();

	if (count == 0) {
		cout << "\n\t\t\t\t\t\tNo matching records found!" << endl;
	}

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();
	}

	else
		exit(0);

}

//the Display Patient Database Ends Here
// ---------------------------------------------------------------------------------------------------------


// ---------------------------------------------------------------------------------------------------------

//Number of Patient function
// ---------------------------------------------------------------------------------------------------------


void numberofPats()
{

	fstream Obj("patient.txt");
	Obj.seekg(0);
	string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
	int p_age, p_ID, count = 0;
	long double phnumber, bill;
	while (Obj >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept)
	{
		count++;
	}

	Obj.close();
	cout << "\n\n\t\t\t\t\tThe Total number of Patients in the hospital=" << count << endl << endl;

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\n\t\t\t\t\t\tEnter 1 to return to Patient Database\n\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\n\t\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getPatientDatabase();
	}

	else
		exit(0);

}
// Number Of Patient Functions Ends Here
// ---------------------------------------------------------------------------------------------------------



// Bed Class
// ---------------------------------------------------------------------------------------------------------

class bed {
public:
	int total = 1500;
	friend void getStatus();
};
// ---------------------------------------------------------------------------------------------------------


// Get Status of Bed Function
// ---------------------------------------------------------------------------------------------------------

void getStatus()
{	bed b;
	cout << "\n\t\t\t\t\t\tTotal Number of Beds in the hospital:" << b.total << endl;
	fstream file("patient.txt");
	file.seekg(0);
	string fname, lname, occupation, p_city, dis, addDate, relDate, dept;
	int p_age, p_ID, count = 0;
	long double phnumber, bill;
	while (file >> p_ID >> fname >> lname >> p_age >> phnumber >> occupation >> p_city >> dis >> addDate >> relDate >> bill >> dept)
	{
		count++;
	}

	file.close();
	cout << "\n\n\t\t\t\t\t\tThe number of Occupied Beds=" << count << endl;
	cout << "\n\t\t\t\t\t\tThe number of Empty Beds=" << b.total - count << endl;

	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\n\t\t\t\t\t\tEnter 1 to return to Bed Database\n\t\t\t\t\t\tEnter 2 to Exit." << endl;
	cout << "\t\t\t\t\t\t";
	int c;
	cin >> c;
	if (c == 1) {
		clear_screen();
		getBedDatabase();
	}

	else
		exit(0);

}
// ---------------------------------------------------------------------------------------------------------

//the main function



password A;

int main()
{
	A.getPassword();
	clear_screen();

	cout << "\t\t\t\t\tWELCOME TO MEDANTA HOSPITAL MANAGEMENT SYSTEM " << endl;
	cout << endl << endl;
	cout << "\t\t\t\t\t" << "------------------------------------------------" << endl;

	cout << "\t\t\t\t\t\t\t1.Main Menu" << endl;
	cout << "\t\t\t\t\t\t\t2.Exit" << endl;
	cout << "\t\t\t\t\t------------------------------------------------" << endl << endl;
	cout << "\t\t\t\t\t\tEnter your choice:";
	int choice1;
	cin >> choice1;

	if (choice1 == 1) {
		menu();
	}
	else if (choice1 == 2) {
		return 0;
	}
	else
		cout << "\nCome on!Enter a valid option." << endl;



}
void menu()
{
	clear_screen();
	int var = chooseMain();
	clear_screen();
	switch (var) {
	case 1: {
		A.passwordProtect();
		clear_screen();
		getDoctorDatabase();
		break;
	}

	case 2: {
		A.passwordProtect();
		clear_screen();
		getPatientDatabase();
		break;

	}

	case 3: {
		A.passwordProtect();
		clear_screen();
		getBedDatabase();
		break;
	}

	case 4:
	{
		exit(0);
		break;
	}
	default:
		cout << "\nCome on!Enter a valid option." << endl;
	}

}


//the chooseMain function


int chooseMain() {

	int choice2;
	cout << "\n\t\t\t\t\t\tMAIN MENU" << endl << endl << endl;
	cout << "\t\t-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t\t\t\t\t1.Enter Into Doctors' Database" << endl;
	cout <<  "\t\t\t\t\t2.Enter Into Patients' Database" << endl;
	cout <<  "\t\t\t\t\t3.Check for Hospital Bed Availability" << endl;
	cout << "\t\t\t\t\t4.Exit" << endl << endl;


	cout << "\t\t-------------------------------------------------------------------------" << endl;


	cout << "\n\t\t\tEnter the number corresponding to your choice: " ;
	cin >> choice2;
	return choice2;

}






void getDoctorDatabase()
{

	int choice_doc;
	cout << "\t\t\t\t\t\tWELCOME TO DOCTOR'S DATABASE" << endl << endl;
	cout << "\t\t-------------------------------------------------------------------------" << endl;

	cout << "\t\t\t\t\t1.Add New Doctor's Information" << endl;
	cout << "\t\t\t\t\t2.Edit a Doctor's Information" << endl;
	cout << "\t\t\t\t\t3.Display a Doctor's Information" << endl;
	cout << "\t\t\t\t\t4.Delete a Doctor's Information" << endl;
	cout << "\t\t\t\t\t5.Display Entire Doctor Database" << endl;
	cout << "\t\t\t\t\t6.Total Number of Doctors" << endl;
	cout << "\t\t\t\t\t7.Go back to Main Menu" << endl << endl;

	cout << "\t\t-------------------------------------------------------------------------" << endl;


	cout << "\n\t\t\tEnter the number corresponding to your choice:  ";
	cin >> choice_doc;
	clear_screen();
	switch (choice_doc) {
	case 1: {
		addDoc();
		break;
	}
	case 2: {
		doctor k;
		editDoc(k);
		break;
	}
	case 3: {
		displayDoc();
		break;
	}
	case 4: {
		deleteDoc();
		break;
	}
	case 5: {
		dispDatabase();
		break;
	}
	case 6: {

		numberofDocs();
		break;
	}

	case 7: {

		menu();
		break;
	}

	}
}



//the getPatientDatabase function

void	getPatientDatabase() {
	int choice_pat;
	cout << "\n\t\t\t\t\t\tWELCOME TO PATIENT'S DATABASE" << endl << endl;
	cout << "\t\t-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t\t\t\t\t1.Add New Patient's Information" << endl;
	cout << "\t\t\t\t\t2.Edit a Patient's Information" << endl;
	cout << "\t\t\t\t\t3.Display a Patient's Information" << endl;
	cout << "\t\t\t\t\t4.Delete a Patient's Information" << endl;
	cout << "\t\t\t\t\t5.Display Entire Patient Database" << endl;
	cout << "\t\t\t\t\t6.Total Number of Patients" << endl;
	cout << "\t\t\t\t\t7.Check for doctor availability" << endl;
	cout << "\t\t\t\t\t8.Go back to Main Menu" << endl << endl;

	cout << "\t\t-------------------------------------------------------------------------" << endl;


	cout << "\n\t\t\tEnter the number corresponding to your choice: ";
	cin >> choice_pat;
	clear_screen();
	switch (choice_pat) {
	case 1: {
		addPat();
		break;
	}
	case 2: {
		patient p;
		editPat(p);
		break;
	}
	case 3: {
		displayPat();
		break;
	}
	case 4: {
		deletePat();
		break;
	}
	case 5: {
		dispPatDatabase();
		break;
	}
	case 6: {
		numberofPats();
		break;
	}
	case 7: {
		getDoctor();
		break;
	}


	case 8: {
		menu();
		break;
	}

	}
}


//the getBedDatabase function
void getBedDatabase() {
	int choice_bed;
	cout << "\n\t\t\t\t\t\tWELCOME TO BED DATABASE" << endl << endl;
	cout << "\t\t-------------------------------------------------------------------------" << endl;
	cout << endl;
	cout << "\t\t\t\t\t\t1.Check Bed Status" << endl;
	cout << "\t\t\t\t\t\t2.Go back to Main Menu" << endl << endl;
	cout << "\t\t-------------------------------------------------------------------------" << endl;

	cout << "\n\t\t\tEnter the number corresponding to your choice:  ";
	cin >> choice_bed;
	clear_screen();
	switch (choice_bed)
	{
	case 1: {
		getStatus();
		break;
	}
	case 2: {
		menu();
		break;
	}
	}
}
void clear_screen()
{
// windows user;
// system("cls");


// linux user:
	system("clear");
}