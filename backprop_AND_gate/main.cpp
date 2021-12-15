using namespace std;
#include <iostream>
#include <cmath>

void printActualResults(int allInputs, double x[3], double w[3], double z[3], double sum, double sigm, double loss, double dW[3], int target){
    cout<<"inputs number = "<<allInputs<<endl;
    cout<<"x : \t"<<x[0]<<"\t"<<x[1]<<"\t"<<x[2]<<endl;
    cout<<"w : \t"<<w[0]<<"\t"<<w[1]<<"\t"<<w[2]<<endl;
    cout<<"z : \t"<<z[0]<<"\t"<<z[1]<<"\t"<<z[2]<<endl;
    cout<<"target: "<<target<<endl;
    cout<<"sum :\t"<<sum<<endl;
    cout<<"sigm :\t"<<sigm<<endl;
    cout<<"loss :\t"<<loss<<endl;
    cout<<endl;
    cout<<"dW : \t"<<dW[0]<<"\t"<<dW[1]<<"\t"<<dW[2]<<endl;
    cout<<endl;
    cout<<endl;
}

int main() {
    bool fastSigm=false;

    int inputs=2;
    double x[4][3]={{1,0,0},{1,0,1},{1,1,0},{1,1,1}};
    double w[]={1,1,1};
    double z[]={0,0,0};

    int t[]={0,0,0,1};

    double sum;
    double sigm;
    double loss;

    double deltaWeight[]={0,0,0};

    int actual_it=0;
    int input_decimal=actual_it%4;
    int iteration = 1000;

    //dW_j = -(sigm-target)*sigm*(1-sigm)*z_j

    for (int i = 0; i < iteration; ++i) {

        actual_it=i;
        input_decimal=actual_it%4;

        for (int j = 0; j < inputs+1; ++j) {
            //calc weighted inputs
            z[j]=x[input_decimal][j]*w[j];
        }
        //sum wighted inputs
        sum=z[0]+z[1]+z[2];

        //activation
        if(fastSigm){
            sigm= 0.5 * (sum / (1 + abs(sum)) + 1);
        }
        else{
            sigm= 1/(1+exp(-(sum)));
        }

        //loss function (it must be smaller after every iteration)
        loss=0.5*pow(sigm-t[input_decimal],2);

        //the dW which with we modify the Weights
        for (int j = 0; j < inputs+1; ++j) {
            //deltaWeight[j]=-(sigm-t[input_decimal])*sigm*(1-sigm)*z[j];
            deltaWeight[j]=-(sigm-t[input_decimal])*sigm*(1-sigm)*x[input_decimal][j];
        }

        for (int j = 0; j < inputs+1; ++j) {
            w[j]=w[j]+deltaWeight[j];
        }

        printActualResults(inputs+2,x[input_decimal],w,z,sum,sigm,loss,deltaWeight, t[input_decimal]);



    }

    std::cout << "FINISHED" << std::endl;
    return 0;
}
