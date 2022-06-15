#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//实现功能：可实现含小数、负数的求平均数，求方差，求众数，求中位数操作
/*
    平均数 mean
    方差 variance
    众数 mode
    中位数 median
*/
double mean = 0;
double meansqrt = 0;
int main(){
    vector<double> nums;
    string allNum;
    getline(cin,allNum);
    double a = 0;
    double rank = 0.1;
    short nagative = 1;
    bool isHas = false;
    for(int i =0;i<=allNum.length();i++){
        if(i<allNum.length()){
            if(allNum[i]=='-'){
                nagative = -1;
                continue;
            }
            if(allNum[i]=='.'){
                isHas = true;
                continue;
            }
            bool isDigital = allNum[i]>='0' && allNum[i]<='9';
            if(isDigital&&(!isHas)){
                a = a*10 + allNum[i]-'0';
                continue;
            }else if(isDigital&&(isHas)){
                a = a + (allNum[i]-'0')*rank;
                rank = rank*0.1;
                continue;
            }
            if(allNum[i]!=' '){
                cout << "error"<<endl;
                break;
            }
        }
        a = a*nagative;
        nums.push_back(a);
        mean += a;
        meansqrt += a*a;
        a = 0;
        rank = 0.1;
        nagative = 1;
        isHas = false;
    }
    mean = mean/(nums.size()*1.0);
    double variance = meansqrt/(nums.size()*1.0) - mean*mean;
    cout << "Mean number is " << mean << endl;
    cout << "Variance is " << variance << endl;
    sort(nums.begin(),nums.end());
    double median;
    if(nums.size()&1){
        median = nums[nums.size()/2];
    }else{
        median = (nums[nums.size()/2]+nums[nums.size()/2-1])/2;
    }
    cout << "Median is " << median << endl;
    vector<double> mode;
    int numTime = 1;
    int maxTime = 0;
    for(int i =1;i<nums.size();i++){
        if(nums[i]!=nums[i-1]){
            if(numTime>maxTime){
                maxTime = numTime;
                mode.clear();
                mode.push_back(nums[i-1]);
            }else if (numTime == maxTime){
                mode.push_back(nums[i-1]);
            }
            numTime = 1;
        }else{
            numTime++;
        }
    }
    if(numTime>maxTime){
        maxTime = numTime;
        mode.clear();
        mode.push_back(nums[nums.size()-1]);
    }else if (numTime == maxTime){
        mode.push_back(nums[nums.size()-1]);
    }
    cout << "Mode is ";
    for(int  i =0;i<mode.size();i++){
        cout << mode[i] << ' ';
    }
    cout << endl;
    system("pause");
    return 0;
}