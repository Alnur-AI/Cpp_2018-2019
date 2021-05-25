#include <iostream>
#include <cstdlib>

class matrix {
public:
    int length;
    int width;
    double **member;

    matrix(int x,int y){
        length = x;
        width = y;

        member = new double* [x];
        for ( int i = 0; i < x; i++)
            member[i] = new double [y];

        for ( int i = 0; i < x; i++)
            for ( int j = 0; j < y; j++)
                member[i][j] = rand()%2;
    }
    matrix(){
        std::cout << "Enter length" << '\n';
        std::cin >> length;

        std::cout << "Enter width" << '\n';
        std::cin >> width;

        member = new double* [length];
        for ( int i = 0; i < length; i++)
            member[i] = new double [width];

        for ( int i = 0; i < length; i++)
            for ( int j = 0; j < length; j++)
                std::cin >> member[i][j];
    }
    matrix(const matrix& other){
        length = other.length;
        width = other.width;
        member = new double* [other.length];
        for ( int i = 0; i < other.length; i++)
            member[i] = new double [other.width];
        for ( int i = 0; i < length; i++)
            for ( int j = 0; j < length; j++)
                member[i][j] = other.member[i][j];
    }
    matrix(int a, int b, int c){
        length = a;
        width = b;
        member = new double* [a];
        for ( int i = 0; i < a; i++)
            member[i] = new double [b];
    }
    ~matrix(){
        for ( int i = 0; i < length; i++)
            delete [] member[i];
    }
        matrix operator +(const matrix& other){
            matrix new_matrix(other);
            for ( int i = 0; i < length; i++)
                for ( int k = 0; k < width; k++)
                    new_matrix.member[i][k]= member[i][k] + other.member[i][k];
            return new_matrix;
        }
        matrix operator -(const matrix& other){
            matrix new_matrix(other);
            if (width = other.width && length == other.length)
                for ( int i = 0; i < length; i++)
                    for ( int k = 0; k < width; k++)
                        new_matrix.member[i][k]= member[i][k] - other.member[i][k];
            else
                std::cout << "You cant do it" << '\n';
            return new_matrix;
        }
        matrix operator *(int num){
            matrix C(*this);
            for ( int i = 0; i < length; i++)
                for ( int k = 0; k < width; k++)
                    C.member[i][k] = member[i][k] * num;
            return C;
        }
        matrix operator *(const matrix& other){
            if (this->width != other.length){
                std::cout << "error" << std::endl;
                exit(1);
            }
            else
            {
                matrix new_matrix(length, other.width, 1);
                int sum;
                for(int i = 0; i < length; i++){
                    for(int j = 0; j < width; j++){
                        sum = 0;
                        for(int s = 0; s < width; s++)
                            sum += this->member[i][s] * other.member[s][j];
                        new_matrix.member[i][j] = sum;
                    }
                }
                return new_matrix;
            }


        }
        void operator = (const matrix& other){
            for ( int i = 0; i < other.length; i++)
                for ( int j = 0; j < other.width; j++)
                    member[i][j] = other.member[i][j];
            return;
        }
        friend void output_matrix(matrix&);
};
void output_matrix(matrix& obj){
    for ( int i = 0; i < (int)obj.length; i++){
        for ( int j = 0; j < (int)obj.width; j++)
            std::cout << obj.member[i][j] << " ";
        std::cout << '\n';
    }
    std::cout << '\n';
    return;
}


int main(){
      matrix A(2,5);
      matrix B(5,2);
      matrix C = A*B;

      output_matrix(A);
      output_matrix(B);
      output_matrix(C);
      return 0;
}

/*
matrix new_matrix(other);
            if(width == other.length)
            {

                new_matrix.member = new double* [length];
                for ( int i = 0; i < length; i++)
                    new_matrix.member[i] = new double [other.width];
                int sum;
                for(int i = 0; i < length; i++){
                    for(int j = 0; j < width; j++){
                        sum = 0;
                        for(int s = 0; s < width; s++)
                            sum += this->member[i][s] * other.member[s][j];
                        new_matrix.member[i][j] = sum;
                    }
                }
                return new_matrix;
            }
            else
            {
                std::cout << "error" << std::endl;
                exit(1);
            }
            return new_matrix;
*/
