#include <iostream>  // Cho cout, endl
#include <vector>    // Cho vector
#include <cmath>     // Cho abs, exp
#include <cstdlib>   // Cho rand, srand, RAND_MAX
#include <ctime>     // Cho time

using namespace std;

// Hàm m?c tiêu: f(x) = x^2
double hamMucTieu(double x) {
    return x * x;
}

double tinhKhoangCach(double x1, double x2) {
    return abs(x1 - x2);}

double capNhatViTri(double viTri_i, double viTri_j, double beta, double gamma, double alpha) {
    double khoangCach = tinhKhoangCach(viTri_i, viTri_j);
    double doHapDan = beta * exp(-gamma * khoangCach * khoangCach);
    double thanhPhanNgauNhien = alpha * ((double)rand() / RAND_MAX - 0.5);
    return viTri_i + doHapDan * (viTri_j - viTri_i) + thanhPhanNgauNhien;
}
int main() {
    srand(time(0)); 
    const int soLuongDomDom = 5;  
    const int MaxGeneration = 20; 
    const double beta = 0.8;        
    const double gamma = 1.0;       
    const double alpha = 0.1;       
    const double gioiHanDuoi = -5;  
    const double gioiHanTren = 5;   
   
    vector<double> viTriDomDom(soLuongDomDom);
    for (int i = 0; i < soLuongDomDom; i++) {
        viTriDomDom[i] = gioiHanDuoi + (gioiHanTren - gioiHanDuoi) * ((double)rand() / RAND_MAX);}
    int t = 0; 
    while (t < MaxGeneration) {
        for (int i = 0; i < soLuongDomDom; i++) {
            for (int j = 0; j < soLuongDomDom; j++) {
                if (hamMucTieu(viTriDomDom[j]) < hamMucTieu(viTriDomDom[i])) {
                   
                    viTriDomDom[i] = capNhatViTri(viTriDomDom[i], viTriDomDom[j], beta, gamma, alpha);
                    
                    if (viTriDomDom[i] < gioiHanDuoi) viTriDomDom[i] = gioiHanDuoi;
                    if (viTriDomDom[i] > gioiHanTren) viTriDomDom[i] = gioiHanTren;
                }
            }
        }
       
        t++;
    }
    
    double viTriTotNhat = viTriDomDom[0];
    for (int i = 1; i < soLuongDomDom; i++) {
        if (hamMucTieu(viTriDomDom[i]) < hamMucTieu(viTriTotNhat)) {
            viTriTotNhat = viTriDomDom[i];
        }
    }
  
    cout << "Vi tri toi uu: " << viTriTotNhat << endl;
    cout << "Gia tri toi uu: " << hamMucTieu(viTriTotNhat) << endl;
    return 0;}

