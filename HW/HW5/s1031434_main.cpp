#include<vector>
#include<string>
#include<fstream>
#include<iostream>
#include<cstdlib>
#include"s1031434_shape.h"
#include"s1031434_main.h"
using namespace std;

vector<MIME::shape*> data;

int loadshape(string file){
	ifstream readfile(file, ios::in);
	if (!readfile){
		readfile.close();
		cout << "*Note: File can't be open !" << endl;
		exit(1);
	}
	int num = 0;//to count the number of shape
	for (int n = 0; !readfile.eof();){
		readfile >> n;
		float myX, myY;
		switch ((ShapeType)n){
		case Shape:
			cout << "[LOADER] invalde abstract type: Shape" << endl;
			return num;
		case Triangle:
			cout << "[LOADER] add : Triangle" << endl;
			data.push_back(new MIME::Triangle());
			num++;
			break;
		case Quadrilateral:break;
		case Pentagon:break;
		case Parallelogram:break;
		case Square:break;
		case Trapezium:break;
		case Isosceles_triangle:break;
		case Regular_triangle:break;
		case Right_triangle:break;
		case Polygon:break;
		}//end switch

	}//end for-loop

	return num;
}


int main()
{
	int NUMofSHAPE = loadshape("test_shape.txt");
	cout << "# of shapes = " << NUMofSHAPE << endl;

	for each (MIME::shape* ptr in data){
		ptr->print();
		cout << "AREA: " << ptr->area() << endl;
		cout << "Valid ? : " << (ptr->Valid() ? "YES" : "NO") << endl;
		//cout << "Convex ? : " << (ptr->Convex() ? "YES" : "NO") << endl << endl;
	}
	for each (MIME::shape* ptr in data)
		delete ptr;

	system("PAUSE");
	return 0;
}