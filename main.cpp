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




MatrixXd myproduct (MatrixXd a,MatrixXd b,MatrixXd c,int m1,int m2){
    for (int index1_1 = 1;index1_1<=m1;++index1_1){
        for (int index1_2 = 1;index1_2<=b.rows();++index1_2){
            for (int index1_3 = 1;index1_3<=m2;++index1_3){
                for(int index1_4 = 1;index1_4<=b.rows();++index1_4){
                    int temp_index1 = (index1_1-1) *b.rows()*m2+(index1_2-1)*m2+index1_3-1;
                    int temp_index2 =(index1_1-1)*b.rows()*m2 + (index1_4-1)*m2 + index1_3-1;
                    //cout<<temp_index2<<endl;
                    //cout<<temp_index2<<endl;
                    a(temp_index1,0) = a(temp_index1,0)+b(index1_2-1,index1_4-1)*c(temp_index2,0);
                    //cout<<c(temp_index2,0);
                }
            }
        }
    }
return a;
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
    /*cout<<C(1,0);
    int temp = 1;
    C(1,0)=temp;
    cout<<temp;
    cout<<C(temp,0);*/
    MatrixXd E = myproduct(A,B,C,_size_m1,_size_m2);
    cout<<E;
    return 0;
}



