#include <iostream>
#include <cstdlib>
#include <stdexcept>
#include <exception>

#include "Errors.h"
#include "MyVector.cpp"

int main()
{
    try
    {
        std::cout << "Test constructors\n\n";

       MyVector<int>* v1 = new MyVector<int>();
        std::cout << "Default:\n";
        std::cout << v1 << "\n";

        std::cout << "With parameters: \n";
        MyVector<double> v2(2, 3., 4.);
        MyVector<double> v3(3, 3.0, 4.0, 0.0);
        std::cout << v2 << "\n" << v3 << "\n";

        std::cout << "From array: \n";
        double arr[5] = { 5, 1, 7, 4, 0 };
        MyVector<double> v4(5, arr);
        std::cout << v4 << "\n";

        std::cout << "From existing MyVector:\n";
        MyVector<double> v5(v3);
        std::cout << v5 << "\n";


        std::cout << "\nTest methods\n\n";

        std::cout << "Length of MyVector (3, 4, 0): " << v3.len() << "\n";
        std::cout << "Size of MyVector (3, 4, 0): " << v3.size() << "\n";
        std::cout << "Get second element {5, 1, 7, 4, 0}: " << v4.getElemMyVector(1) << "\n";

        std::cout << "Multiply by 10: " << (v4 *= 10) << "\n";
        std::cout << "Divide by 10: " << (v4 /= 10) << "\n";
        std::cout << "Subtract two MyVectors {5, 1, 7, 4, 0} minus {3, 4, 0}: " << (v4 -= v3) << "\n";
        std::cout << "Change to opposite direction (unary minus) {3, 4, 0}: " << (-v3) << "\n\n";

        MyVector<double> v12{ 1., 2., 3., 4., 5. };
        std::cout << "Init MyVector {1., 2., 3., 4., 5.}: " << v12 << "\n";
        v12[2] = 10.;
        std::cout << "Change third element using []: " << v12 << "\n";
        v12.setElemMyVector(3, 11.);
        std::cout << "Change fourth element using set_elem_MyVector method: " << v12 << "\n";
        v12 = v12.getSingleMyVector();
        std::cout << "Get MyVector with lenght of one: " << v12 << "\n\n";

        MyVector<double> v6(3, 3.0, 4.0, 0.0);
        std::cout << "MyVector multiplication {3,4,0} and {3,4,0}: " << (v3 &= v6) << "\n";
        MyVector<int> v7(2, 10, 0);
        MyVector<int> v8(2, 0, 10);
        std::cout << "Find angle between {10, 0} and {0, 10}: " << v7.angleBetweenMyVectors(v8) << "\n";
        MyVector<double> v9(2, 5., 5.);
        MyVector<double> v10(2, 10., 0.0);
        std::cout << "Find angle between {5, 5} and {10, 0}: " << v9.angleBetweenMyVectors(v10) << "\n";
        MyVector<double> v20(2, 20., 20.0);
        std::cout << "Check collinearity of {5, 5} and {20, 20}: " << v9.isCollinearity(v20) << "\n";
        std::cout << "Scalar multiplication {5, 5} and {10, 0}: " << v9 * v10 << "\n\n";

        MyVector<int> v11(4, 1, 0, 0, 0);
        std::cout << "Is MyVector of length one {4, 1, 0, 0, 0}? " << v11.isSingle() << "\n";
        std::cout << "Are two MyVectors equal? {3, 4, 0} and {3, 4, 0}: " << (v3 == v6) << "\n";
        std::cout << "Are two MyVectors not equal? {3, 4, 0} and {3, 4, 0}: " << (v3 != v6) << "\n";
    }
    catch (ExceptionVector & err)
    {
        std::cout << err.what() << std::endl;
    }
    return 0;
}