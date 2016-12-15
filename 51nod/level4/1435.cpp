#include<iostream>
#include<vector>
#include<string>
using namespace std;
int digit[10];

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++) 
        digit[str[i]-'0']++;
    for(int i=2;i<10;i++){
        for(int j=i+1;j<10;j++){
            digit[i]+=digit[j];
        }
    }
    for(int i=9;i>=2;i--){
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                digit[j]+=digit[i];
                digit[i/j]+=digit[i];
                break;
            }
        }
    }
    vector<int>num;
    for(int i=0;i<digit[7];i++){
        digit[2]-=4; digit[3]-=2; digit[5]--;
        num.push_back(7);
    }
    for(int i=0;i<digit[5];i++){
        digit[2]-=3; digit[3]--;
        num.push_back(5);
    }
    for(int i=0;i<digit[3];i++){
        digit[2]--;
        num.push_back(3);
    }
    for(int i=0;i<digit[2];i++){
        num.push_back(2);
    }
    for(int i=0;i<int(num.size());i++){
        cout<<num[i];
    }
    cout<<endl;
    return 0;
}