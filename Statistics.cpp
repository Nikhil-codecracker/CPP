#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

double CalculateMean(vector<int> arr){
    double sum = 0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
    }
    return sum/arr.size();
}

double CalculateStd(vector<int> arr){
    double sum = 0;
    double mean = CalculateMean(arr);
    for(int i=0;i<arr.size();i++){
        sum += ((arr[i] - mean)*(arr[i] - mean));
    }
    return sqrt(sum/(arr.size()-1));
}

double CalculateMedian(vector<int> arr){
    sort(arr.begin(),arr.end());
    if(arr.size()%2==0){
        int n1 = arr.size()/2;
        int n2 = n1-1;
        return (arr[n1]+arr[n2])/2;
    }
    else{
        return arr[arr.size()/2];
    }
}

double CalculateMode(vector<int> arr){
    unordered_map<int,int> mp;
    for(int i=0;i<arr.size();i++){
        mp[arr[i]]++;
    }
    int max_val = 0, freq = 0;
    for(auto it : mp){
        if(freq < it.second){
            freq = it.second;
            max_val = it.first;
        }
    }
    return max_val;
}

int main(int argc, char const *argv[]) {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"MEAN is: "<<CalculateMean(arr)<<endl;
    cout<<"MEDIAN is: "<<CalculateMedian(arr)<<endl;
    cout<<"MODE is: "<<CalculateMode(arr)<<endl;
    cout<<"Standard Deviation is: "<<CalculateStd(arr)<<endl;
    return 0;
}
