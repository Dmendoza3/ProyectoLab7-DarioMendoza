//#include "Consola.h"
//#include "Microsoft.h"

#include <ctime>
#include <vector>
#include <typeinfo>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class te{
	public:
		te(double dd, int mm)
		{
			d = dd;
			m = mm;
		}
		double d;
		int m;
		virtual ~te(){}
};

class tt : public te{
	public:
		tt(double dd, int mm, double tt, int ss) : te(dd,mm)
		{
			t = tt;
			s = ss;
		}
	double t;
	int s;
	//virtual ~tt(){}
};

void addOne(int* a, int size)
{
	for(int i = 0; i < size; i++)
	{
		a[i]++;
	}
}

int main()
{	  
//	ofstream o(".\\log_ventas\\sdsd.log");
	string wew = "d";
	string c = "./log_venta/" + wew + "addd.log";
	ofstream o(c.c_str());

	o << "sdads";
	
	o.close();
	/*time_t horaVenta = time(0) ;
    tm *ltm = localtime(&horaVenta);
    string dt =  to_string(ltm->tm_mday) + "/" + to_string(1 + ltm->tm_mon) + "/" + to_string(1900 + ltm->tm_year);

    cout << dt;*/
	
	/*int d[] = {0,0,0,0,0,0};

	addOne(d, 6);

	cout << typeid(d).name() << endl;

	for(int i = 0; i < 6; i++)
	{
		cout << d[i] << endl;
	}*/
	
	/*vector<te*> vv;
	vv.push_back(new te(0.5, 4));
	vv.push_back(new tt(1.5, 2, 0.5, 2));
	vv.push_back(new te(2.5, 3));*/

	/*cout << typeid(*(vv[0])).name();
	cout << typeid(*(vv[1])).name();
	cout << typeid(*(vv[2])).name();*/

	/*for(te* nint : vv)
	{
		cout << typeid((*nint)).name() << endl;
		(*nint).d += 0.7;
	}

	for(int i = 0; i < vv.size(); i++)
	{
		cout << vv[i]->d << endl;
	}

	delete vv[0];
	delete vv[1];
	delete vv[2];*/
	
	return 0;
}
