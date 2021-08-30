/* MP1 
** Author: Rojas, 2021
*/

#include <cstdio>
#include <string>
#include<iostream>

#include<iomanip>
#include<math.h>
#include<stdlib.h>

using namespace std;

#include "exprtk.hpp"

template <typename T>
float Fparser(std::string expression_string, float value)
{
   typedef exprtk::symbol_table<T> symbol_table_t;
   typedef exprtk::expression<T>   expression_t;
   typedef exprtk::parser<T>       parser_t;
   T x= T(value);

   symbol_table_t symbol_table;
   symbol_table.add_variable("x",x);
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);    //expression --mathematical expression

   T result = expression.value();
   return result;   //number
}
void FixedPoint(int precision) {
	int step=1, N;
    std::string fx, gx;
    float x0, x1,e;

	cout<< setprecision(precision)<< fixed;

    cout<<"Enter f(x): ";
    cin>>fx;
    cout<<"Enter g(x): ";
    cin>>gx;
    cout<<"Enter initial value x(0): ";
    cin>>x0;
	cout<<"Enter tolerable error: ";
	cin>>e;
    cout<<"Enter iterations: ";
    cin>>N;
	cout<< endl<<"**************************"<< endl;
	cout<<"Fixed Point Iteration Method"<< endl;
	cout<<"**************************"<< endl;
    do {
		  x1 = Fparser<double>(gx, x0);
		  cout<<"Iteration-"<< step<<":\t x1 = "<< setw(10)<< x1<<" and f(x1) = "<< setw(10)<< Fparser<double>(fx, x1)<< endl;
		  step = step + 1;

		  if(step>N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }

		  x0 = x1;
	 }while( fabs(Fparser<double>(fx, x1)) > e);

	cout<< endl<<"Root is "<< x1<< endl;
	cout<<"**************************"<< endl;
}

float GSparser(std::string expression_string, float x_value, float y_value, float z_value)
{
   typedef float T; 
   typedef exprtk::symbol_table<T> symbol_table_t;
   typedef exprtk::expression<T>   expression_t;
   typedef exprtk::parser<T>       parser_t;
   T x= T(x_value);
   T y= T(y_value);
   T z= T(z_value);

   symbol_table_t symbol_table;
   symbol_table.add_variable("x",x_value);
   symbol_table.add_variable("y",y_value);
   symbol_table.add_variable("z",z_value);
   symbol_table.add_constants();

   expression_t expression;
   expression.register_symbol_table(symbol_table);

   parser_t parser;
   parser.compile(expression_string,expression);

   T result = expression.value();
   return result;
}
void GaussSeidel(int precision) {
    std::string f1, f2, f3;
    float x0=0, y0=0, z0=0, x1, y1, z1, e1, e2, e3, e;
    int step=1;
    cout<< setprecision(precision)<< fixed;

    cout<<"Enter f1: ";
    cin>>f1;
    cout<<"Enter f2: ";
    cin>>f2;
    cout<<"Enter f3: ";
    cin>>f3;
    cout<<"Enter tolerable error: ";
    cin>>e;

	cout<< endl<<"**************************"<< endl;
	cout<<"Gauss-Seidel Method"<< endl;
	cout<<"**************************"<< endl;

    cout<< endl<<"Count\tx\t\ty\t\tz"<< endl;
    do {
    x1 = GSparser(f1,x0,y0,z0);
    y1 = GSparser(f2,x1,y0,z0);
    z1 = GSparser(f3,x1,y1,z0);

    cout<< step<<"\t"<< x1<<"\t"<< y1<<"\t"<< z1<< endl;
    e1 = fabs(x0-x1);
    e2 = fabs(y0-y1);
    e3 = fabs(z0-z1);

    step++;
    x0 = x1;
    y0 = y1;
    z0 = z1;
    }while(e1>e && e2>e && e3>e);
    cout<< endl<<"Solution: x = "<< x1<<", y = "<< y1<<" and z = "<< z1<< endl;
	cout<<"**************************"<< endl;
}

void Lagrange(int precision) {
	float x[100], y[100], xp, yp=0, p;
	int i,j,n;

	cout<<"Enter number of data: ";
	cin>>n;
	cout<<"Enter data:"<< endl;
	for(i=1;i<=n;i++)
	{
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i];
	}
	cout<<"Enter interpolation point: ";
	cin>>xp;
	cout<< endl<<"**************************"<< endl;
	cout<<"Lagrange Method"<< endl;
	cout<<"**************************"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	cout<< endl<<"Interpolated value at "<< xp<< " is "<< yp<< endl;
	cout<<"**************************"<< endl;
}

vector<int> Validation() {
    vector<int> methods= {0, 0, 0};
    string f_ans, gx_ans; 
    int f_num_ans;

    cout<<"Do you want to enter a function? Press y/n: ";
    cin>>f_ans;
    if (f_ans=="y" || f_ans=="Y") {
        cout<<"How many functions do you have? ";
        cin>>f_num_ans;
        if (f_num_ans<0) {
            cout<<"Incorrect value.";
        } else {
            if (f_num_ans==0) {
                cout<<"You need to enter # of equations for these methods.";
            } else {
                if (f_num_ans!=1) {
                    cout<<"Is the other equation a derived value of x? ";
                    cin>>gx_ans;
                    if (gx_ans=="y" || gx_ans=="Y") {
                        methods = {1, 0, 0}; //Fixed Point
                    } else {
                        methods = {0, 1, 0};  //Gauss-Seidel
                    }
                } else {
                    //DO NOTHING --
                    cout<<"Invalid.";
                }
            }
        }
    } else {
        methods = {0, 0, 1}; //Lagrange
    }
    return methods;
}

int main()
{
    bool a=true;
    std::string ans;
    int mode;
    int precision;
    vector<int> methods= {0, 0, 0};

    cout<<"Enter precision: ";
    cin>>precision;
    while(a) {
        methods = Validation();
        for (int i=0; i <= methods.size(); i++) {
            if (methods[i]==1) {
                int count = i;
                switch (count) {
                case 0: FixedPoint(precision); break;
                case 1: GaussSeidel(precision); break;
                case 2: Lagrange(precision); break;
                default: break;
                }
            }
        }

        cout<<"Try again? Press y/n: ";
        cin>>ans;
        if (ans=="y") {
            a=true;
        } else {
            a=false;
        }
    }
}
