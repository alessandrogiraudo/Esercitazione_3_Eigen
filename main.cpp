#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen; 


int main()
{
	Matrix2d A1, A2, A3;
	Vector2d b1, b2, b3;
	
	A1 << 5.547001962252291e-01, -3.770900990025203e-02,
          8.320502943378437e-01, -9.992887623566787e-01;

    b1 << -5.169911863249772e-01,
           1.672384680188350e-01;
		   
	A2 << 5.547001962252291e-01,-5.540607316466765e-01, 
			8.320502943378437e-01,-8.324762492991313e-01;
	
	b2 << -6.394645785530173e-04,
			4.259549612877223e-04;
	
	A3 << 5.547001962252291e-01,-5.547001955851905e-01, 
			8.320502943378437e-01,-8.320502947645361e-01;
	
	b3 << -6.400391328043042e-10, 
			4.266924591433963e-10;
	
	Vector2d x1 = A1.colPivHouseholderQr().solve(b1);
	Vector2d x2 = A2.colPivHouseholderQr().solve(b2);
	Vector2d x3 = A3.colPivHouseholderQr().solve(b3);
	
	Vector2d y1 = A1.fullPivLu().solve(b1);
	Vector2d y2 = A2.fullPivLu().solve(b2);
	Vector2d y3 = A3.fullPivLu().solve(b3);
	
	cout.precision(16)
	cout << "The solution of A1 using the QR decomposition is:\n"
     << x1 << endl;
	cout << "The solution of A2 using the QR decomposition is:\n"
     << x2 << endl;
	cout << "The solution of A3 using the QR decomposition is:\n"
     << x3 << endl;
	 
	/*PALU*/
	cout << "Here is, up to permutations, its LU decomposition matrix:"
     << endl << y1 << endl;
	cout << "Here is, up to permutations, its LU decomposition matrix:"
    << endl << y2 << endl;
	cout << "Here is, up to permutations, its LU decomposition matrix:"
    << endl << y3 << endl;
	
    return 0;
}
