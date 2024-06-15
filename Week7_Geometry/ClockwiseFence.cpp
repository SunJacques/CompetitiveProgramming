#include <iostream>
#include <string>
#include <complex>

using namespace std;

complex<double> updatePoint(complex<double> p, char S){
    if (S == 'E'){
        p.imag(p.imag() + 1);
    }else if(S == 'W'){
        p.imag(p.imag() - 1);
    }else if(S == 'N'){
        p.real(p.real() + 1);
    }else if(S == 'S'){
        p.real(p.real() - 1);
    }
    
    return p;
}

int main(){
    int N;
    string s;
    cin >> N;


    for (int i = 0; i < N; i++){
        complex<double> p0(0,0);
        complex<double> p1,p2;
        double rotation;
        int totalRotation = 0;

        cin >> s;

        p1 = updatePoint(p0,s[0]);
        p2 = p1;
        

        for (int j = 1; j < s.size(); j++){
            p2 = updatePoint(p2,s[j]);

            rotation = (conj(p2 - p1) * (p0 - p1)).imag();

            if (abs(rotation) > 0.1){
                if (rotation > 0){
                    totalRotation--;
                }else if (rotation < 0)
                {
                    totalRotation++;
                }
            }

            if (p2.real() == 0 && p2.imag() == 0){
                if (totalRotation < 0){
                    cout << "CW" << endl;
                }else{
                    cout << "CCW" << endl;
                }
            }
            
            p0 = p1;
            p1 = p2;
        }


    }

    return 0;
}