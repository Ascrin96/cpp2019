#include <iostream>
#include <stdexcept>

class Matrix{
public:
  Matrix():d_rows(0),d_cols(0){
    d_data = nullptr;
  }
  Matrix(int num_rows, int num_cols)
  {
    if(num_rows < 1  || num_cols < 1){
      throw std::out_of_range("Error! The rows or cols can't be negative!");
    }
    d_rows = num_rows;
    d_cols = num_cols;
    d_data = new int[d_rows*d_cols]{};
  }

  int At(int i_row, int i_col) const
  {
    if(i_row*i_col > d_rows*d_cols)
      throw std::out_of_range("Error! number of cols or rows is out of range of matrix");
    return d_data[i_row*i_col];
  }

  int& At(int i_row, int i_col)
  {
    if(i_row*i_col > d_rows*d_cols)
      throw std::out_of_range("Error! number of cols or rows is out of range of matrix");
    return d_data[i_row*i_col];
  }

  friend std::ostream& operator<<(std::ostream& out, const Matrix& m) {
    // for (int i=0; i < m.rows; ++i) {
    //     for (int j=0; j < m.cols; ++j) {
    //         os << m.Mat[i][j] << "  " ;
    //     }
    //     os << '\n';
    // }
    for(int i = 0; i < m.d_rows * m.d_cols; i++){
      out << m.d_data[i];
      if((i != 0) && (i % m.d_cols == 0)){
        out << "\n";
      }
      else{
        out << " ";
      }
    }
    return out;
  }




private:
  int d_cols;
  int d_rows;
  int* d_data;
};

int main() {
  using namespace std;
  Matrix one;
  Matrix two;

  // cin >> one >> two;
  // cout << one + two << endl;
  return 0;
}