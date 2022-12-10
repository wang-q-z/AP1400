#include "hw1.h"

namespace algebra{

Matrix zeros(size_t n, size_t m)
{
    Matrix mat(n);

    for(size_t i = 0; i < n; i++){
        vector<double> vec(m);
        for(size_t j = 0; j < m; j++){
            vec[j] = 0.0;
        }
        mat[i] = vec;
    };
    return mat;
}

Matrix ones(size_t n, size_t m)
{
    Matrix mat(n);

    for(size_t i = 0; i < n; i++){
        vector<double> vec(m);
        for(size_t j = 0; j < m; j++){
            vec[j] = 1.0;
        }
        mat[i] = vec;
    };
    return mat;
}

Matrix random(size_t n, size_t m, double min, double max)
{
    if( min >= max)
        throw std::logic_error("Min is greater than Max!");

    Matrix mat(n);

    std::random_device rd;
    std::mt19937 rng(rd());
    std::uniform_real_distribution<double> dist(min, max);

    for(size_t i = 0; i < n; i++){
        vector<double> vec(m);
        for(size_t j = 0; j < m; j++){
            
            vec[j] = dist(rng);
        }
        mat[i] = vec;
    };
    return mat;
}

void show(const Matrix& matrix)
{
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();


    for(size_t i = 0; i < rows; i++){
        for(size_t j = 0; j < cols; j++){
            cout<<fixed << setprecision(3) <<matrix[i][j]<<" ";
        };
        cout<<"\n";
    }

}

Matrix multiply(const Matrix& matrix, double c)
{
    size_t rows = matrix.size();
    size_t cols = matrix[0].size();
    Matrix result(rows);

    if(rows == 0 | cols == 0)
        cout << "it is a empty matrix" << endl;
    else{
        for(size_t i = 0; i < rows; i++){
            vector<double> re(cols);
            for(size_t j = 0; j < cols; j++){
                re[j] = matrix[i][j] * c;
            };
        result[i] = re;
        }
    }
    return result;
}

Matrix multiply(const Matrix& matrix1, const Matrix& matrix2)
{
    size_t row1 = matrix1.size();
    size_t row2 = matrix2.size();
  
    
    if(row1 == 0 || row2 == 0)
    {
        return Matrix {};
    }
   
    size_t col2 = matrix2[0].size(); 
    size_t col1 = matrix1[0].size();

    if(row2 != col1)
    {
        throw std::logic_error("Could not multiply");
    }

    Matrix result(row1);
    result = algebra::zeros(row1,col2);
    
    for(size_t i = 0; i < row1; i++){
        for(size_t j = 0; j < col2; j++){
            double val = 0.0;
            for(size_t k = 0; k < col1; k++){
                
                val += matrix1[i][k] * matrix2[k][j];
            };
            result[i][j] = val;
        }
    }

    return result;
}

Matrix sum(const Matrix& matrix, double c)
{
    size_t rows = matrix.size();
    if(rows == 0){
        return Matrix {};
    }
    size_t cols = matrix[0].size();
    Matrix result(rows);

    for(size_t i = 0; i < rows; i++){
        vector<double> re(cols);
        for(size_t j = 0; j < cols; j++){
            re[j] = matrix[i][j] + c;
        };
    result[i] = re;
    }
    return result;  
}

Matrix sum(const Matrix& matrix1, const Matrix& matrix2)
{
    size_t row1 = matrix1.size();
    size_t row2 = matrix2.size();
  
    
    if(row1 == 0 && row2 == 0)
    {
        return Matrix {};
    }
    
    if(row1 == 0 || row2 == 0){
        throw std::logic_error("Could not add");
    }
   
    size_t col2 = matrix2[0].size(); 
    size_t col1 = matrix1[0].size();

    if(row2 != row1 || col1 != col2)
    {
        throw std::logic_error("Could not add");
    }

    Matrix result(row1);
    result = algebra::zeros(row1,col1);
    
    for(size_t i = 0; i < row1; i++){
        for(size_t j = 0; j < col1; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;  
}

Matrix transpose(const Matrix& matrix)
{
    size_t rows =  matrix.size();
    if(rows == 0)
    {
        return Matrix {};
    }
    size_t cols = matrix[0].size();
    Matrix result(cols);
    result = algebra::zeros(cols,rows);

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[j][i] = matrix[i][j];
        }
    }
    return result;
}
Matrix minor(const Matrix& matrix, size_t n, size_t m)
{
    size_t rows = matrix.size();
    if(rows == 0){
        return Matrix {};
    }
    size_t cols = matrix[0].size();

    Matrix result(rows - 1);
    result = algebra::zeros(rows - 1, cols - 1);
    size_t col = 0;
    size_t row = 0;
    for(size_t i = 0; i < rows; i++){
        if(i != n){
         for(size_t j = 0; j < cols; j++){
            if(j != m){
                result[row][col] = matrix[i][j];
                col++;  
            };
                
        }
        col = 0;
        row++;           
        }
    }
    return result;
}

double determinant(const Matrix& matrix)
{
    size_t rows = matrix.size();
    if(rows == 0){
        return 1.0;
    }

    size_t cols = matrix[0].size();
    if(rows != cols){
        throw std::logic_error("rows != cols");
    }
    if(rows == 1)
    {
        return matrix[0][0];
    }
    
    vector<Matrix> minor_mat(rows);

    for(int i = 0; i < rows; i++){
        Matrix mat = algebra::minor(matrix,0,i);
        minor_mat[i] = mat;
    }

    Matrix result = algebra::multiply(minor_mat[0],matrix[0][0]);
    for(int j = 1; j < rows; j++){
        result = algebra::sum(result,algebra::multiply(minor_mat[j],matrix[0][j]));
    };
    determinant(result);

}

}