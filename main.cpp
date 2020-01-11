#include <iostream>
#include <Eigen/Dense>
#include "Stack.h"

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




MatrixXd myproduct (MatrixXd &a,MatrixXd &b,MatrixXd &c,int m1,int m2){
    for (int index1_1 = 0;index1_1<m1;++index1_1){
        for (int index1_2 = 0;index1_2<b.rows();++index1_2){
            for (int index1_3 = 0;index1_3<m2;++index1_3){
                for(int index1_4 = 0;index1_4<b.rows();++index1_4){
                    int temp_index1 = index1_1 *b.rows()*m2+index1_2*m2+index1_3;
                    //temp_index2 = index;
                    a(temp_index1,1) = a(temp_index1,1)+b(index1_2,index1_4)*c(temp_index1,1);
                }
            }
        }
    }
}
int main(){
    MatrixXd A(27,1);
    MatrixXd B(3,3);
    MatrixXd C(27,1);
    MatrixXd D(9,1);
    int _size_m1 = 3;
    int _size_m2 = 3;
    D <<1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9;
    A <<D,
        D,
        D;
    B <<1,2,3,
        4,5,6,
        7,8,9;
    C <<A;
    //cout<<A.cols();
    cout<<A;
    MatrixXd E(27,1);
    E = myproduct(A,B,C,_size_m1,_size_m2);
    cout<<E;
    return 0;

}



