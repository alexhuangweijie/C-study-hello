#include <iostream>
#include <Eigen/Dense>
#include "Stack.h"
#include <ctime>

using namespace Eigen;
using namespace std;
/*int main() {
    MatrixXd m = MatrixXd::Random(3,3);
    m = (m + MatrixXd::Constant(3,3,1.2)) * 50;
    cout << "m =" << endl << m << endl;
    VectorXd v(3);
    v << 1, 2, 3;
    cout << "m * v =" << endl << m * v << endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}*/
/*
 int main(){
     for (int ix = 0; ix<10;++ix) {
         cout << ix << '\n';
     }
     cout<<"change"<<'\n';
     for (int iy = 0; iy<10;iy++) {
         cout << iy << '\n';
     }
     return 0;
 }*/

/*testing the Eigen template
int main (){
    Matrix<double, 3,3> A;
    A<<1,2,3,
       4,5,6,
       7,8,9;
    cout << A << '\n'<< endl;
    A<<A,A;
    cout<< A <<endl;
return 0;
};
*/
MatrixXd myproduct (MatrixXd b,MatrixXd c,int m1,int m2) {
    MatrixXd a(c.rows(),c.cols());
    int temp_index1 = 0;
    int temp_index2 = 0;
    for (int index1_1 = 1; index1_1 <= m1; ++index1_1) {
        for (int index1_2 = 1; index1_2 <= b.rows(); ++index1_2) {
            for (int index1_3 = 1; index1_3 <= m2; ++index1_3) {
                for (int index1_4 = 1; index1_4 <= b.rows(); ++index1_4) {
                    temp_index1 = (index1_1 - 1) * b.rows() * m2 + (index1_2 - 1) * m2 + index1_3 - 1;
                    temp_index2 = (index1_1 - 1) * b.rows() * m2 + (index1_4 - 1) * m2 + index1_3 - 1;
                    //cout<<temp_index1<<endl;
                    //cout<<temp_index2<<endl;
                    a(temp_index1, 0) = a(temp_index1, 0) + b(index1_2 - 1, index1_4 - 1) * c(temp_index2, 0);
                    //cout<<index1_4-1;
                }
            }
        }
    }
    return a;
}
int main(){
    //MatrixXd A(27,1);
    MatrixXd B = MatrixXd::Random(10,10);
    MatrixXd C = MatrixXd::Random(400,1);
    //MatrixXd D(9,1);
    int _size_m1 = 4;
    int _size_m2 = 10;
    /*cout<<C(1,0);
    int temp = 1;
    C(1,0)=temp;
    cout<<temp;
    cout<<C(temp,0);*/
    MatrixXd E;
    clock_t t1 = clock();
    for (int i = 0; i<=100000;++i){
        E = myproduct(B,C,_size_m1,_size_m2);
    }
    clock_t t2 = clock();
    //cout<<E<<endl;
    cout<<(double)(t2-t1)/CLOCKS_PER_SEC<<endl;
    return 0;
}