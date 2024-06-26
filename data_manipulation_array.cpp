#include<iomanip>
#include<iostream>
using namespace std;
void input(int A[5][6],int n){   // Number of students and their marks in 5 subjects
    for(int i=0;i<n;i++){
        cout<<i+1<<'\t';
        for(int j=0;j<5;j++){
            cout<<"Enter details:";
            cin>>A[i][j];
        }
        A[i][5]=0;
    }
    
}
void Result_summary(int A[5][6],int n){
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<5;j++){
            sum+=A[i][j];  //sum of marks of each row
        }
        A[i][5]=sum/5; //assigned to "percentage col"
    }
}
int topper(int A[5][6],int n){     // Highest percentage scored 
    int lgt=A[0][5];
    for(int i=0;i<n;i++){
        if(A[i][5]>lgt){
            lgt=A[i][5];
        }
    }
    return lgt;
}
void avg_marks(int A[5][6],int n){   // Average marks in each subject
    int avg;
    
    for(int j=0;j<6;j++){
        int sum=0;
        for(int i=0;i<n;i++){
        
            sum+=A[i][j];
        }
        avg=sum/n;
        cout<<'\t'<<avg;
    }  
}
void display(int A[5][6],int n){    // Display of the database created
    cout<<"YOUR DATA BASE:"<<endl;
    cout<<"RN."<<'\t'<<"Eng"<<'\t'<<"CS"<<'\t'<<"Maths"<<'\t'<<"Phy"<<'\t'<<"Chem"<<'\t'<<"Percentage"<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<'\t';
        for(int j=0;j<6;j++)
        {
            cout<<A[i][j]<<'\t';
        }
    cout<<endl;
    }
    cout<<"Avg:";
    avg_marks(A,n);cout<<endl;
    cout<<"Highest percentage scored is : "<<topper(A,n)<<endl;
}
int main(){
    int n;cout<<"Enter number of students:"<<endl;cin>>n;
    int A[5][6];
    input(A,n);
    Result_summary(A,n);
    display(A,n);
}