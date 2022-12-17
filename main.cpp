#include <iostream>
#include <string>
#include <fstream>
#include "shape.h"
#include "parallelogram.h"
#include "base-types.h"
#include "rectangle.h"


using namespace std;

Shape* sortshapes(Shape** shapearray, int len);

void shapesfromfile();
string delSymbol(string str, char symbol);

int main() {

	cout << "Creating rectangle:" << endl << endl;

	point_t r1, r2;
	r1.x = 1;
	r1.y = 1;
	r2.x = 5;
	r2.y = 5;

	Rectangle rec1(r2, r1);

	cout << "rec1 area: "<<rec1.getArea() << endl;
	rec1.move_c(2, 2);
	cout<<"rec1 area after moving 1:" << rec1.getArea() << endl;
	rec1.move_o(-3, -3);
	cout << "rec1 area after moving 2:" << rec1.getArea() << endl;
	rec1.scale(2);
	cout << "rec1 area after scaling x2:" << rec1.getArea() << endl;
	rec1.scale(0.5);
	cout << "rec1 area after scaling x0.5:" << rec1.getArea() << endl;


	cout <<endl<<endl<< "Creating parallelogram:" << endl << endl;

	point_t t1, t2, t3;
	t1.x = 1;
	t1.y = 5;
	t2.x = 6;
	t2.y = 5;
	t3.x = 4;
	t3.y = 1;

	Parallelogram par1(t1, t2, t3);

	cout << "par1 area: " << par1.getArea() << endl;
	par1.move_c(2, 2);
	cout << "par1 area after moving 1:" << par1.getArea() << endl;
	par1.move_o(-3, -3);
	cout << "par1 area after moving 2:" << par1.getArea() << endl;
	par1.scale(2);
	cout << "par1 area after scaling x2:" << par1.getArea() << endl;
	par1.scale(0.5);
	cout << "par1 area after scaling x0.5:" << par1.getArea() << endl;

	cout << endl << endl << "Creating parallelogram with another points:" << endl << endl;

	t3.x = 1;
	t3.y = 5;
	t1.x = 6;
	t1.y = 5;
	t2.x = 4;
	t2.y = 1;

	Parallelogram par2(t1, t2, t3);

	cout << "par2 area: " << par2.getArea() << endl;
	par2.move_c(2, 2);
	cout << "par2 area after moving 1:" << par2.getArea() << endl;
	par2.move_o(-3, -3);
	cout << "par2 area after moving 2:" << par2.getArea() << endl;
	par2.scale(2);
	cout << "par2 area after scaling x2:" << par2.getArea() << endl;
	par2.scale(0.5);
	cout << "par2 area after scaling x0.5:" << par2.getArea() << endl;

	cout << (par2 < rec1) << endl;

	Shape* par2c = par2.clone();
	Shape* rec1c = rec1.clone();
	cout << "par2 clone area: " << par2c->getArea() << endl;
	cout << "rec1 clone area: " << rec1c->getArea() << endl;

	cout << par2c << endl;

	Shape* par3 = par2c->clone();
	par3->scale(1.5);
	Shape* rec2 = rec1.clone();
	rec2->scale(3);

	cout << endl << endl << "Sorting shapes" << endl << endl;

	Shape* array[4]{ &rec1, &par2, par3, rec2 };

	*array = sortshapes(array, 4);

	for (int i = 0; i < 4; i++) {

		cout << array[i] << endl;

	}

	cout << endl << endl << "Taking shapes from file" << endl << endl;

	shapesfromfile();

	system("pause");
	return 0;

}

Shape* sortshapes(Shape** shapearray, int len) {

	Shape* temp;
	for (int i = 0; i < len-1; i++) {
		for (int j = 0; j < len-i-1; j++) {

			if (( shapearray[j] < shapearray[j+1])) {

				temp = shapearray[j];
				shapearray[j] = shapearray[j + 1];
				shapearray[j + 1] = temp;

			}

		}
	}

	return *shapearray;

}

void shapesfromfile() {

	string ipath;
	while (true) {

		cout << "Enter path to the file:" << endl;
		cin >> ipath;
		cout << endl;

		int n = ipath.length();
		for (int i = 0; i < n; i++) {

			if (ipath[i] == '\\') {
				ipath[i] = '/';
			}

		}
		ipath = delSymbol(ipath, '\"');
		ipath = delSymbol(ipath, ' ');


		int n1 = ipath.length();
		if (ipath.substr(n1 - 4, 4) != ".txt") {
			cout << "File must be .txt" << endl;
		}
		else {
			break;
		}
	}
		ifstream inpath(ipath);
		if (inpath.is_open()) {

			string frow;
			int rcount(0);
			while (getline(inpath, frow)) {
				if (!frow.empty())rcount++;
				
			}
			
			if (rcount>0) {
				inpath.close();
				ifstream inpath1(ipath);
				while (getline(inpath1, frow)) {
					if (!frow.empty()) {

						string delimiter = " ";
						string token;
						size_t pos = 0;
						string frow1 = frow;
						//Shape** shapefile = new Shape* [rcount - 1];
						int elemsc(0);
						while ((pos = frow1.find(delimiter)) != frow.npos) {
							token = frow1.substr(0, pos);
							frow1.erase(0, pos + delimiter.length());
							elemsc++;

						}
						
						string* curr = new string[elemsc];

						int u(0);
						while ((pos = frow.find(delimiter)) != frow.npos) {

							token = frow.substr(0, pos);
							curr[u] = token;
							frow.erase(0, pos + delimiter.length());
							u++;

						}
						if (curr[0] == "RECTANGLE") {
							double x1 = stod(curr[1]);
							double y1 = stod(curr[2]);
							double x2 = stod(curr[3]);
							double y2 = stod(curr[4]);
							point_t p1, p2;
							p1.x = x1;
							p1.y = y1;
							p2.x = x2;
							p2.y = y2;
							Rectangle r1(p1, p2);
							Shape* r1c = r1.clone();
							cout << r1c << endl;
						}
						else if (curr[0] == "PARALLELOGRAM") {

							double x1 = stod(curr[1]);
							double y1 = stod(curr[2]);
							double x2 = stod(curr[3]);
							double y2 = stod(curr[4]);
							double x3 = stod(curr[5]);
							double y3 = stod(curr[6]);
							point_t p1, p2, p3;
							p1.x = x1;
							p1.y = y1;
							p2.x = x2;
							p2.y = y2;
							p3.x = x3;
							p3.y = y3;
							Parallelogram para1(p1, p2, p3);
							Shape* par1cl = para1.clone();
							cout << par1cl << endl;
						}
						else {
							cout << "Wrong figure" << endl;
						}
					}
				}

			}

		}
		else {
			cout << "cant open a file";
		}
		

}

string delSymbol(string str, char symbol) {

	int length = str.length();
	string newstr;

	for (int k = 0; k < length; k++) {

		if (str[k] != symbol) {
			newstr.append(1, str[k]);
		}

	}

	return newstr;
}